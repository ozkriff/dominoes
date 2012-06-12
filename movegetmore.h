// See LICENSE file for copyright and license details.

#ifndef MOVEGETMORE_H_
#define MOVEGETMORE_H_

class MoveGetMore : public Move {
private:
   BricksList bricks;
   Brick *putbrick;
public:
   MoveGetMore()
      : Move(MOVE_GET_MORE)
   {}
   virtual ~MoveGetMore() {}
};

#endif /* MOVEGETMORE_H_ */
