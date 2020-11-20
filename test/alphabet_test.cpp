#define CATCH_CONFIG_MAIN
#include "alphabet.h"
#include "catch.hpp"

TEST_CASE("File_Is_Open", "[ReadFile]")
{
    alphabet testingClass;
    std::string path = "../test/text/any_text.txt";
    int expected = 1;
    int result = testingClass.ReadFromFile(path);
    REQUIRE(expected == result);
}

TEST_CASE("File_Not_Open", "[ReadFile]")
{
    alphabet testingClass;
    std::string path = "../test/text/non-existent.txt";
    int expected = 0;
    int result = testingClass.ReadFromFile(path);
    REQUIRE(expected == result);
}