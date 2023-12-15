# OBJECTS = $(SRC_FILES:.cpp=.o)
TARGET = descent_parser
SRCS = $(wildcard *.cpp) $(wildcard */*.cpp)
CC = g++
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
CFLAGS =  -std=c++20 -w
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
all: $(TARGET)
$(TARGET): $(OBJS)

	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@


run: $(TARGET)
	./$(TARGET)
# no make clean becauses i couldn't figure