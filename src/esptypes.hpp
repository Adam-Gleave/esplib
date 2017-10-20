/*
 * libesp
 * Copyright 2017 Adam Gleave
 *
 * This file is part of libesp.
 * libesp is free software, under the terms of the GPLv3 license.
 * See the LICENSE file for more details.
 *
 */

#ifndef ESPTYPES_H
#define ESPTYPES_H

#include <string>
#include <stdint.h>
#include <cstddef>

namespace ESP {

struct EspChar;
struct EspWChar;
struct EspByte;
struct EspUByte;
struct EspShort;
struct EspUShort;
struct EspLong;
struct EspULong;
struct EspLongLong;
struct EspULongLong;
struct EspFloat;
struct EspDouble;
struct EspFormID;

class TypeVisitor {
public:
    virtual void visit(EspChar&) = 0;
    virtual void visit(EspWChar&) = 0;
    virtual void visit(EspByte&) = 0;
    virtual void visit(EspUByte&) = 0;
    virtual void visit(EspShort&) = 0;
    virtual void visit(EspUShort&) = 0;
    virtual void visit(EspLong&) = 0;
    virtual void visit(EspULong&) = 0;
    virtual void visit(EspLongLong&) = 0;
    virtual void visit(EspULongLong&) = 0;
    virtual void visit(EspFloat&) = 0;
    virtual void visit(EspDouble&) = 0;
    virtual void visit(EspFormID&) = 0;
};

struct AbstractEspType {
    virtual void accept(TypeVisitor& v) = 0;
};

template <typename T>
struct EspBasicType : AbstractEspType {
    EspBasicType() {}
    EspBasicType(char** buffer) {
        data = (T*)*buffer;
        *buffer += getSize();
    }
    EspBasicType(char** buffer, std::size_t in_size) {
        arraySize = in_size;
        data = (T*)&buffer;
        *buffer += getSize();
    }

    T* data;
    std::size_t arraySize = 1;

    T get() {
        return *data;
    }
    std::size_t getSize() {
        return sizeof(T) * arraySize;
    }
    bool isArray() {
        return arraySize < 1;
    }

    virtual void accept() = 0;
};

// 8-bit character
struct EspChar : EspBasicType<char> {
    EspChar(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 16-bit character
struct EspWChar : EspBasicType<char16_t> {
    EspWChar(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 8-bit integer
struct EspByte : EspBasicType<int8_t> {
    EspByte(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// Unsigned 8-bit integer
struct EspUByte : EspBasicType<uint8_t> {
    EspUByte(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 16-bit integer
struct EspShort : EspBasicType<int16_t> {
    EspShort(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// Unsigned 16-bit integer
struct EspUShort : EspBasicType<uint16_t> {
    EspUShort(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 32-bit integer
struct EspLong : EspBasicType<int32_t> {
    EspLong(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// Unsigned 32-bit integer
struct EspULong : EspBasicType<uint32_t> {
    EspULong(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 64-bit integer
struct EspLongLong : EspBasicType<int64_t> {
    EspLongLong(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// Unsigned 64-bit integer
struct EspULongLong : EspBasicType<uint64_t> {
    EspULongLong(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 32-bit floating point number
struct EspFloat : EspBasicType<float> {
    EspFloat(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// 64-bit floating point number
struct EspDouble : EspBasicType<double> {
    EspDouble(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

// Unsigned 32-bit integer
// Used to refer to another form in the heirarchy
struct EspFormID : EspBasicType<uint32_t> {
    EspFormID(char** buffer) : EspBasicType(buffer) {}
    void accept(TypeVisitor& v) override {
        v.visit(*this);
    }
};

class IntegerVisitor : public TypeVisitor {
public:
    int64_t value;

    void visit(EspChar& c) override {
        value = c.get();
    }
    void visit(EspWChar& wc) override {
        value = wc.get();
    }
    void visit(EspByte& b) override {
        value = b.get();
    }
    void visit(EspUByte& ub) override {
        value = ub.get();
    }
    void visit(EspShort& s) override {
        value = s.get();
    }
    void visit(EspUShort& us) override {
        value = us.get();
    }
    void visit(EspLong& l) override {
        value = l.get();
    }
    void visit(EspULong& ul) override {
        value = ul.get();
    }
    void visit(EspLongLong& ll) override {
        value = ll.get();
    }
    void visit(EspULongLong& ull) override {
        value = ull.get();
    }
    void visit(EspFloat&) override {
        throw std::runtime_error("Not an integer.");
    }
    void visit(EspDouble&) override {
        throw std::runtime_error("Not an integer.");
    }
    void visit(EspFormID& id) override {
        value = id.get();
    }
};

}

#endif // ESPTYPES_H
