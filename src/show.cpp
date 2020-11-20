#include "alphabet.h"

void alphabet::ShowInLine()
{
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << "  ";
    }
    std::cout << std::endl;
}

void alphabet::ShowInColumn()
{
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << "\n";
    }
    std::cout << std::endl;
}