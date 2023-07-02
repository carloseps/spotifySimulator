CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -I./include -I./include/rest -I./lib
LDFLAGS = -L./lib -lcurl

SRC_DIR = src
BIN_DIR = bin

EXECUTABLE = $(BIN_DIR)/main

.PHONY: all clean

all: $(EXECUTABLE)
		@$(EXECUTABLE)
		@$(MAKE) clean

$(EXECUTABLE): $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f $(EXECUTABLE)