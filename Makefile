CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude -Isrc/commands

SRC = src/main.cpp src/Shell.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = MiniShell

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)