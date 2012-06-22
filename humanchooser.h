// See LICENSE file for copyright and license details.

#ifndef HUMANCHOOSER_H_
#define HUMANCHOOSER_H_

#include "nexttilechooser.h"
#include "tile.h"

class HumanChooser : public NextTileChooser {
private:
   void put_snake();
   void print_indexed_list(const TilesList *list);
public:
   HumanChooser();
   virtual Move* do_move();
};

#endif /* HUMANCHOOSER_H_ */
