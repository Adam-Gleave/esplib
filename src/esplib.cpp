#include "esplib.hpp"

namespace ESP {

void readFile() {
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

}
