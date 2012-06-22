// See LICENSE file for copyright and license details.

#include "tile.h"
#include <cstdio>

void Tile::print_no_rot(int a, int b) {
   // const char *s = "%i-%i";
   // const char *s = "[%i:%i]";
   const char *s = "(%i|%i)";
   printf(s, a, b);
}

Tile::Tile(int left, int right, bool is_rotated)
   : is_rotated(is_rotated),
      left(left),
      right(right)
{
}

void Tile::print() {
   if (is_rotated) {
      print_no_rot(left, right);
   } else {
      print_no_rot(right, left);
   }
}

bool Tile::can_connect(const Tile *tile) {
   return left == tile->left
         || left == tile->right
         || right == tile->left
         || right == tile->right;
}

void print_tiles_list(const TilesList *list) {
   for (TilesList::const_iterator tile = list->begin();
         tile != list->end(); ++tile)
   {
      (*tile)->print();
      putchar(' ');
   }
   putchar('\n');
}
