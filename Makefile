CC=clang++
CXX=clang++
SRC= src/main.cc src/id.cc src/run.cc src/shader.cc src/render.cc \
	 src/area.cc src/randomizer.cc src/state.cc src/controller.cc \
	 src/pevents.cc src/vectwo.cc src/physics.cc src/logger.cc \
	 src/clock.cc src/player.cc src/color.cc src/level.cc src/factory.cc \
	 src/camera.cc src/helpers.cc src/chest.cc

CXXFLAGS=-pedantic -g -Wall -Wextra -std=c++14 -DDEBUG

LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lm -lGLEW \
-lGL

MSRC=src/main.cc
TSRC=tests/main.cc
OBJ=$(SRC:.cc=.o)
all: thief

thief: $(OBJ)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(OBJ) -o $@

check: $(SRC) $(TSRC)
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) thief $(OBJ) src/*.gch src/*.o
