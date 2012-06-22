// See LICENSE file for copyright and license details.

#include "snake.h"

void Snake::add_tile_right(Tile *tile) {
   tiles.push_back(tile);
}

void Snake::add_tile_left(Tile *tile) {
   tiles.push_front(tile);
}

void Snake::add_first_tile(Tile *tile) {
   tiles.push_front(tile);
}

void Snake::print() {
   print_tiles_list(&tiles);
}

bool Snake::check_can_put(const Tile *b) {
   return tiles.front()->can_connect(b)
         || tiles.back()->can_connect(b);
}
