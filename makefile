CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -I./include/model -I./include/rest -I./include/controller -I./lib
LDFLAGS = -L./lib -lcurl -lodb -lodb-sqlite

SRC_DIR = src
BIN_DIR = bin

EXECUTABLE = $(BIN_DIR)/main

.PHONY: all clean

all: $(EXECUTABLE)
		@$(EXECUTABLE)
		@$(MAKE) clean

$(EXECUTABLE): $(wildcard $(SRC_DIR)/*.cpp)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

clean:
	rm -f $(EXECUTABLE)