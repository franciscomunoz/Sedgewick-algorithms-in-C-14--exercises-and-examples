# compiler
CXX = clang++
# flags
CXXFLAGS = -Wall -std=c++14
# general dependencies
DEPS = list.h listnode.h
# object files
OBJ = main.o
# main file name
TARGET = ex_3.33
# out file name
OUT = ex_3.33

all : $(TARGET)

debug : CXXFLAGS += -DDEBUG -g
debug : all


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

$(OBJ): $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.dSYM) $(wildcard *.o) $(wildcard *~) $(OUT)
