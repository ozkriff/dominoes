// See LICENSE file for copyright and license details.

#ifndef MOVEPASS_H_
#define MOVEPASS_H_

#include "move.h"

class MovePass : public Move {
private:
public:
  MovePass()
    : Move(MOVE_PASS)
  {}
  virtual ~MovePass() {}
};

#endif /* MOVEPASS_H_ */
