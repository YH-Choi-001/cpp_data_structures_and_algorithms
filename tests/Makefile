# Compiler
CXX := g++

# C++ standard
CXXSTD := c++11

# Compiler flags
CXXFLAGS := -Wall -g -std=$(CXXSTD)

# Target C++ file
TARGETCPP := $(shell find ./ -type f -name "test*.cpp")

# Target
TARGET := $(TARGETCPP:.cpp=.out)

# Header files
HEADERS := $(shell find ../src -type f -name "*.h")

# Source files
SRCS := $(TARGETCPP)

# Object files
OBJS := $(SRCS:.cpp=.o)

# Default rule to build and run the executable
all: update_tests build run

# Rule to compile .cpp files into .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.out: %.o
	$(CXX) $(CXXFLAGS) -o $@ $<

# Rule to compile all source .cpp files
compile: $(OBJS)

# Rule to build the executable
build: $(TARGET)

# Rule to run the executable
run: $(TARGET)
	find ./ -type f -name "test*.out" -exec "{}" \; | grep -E "(All passed|failed)"

# Update the testcases in the testfile
update_tests:
	find ./ -type f -name "*.cpp" -exec ./update_testcase.sh "{}" \;

# Clean rule to remove generated files
clean:
	rm $(TARGET) $(OBJS) || true
