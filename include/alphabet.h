#ifndef ALPHABET_H
#define ALPHABET_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class alphabet {
private:
    std::vector<std::string> data;

public:
    ~alphabet();
    int ReadFromFile(std::string path);
};

#endif