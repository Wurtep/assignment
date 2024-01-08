CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

OBJS = assignment.o main.o

EXEC = assignment

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

assignment.o: assignment.cpp assignment.hpp INode.hpp
	$(CXX) $(CXXFLAGS) -c assignment.cpp

main.o: main.cpp assignment.hpp node.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f $(OBJS) $(EXEC)