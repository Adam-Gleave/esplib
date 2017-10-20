#include "esplib.hpp"

namespace ESP {

using json = nlohmann::json;

void readFile() {
    std::streampos size;
    std::ifstream file(TEST_LOC, std::ios::in | std::ios::binary | std::ios::ate);
    char* buffer;

    //Load contents of esp/esm into memory
    if (file.is_open())
    {
        file.seekg(0, file.end);
        size = file.tellg();
        file.seekg(0, file.beg);
        buffer = new char[size];
        file.read(buffer, size);
        file.close();

        std::cout << "Contents of file are in memory. " << std::endl
                  << size << " bytes loaded." << std::endl;
    }
    else
    {
        std::cout << "Cannot open ESP/ESM file!" << std::endl;
        return;
    }

    //Load contents of json file into memory
    json jdef = readJson();

    if (jdef == 0) {
        return;
    }

    MapBuilder builder;
    builder.build(jdef, buffer);
}

json readJson() {
    json j;
    std::ifstream file(JSON_LOC);

    if (file.is_open())
    {
        file >> j;
        std::cout << "JSON file found and loaded into memory." << std::endl;
        return j;
    }
    else
    {
        std::cout << "Cannot open JSON file!" << std::endl;
        return 0;
    }
}

std::string getType(char** bufferptr) {
    char arr[4];
    std::string str;

    for (int i = 0; i < 4; i++) {
        memcpy(&arr[i], *bufferptr, sizeof(uint8_t));
        *bufferptr += sizeof(uint8_t);
    }

    str = arr;
    return arr;
}

void MapBuilder::build(json jdef, char* buffer) {
    std::string typecode = getType(&buffer);;

    for (json::iterator it = jdef.begin(); it != jdef.end(); it++) {
        std::cout <<  *it << std::endl;
    }
}

}
