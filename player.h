// See LICENSE file for copyright and license details.

#ifndef PLAYER_H_
#define PLAYER_H_

#include "tile.h"

class Move;
class Game;
class NextTileChooser;

class Player {
public:
   Game *game;
private:
   NextTileChooser *chooser;
   int score;
public:
   TilesList tiles;
public:
   Player(Game *game, NextTileChooser *chooser);
   ~Player();
   Move* do_move();
};

typedef std::list<Player*> PlayersList;

#endif /* PLAYER_H_ */
