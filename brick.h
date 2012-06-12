// See LICENSE file for copyright and license details.

#ifndef BROCK_H_
#define BROCK_H_

#include "list"

class Brick {
private:
  void print_no_rot(int a, int b);
public:
  bool is_rotated;
  int left;
  int right;
public:
  Brick(int left, int right, bool is_rotated = false);
  void print();
  bool can_connect(const Brick *brick);
};

typedef std::list<Brick*> BricksList;

void print_bricks_list(const BricksList *list);

#endif /* BROCK_H_ */
