// See LICENSE file for copyright and license details.

#ifndef SNAKE_H_
#define SNAKE_H_

#include "tile.h"

class Snake {
public:
   TilesList tiles;
public:
   void add_tile_right(Tile *tile);
   void add_tile_left(Tile *tile);
   void add_first_tile(Tile *tile);
   void print();
   bool check_can_put(const Tile *b);
};

#endif /* SNAKE_H_ */
