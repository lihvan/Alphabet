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

TEST_CASE("Binary_Search_Empty", "[BinarySearch]")
{
    alphabet testingClass;
    std::string path = "../test/text/first_position_check_text.txt";
    int expectedIndex = 1;
    std::string expectedWord = "Word";
    int resultIndex = testingClass.ReadFromFile(path);
    std::string resultWord = testingClass[0];
    REQUIRE(expectedIndex == resultIndex);
    REQUIRE(expectedWord == resultWord);
}

TEST_CASE("Binary_Search_Sort", "[BinarySearch]")
{
    alphabet testingClass;
    std::string path = "../test/text/sequence_of_test.txt";
    int expectedIndex = 1;
    std::vector<std::string> expectedSequence{
            "apple", "august", "door", "made", "pen", "run", "zero"};
    int resultIndex = testingClass.ReadFromFile(path);
    REQUIRE(expectedIndex == resultIndex);
    for (size_t i = 0; i < expectedSequence.size(); i++) {
        REQUIRE(expectedSequence[i] == testingClass[i]);
    }
}