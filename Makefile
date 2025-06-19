TARGET = main

CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp LinkedList.cpp
OBJS = $(SRCS:.cpp=.o)

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

clear:
	rm -f $(OBJS) $(TARGET) *.txt

make_all: clear all

.PHONY: all clean clear make_all
