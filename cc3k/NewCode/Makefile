CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD

SRC_DIR = .
BIN_DIR = .

SOURCES = $(wildcard $(SRC_DIR)/*.cc)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, %.o, $(SOURCES))
EXEC = $(BIN_DIR)/cc3k

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXEC)

.PHONY: all clean
