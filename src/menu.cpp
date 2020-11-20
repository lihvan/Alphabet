#include "menu.h"
#include "alphabet.h"
#include <limits>
#define ESC "\033" // code for screen cleaning

void menu()
{
    int choose = -1;
    alphabet conteiner;
    while (true) {
        printf(ESC "c");
        std::cout << "1. Open file with text\n";
        std::cout << "2. Show text in line\n";
        std::cout << "3. Show text in a column\n";
        std::cout << "For exit write \"-1\"\n";
        std::cout << "Choose: ";
        std::cin >> choose;
        switch (choose) {
        case 1: {
            std::string path;
            printf(ESC "c");
            std::cout << "WARNING: *The path is written relative to the "
                         "location of the program*\n";
            std::cout << "Path: ";
            std::cin >> path;
            if (conteiner.ReadFromFile(path)) {
                std::cout << "Successfully!\n";
            } else {
                std::cout << "An error occurred while opening the file, "
                             "perhaps you specified the path incorrectly\n";
            }
            break;
        }
        case 2: {
            printf(ESC "c");
            std::cout << "Words:\n";
            conteiner.ShowInLine();
            break;
        }
        case 3: {
            printf(ESC "c");
            std::cout << "Words:\n";
            conteiner.ShowInColumn();
            break;
        }
        }
        std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'); // fix problem with getchar + \n skiping
        std::cout << "Press key to continue...\n";
        getchar();
        if (choose == -1) {
            break;
        }
    }
}