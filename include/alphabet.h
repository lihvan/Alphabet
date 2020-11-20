#ifndef ALPHABET_H
#define ALPHABET_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class alphabet {
private:
    std::vector<std::string> data;

public:
    ~alphabet();
    int ReadFromFile(std::string path);
    int QuickBinarySearch(std::string word);
    std::string operator[](int index);
};

#endif