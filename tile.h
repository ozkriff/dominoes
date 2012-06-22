// See LICENSE file for copyright and license details.

#ifndef TILE_H_
#define TILE_H_

#include <list>

class Tile {
private:
   void print_no_rot(int a, int b);
public:
   bool is_rotated;
   int left;
   int right;
public:
   Tile(int left, int right, bool is_rotated = false);
   void print();
   bool can_connect(const Tile *tile);
};

typedef std::list<Tile*> TilesList;

void print_tiles_list(const TilesList *list);

#endif /* TILE_H_ */
