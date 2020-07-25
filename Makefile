targets = main

cppComp = $(CROSS_TOOL)g++

flags = -Wall -Werror -std=c++11

all: clean $(targets)

$(targets):
	$(cppComp) $(flags) $@.cpp -o $(targets)

clean:
	rm -f $(targets)
format:
	clang-format --style=file -i *.cpp *.hpp
