CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = els

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f src/*.o $(TARGET)
