// See LICENSE file for copyright and license details.

#include "move.h"

Move::Move(MoveType type)
   : type(type)
{
}

Move::~Move() {
}

Move::MoveType Move::get_type() {
   return type;
}
