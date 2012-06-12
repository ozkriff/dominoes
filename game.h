// See LICENSE file for copyright and license details.

#ifndef GAME_H_
#define GAME_H_

#include "snake.h"
#include "player.h"
#include "move.h"
#include "brick.h"

class Game {
public:
  Snake *snake;
private:
  PlayersList *players;
  MovesList *moves;
  BricksList *all_bricks;
private:
  void generate_bricks();
  int get_players_count();
  void get_players();
public:
  Game();
  ~Game();
  int run();
};

#endif /* GAME_H_ */
