#include "alphabet.h"

alphabet::~alphabet()
{
    data.clear();
}

int alphabet::ReadFromFile(std::string path)
{
    data.clear();
    std::ifstream file;
    file.open(path);
    if (file.is_open()) {
        return 1;
    }
    return 0;
}