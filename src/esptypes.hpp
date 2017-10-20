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

struct AbstractEspType {
    virtual void accept() = 0;
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
    void accept() override {
        //TODO
    }
};

// 16-bit character
struct EspWChar : EspBasicType<char16_t> {
    EspWChar(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// 8-bit integer
struct EspByte : EspBasicType<int8_t> {
    EspByte(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// Unsigned 8-bit integer
struct EspUByte : EspBasicType<uint8_t> {
    EspUByte(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// 16-bit integer
struct EspShort : EspBasicType<int16_t> {
    EspShort(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// Unsigned 16-bit integer
struct EspUShort : EspBasicType<uint16_t> {
    EspUShort(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// 32-bit integer
struct EspLong : EspBasicType<int32_t> {
    EspLong(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// Unsigned 32-bit integer
struct EspULong : EspBasicType<uint32_t> {
    EspULong(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// 64-bit integer
struct EspLongLong : EspBasicType<int64_t> {
    EspLongLong(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// Unsigned 64-bit integer
struct EspULongLong : EspBasicType<uint64_t> {
    EspULongLong(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// 32-bit floating point number
struct EspFloat : EspBasicType<float> {
    EspFloat(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// 64-bit floating point number
struct EspDouble : EspBasicType<double> {
    EspDouble(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

// Unsigned 32-bit integer
// Used to refer to another form in the heirarchy
struct EspFormID : EspBasicType<uint32_t> {
    EspFormID(char** buffer) : EspBasicType(buffer) {}
    void accept() override {
        //TODO
    }
};

}

#endif // ESPTYPES_H
