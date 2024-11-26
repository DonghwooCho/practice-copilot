# Makefile

CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = RockPaperScissors
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)