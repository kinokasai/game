CC=clang++
CXX=clang++
SRC= src/main.cc src/entity/id.cc src/screen/run.cc src/graphics/shader.cc \
	 src/graphics/render.cc \
	 src/gameplay/area.cc src/scene/state.cc src/gameplay/controller.cc \
	 src/gameplay/pevents.cc src/helpers/vectwo.cc src/physics/physics.cc \
	 src/debug/logger.cc \
	 src/helpers/clock.cc src/entity/player.cc src/graphics/color.cc \
	 src/map/level.cc src/entity/factory.cc \
	 src/map/camera.cc src/helpers/helpers.cc src/entity/chest.cc \
	 src/physics/speed.cc src/entity/enemy.cc src/graphics/palette.cc \
	 src/entity/wall.cc src/physics/bump.cc

CXXFLAGS=-pedantic -g -Wall -Wextra -std=c++14 -DDEBUG \
		 -Isrc/struct \
		 -Isrc/helpers -Isrc/debug -Isrc/entity -Isrc/gameplay -Isrc/scene \
		 -Isrc/map -Isrc/graphics -Isrc/physics -Isrc/screen


LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lm -lGLEW \
-lGL

MSRC=src/main.cc
OBJ=$(SRC:.cc=.o)
all: thief

thief: $(OBJ)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(OBJ) -o $@

check: $(SRC) $(TSRC)
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) thief $(OBJ) src/*.gch src/*.o
