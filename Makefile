.PHONY: all format clean run test

PROJECT_NAME = Alphabet
TEST_NAME = test_Alphabet
COMPILEFLAGS=-Wall -Werror
INCLUDE_DIR = -I include -I src
FLAGS = -std=c++11

all: bin/$(PROJECT_NAME) bin/$(TEST_NAME) format

bin/$(PROJECT_NAME): build/src/main.o build/src/alphabet.o build/src/menu.o build/src/show.o
			$(CXX) $(COMPILEFLAGS) $^ -o $@

build/src/%.o: src/%.cpp
			$(CXX) $(COMPILEFLAGS) $(INCLUDE_DIR) -c $< -o $@ $(FLAGS)

format: 
			clang-format -i src/*.cpp include/*.h test/*.cpp 

clean:
	rm -rf build/src/*.o bin/$(PROJECT_NAME) build/test/*.o bin/$(TEST_NAME)

run:
	cd bin/ && ./$(PROJECT_NAME)

#Unit test part

bin/$(TEST_NAME): build/test/alphabet_test.o build/src/alphabet.o
			$(CXX) $(COMPILEFLAGS) $^ -o $@

build/test/%.o: test/%.cpp
			$(CXX) $(COMPILEFLAGS) -I include -I thirdparty -c $< -o $@ $(FLAGS)

test:
	cd bin/ && ./$(TEST_NAME)