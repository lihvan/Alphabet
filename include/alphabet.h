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

    int QuickBinarySearch(std::string word);

public:
    ~alphabet();
    int ReadFromFile(std::string path);
    void ShowInLine();
    void ShowInColumn();

    std::string operator[](int index);
};

#endif