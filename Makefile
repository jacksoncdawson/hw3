CXX = g++
CXXFLAGS = -Werror -Wall -Wextra -Wconversion -Wdouble-promotion -pedantic -std=c++11
EXEC = wordrange
OBJS = wordrange.o AVLTree.o node.o
HEADERS = AVLTree.hpp node.hpp

$(EXEC): $(OBJS)
	$(CXX) -g $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean

all: wordrange

clean:
	rm -f *.o wordrange

