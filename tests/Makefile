# Builds and runs the unit-test suite for the NeetCode solutions.
#
#   make        # compile + run all tests
#   make build  # compile only
#   make clean  # remove build artifacts

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wno-unused-variable -Wno-sign-compare
BIN       = run_tests
SOURCES   = $(wildcard test_*.cpp) main.cpp

.PHONY: all build test clean

all: test

build: $(BIN)

$(BIN): $(SOURCES) harness.h
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(BIN)

test: $(BIN)
	./$(BIN)

clean:
	rm -f $(BIN)
