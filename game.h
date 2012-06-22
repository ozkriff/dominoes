// See LICENSE file for copyright and license details.

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "snake.h"
#include "player.h"
#include "move.h"
#include "tile.h"

class Game {
public:
   Snake *snake;
private:
   PlayersList *players;
   MovesList *moves;
   std::vector<Tile*> *deck;
private:
   void generate_tiles();
   int get_players_count();
   void get_players();
public:
   Game();
   ~Game();
   int run();
};

#endif /* GAME_H_ */
