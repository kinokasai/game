CC=clang++
CXX=clang++
SRC= src/main.cc src/id.cc src/run.cc src/shader.cc\

CXXFLAGS=-pedantic -g -Wall -Wextra -std=c++14 -lsfml-graphics		\
-lsfml-window -lsfml-audio -lsfml-system -lm -lGLEW -lGL

MSRC=src/main.cc
TSRC=tests/main.cc
OBJ=$(SRC:.cc=.o)
all: thief

thief: $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $@

check: $(SRC) $(TSRC)
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) thief $(OBJ)
