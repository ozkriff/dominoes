// See LICENSE file for copyright and license details.

#ifndef MOVEPUT_H_
#define MOVEPUT_H_

class MovePut : public Move {
private:
public:
   MovePut()
      : Move(MOVE_PUT_TO_SNAKE)
   {}
   virtual ~MovePut() {}
};

#endif /* MOVEPUT_H_ */
