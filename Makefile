all: dominoes
CXX=g++
#CXX=clang++
CXXFLAGS=-g -Wall -Wextra --pedantic
objects=aichooser.o brick.o game.o humanchooser.o misc.o \
        move.o nextbrickchooser.o player.o snake.o dominoes.o
dominoes: $(objects)
	g++ $(CXXFLAGS) $(objects) -o dominoes -lstdc++
aichooser.o: aichooser.h
brick.o: brick.h
game.o: game.h
humanchooser.o: humanchooser.h
misc.o: misc.h
move.o: move.h
nextbrickchooser.o: nextbrickchooser.h
player.o: player.h
snake.o: snake.h
dominoes.o:
clean:
	rm $(objects) dominoes -f
