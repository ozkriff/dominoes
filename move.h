// See LICENSE file for copyright and license details.

#ifndef MOVE_H_
#define MOVE_H_

#include <list>

class Move {
public:
  enum MoveType {
    MOVE_PASS,
    MOVE_GET_MORE,
    MOVE_PUT_TO_SNAKE
  };
private:
  MoveType type;
public:
  int player_id;
  Move(MoveType type);
  virtual ~Move();
  MoveType get_type();
};

typedef std::list<Move*> MovesList;

#endif /* MOVE_H_ */
