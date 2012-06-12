// See LICENSE file for copyright and license details.

#ifndef HUMANCHOOSER_H_
#define HUMANCHOOSER_H_

#include "nextbrickchooser.h"
#include "brick.h"

class HumanChooser : public NextBrickChooser {
private:
  void put_snake();
  void print_indexed_list(const BricksList *list);
public:
  HumanChooser();
  virtual Move* do_move();
};

#endif /* HUMANCHOOSER_H_ */
