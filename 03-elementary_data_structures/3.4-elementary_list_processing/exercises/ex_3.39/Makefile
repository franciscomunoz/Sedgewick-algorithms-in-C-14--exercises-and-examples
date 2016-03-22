# compiler
CXX = clang++
# flags
CXXFLAGS = -Wall -std=c++14 -fno-elide-constructors
# general dependencies
DEPS = list.h listnode.h
# object files
OBJ = main.o
# main file name
TARGET = app
# out file name
OUT = ex_3.39

all : $(TARGET)

debug : CXXFLAGS += -DDEBUG -g
debug : all


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(OBJ)

$(OBJ): $(DEPS)

.PHONY : clean
clean:
	rm -rf $(wildcard *.dSYM) $(wildcard *.o) $(wildcard *~) $(OUT)
