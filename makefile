# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Linker flags (update if you're using WSL, SFML installed via apt)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include

# Find all source files in src/
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# Replace src/*.cpp with build/*.o for object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Output binary
EXEC = game

# Default target
all: $(EXEC)

# Link object files into the final executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile each source file into an object file inside build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(EXEC)
