// See LICENSE file for copyright and license details.

#ifndef SNAKE_H_
#define SNAKE_H_

#include "brick.h"

class Snake {
public:
  BricksList bricks;
public:
  void add_brick_right(Brick *brick);
  void add_brick_left(Brick *brick);
  void add_first_brick(Brick *brick);
  void print();
  bool check_can_put(const Brick *b);
};

#endif /* SNAKE_H_ */
