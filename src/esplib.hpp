/*
 * libesp
 * Copyright 2017 Adam Gleave
 *
 * This file is part of libesp.
 * libesp is free software, under the terms of the GPLv3 license.
 * See the LICENSE file for more details.
 *
 */

#ifndef ESPLIB_H
#define ESPLIB_H

#include <iostream>
#include <fstream>
#include <map>

#include "json.hpp"
#include "esptypes.hpp"

namespace ESP {

static const char* TEST_LOC = "Skyrim.esm";
static const char* JSON_LOC = "tes4new.json";

void readFile();
nlohmann::json readJson();
std::string readType(char** bufferptr);

struct MapBuilder {
    std::map<std::string, AbstractEspType*> espMap;
    void build(nlohmann::json jdef, char* buffer);
};

}

#endif // ESPLIB_H
