targets = main

cppComp = $(CROSS_TOOL)g++

flags = -Wall -Werror -std=c++11

all: clean $(targets)

$(targets):
	$(cppComp) $(flags) $@.cpp -o $@

clean:
	rm -f $(targets)
