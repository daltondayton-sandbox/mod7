# Define compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -g -Wall -Wextra -Iinc

# Source directory
SRCDIR = src

# Include directory
INCDIR = inc

# Build target executable
TARGET = main

# Find cpp files in src directory
SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Object files
OBJS := $(SRCS:$(SRCDIR)/%.cpp=%.o)

# Default build
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

