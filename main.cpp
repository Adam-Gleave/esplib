/*
 * libesp
 * Copyright 2017 Adam Gleave
 *
 * This file is part of libesp.
 * libesp is free software, under the terms of the GPLv3 license.
 * See the LICENSE file for more details.
 *
 */

#include <iostream>
#include <fstream>

static const char* TEST_LOC = "Skyrim.esm";

int main()
{
    std::streampos size;
    std::ifstream file(TEST_LOC, std::ios::in | std::ios::binary);
    char* buffer;

    //Load contents of esp/esm into memory
    if (file.is_open())
    {
        file.seekg(0, file.end);
        size = file.tellg();
        buffer = new char[size];
        file.read(buffer, size);
        file.close();

        std::cout << "Contents of file are in memory. " << std::endl
                  << size << " bytes loaded." << std::endl;
    }
    else
    {
        std::cout << "Cannot open file!" << std::endl;
    }
}
