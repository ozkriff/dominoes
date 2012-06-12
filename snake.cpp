// See LICENSE file for copyright and license details.

#include "snake.h"

void Snake::add_brick_right(Brick *brick) {
   bricks.push_front(brick);
}

void Snake::add_brick_left(Brick *brick) {
   bricks.push_back(brick);
}

void Snake::add_first_brick(Brick *brick) {
   bricks.push_front(brick);
}

void Snake::print() {
   print_bricks_list(&bricks);
}

bool Snake::check_can_put(const Brick *b) {
   return bricks.front()->can_connect(b)
         || bricks.back()->can_connect(b);
}
