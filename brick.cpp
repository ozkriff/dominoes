// See LICENSE file for copyright and license details.

#include "brick.h"
#include <cstdio>

void Brick::print_no_rot(int a, int b) {
   // const char *s = "%i-%i";
   // const char *s = "[%i:%i]";
   const char *s = "(%i|%i)";
   printf(s, a, b);
}

Brick::Brick(int left, int right, bool is_rotated)
   : is_rotated(is_rotated),
      left(left),
      right(right)
{
}

void Brick::print() {
   if (is_rotated) {
      print_no_rot(left, right);
   } else {
      print_no_rot(right, left);
   }
}

bool Brick::can_connect(const Brick *brick) {
   return left == brick->left
         || left == brick->right
         || right == brick->left
         || right == brick->right;
}

void print_bricks_list(const BricksList *list) {
   for (BricksList::const_iterator it = list->begin();
         it != list->end(); ++it)
   {
      (*it)->print();
      putchar(' ');
   }
   putchar('\n');
}
