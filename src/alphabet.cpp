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
                    data.insert(data.begin() + QuickBinarySearch(word), word);
                }
            }
            return 1;
        }
    }
    return 0;
}

int alphabet::QuickBinarySearch(std::string word)
{
    int L = 0, R = data.size(), sero = 0;
    while (L < R) {
        sero = (L + R) / 2;
        if (data[sero] < word) {
            L = sero + 1;
        } else {
            R = sero;
        }
    }
    if (data.size() == 0) {
        return 0;
    } else {
        return R;
    }
}

std::string alphabet::operator[](int index)
{
    return data[index];
}