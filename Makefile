PROJECT_NAME = Alphabet
COMPILEFLAGS=-Wall -Werror

all: bin/$(PROJECT_NAME) format


bin/$(PROJECT_NAME): build/main.o
			$(CXX) $(COMPILEFLAGS) $^ -o $@

build/%.o: src/%.cpp
			$(CXX) $(COMPILEFLAGS) -I src -c $< -o $@

format: src/main.cpp
			clang-format -i src/*.cpp

clean:
	rm -rf build/*.o bin/$(PROJECT_NAME)

run:
	cd bin/ && ./$(PROJECT_NAME)