#include "alphabet.h"

alphabet::~alphabet()
{
    data.clear();
}

int alphabet::ReadFromFile(std::string path)
{
    data.clear();
    std::ifstream file;
    file.open(path, std::ios::in);
    if (file.is_open()) {
        if (file.good()) {
            std::string conteiner, word;
            while (getline(file, conteiner)) {
                std::istringstream ss(conteiner);
                while (ss >> word) {
                    data.push_back(word);
                }
            }
            return 1;
        }
    }
    return 0;
}