// See LICENSE file for copyright and license details.

#ifndef PLAYER_H_
#define PLAYER_H_

#include "brick.h"

class Move;
class Game;
class NextBrickChooser;

class Player {
public:
   Game *game;
private:
   NextBrickChooser *chooser;
   int score;
public:
   BricksList bricks;
public:
   Player(Game *game, NextBrickChooser *chooser);
   ~Player();
   Move* do_move();
};

typedef std::list<Player*> PlayersList;

#endif /* PLAYER_H_ */
