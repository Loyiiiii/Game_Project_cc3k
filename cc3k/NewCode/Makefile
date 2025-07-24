CXX = g++
CXXFLAGS = -std=c++20 -g -Wall -Werror=vla -MMD

# Directories
SRC_DIR = .
OBJ_DIR = ./AllObjects
BIN_DIR = .

# Find all .cc files in the source directory
SOURCES = $(wildcard $(SRC_DIR)/*.cc)

# Generate object file names from source file names
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SOURCES))

# The executable file name
EXEC = $(BIN_DIR)/cc3k

all: $(EXEC)

# Rule to link the executable
$(EXEC): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Phony targets
.PHONY: all clean 
