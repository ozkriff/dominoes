// See LICENSE file for copyright and license details.

#ifndef NEXTBRICKCHOOSER_H_
#define NEXTBRICKCHOOSER_H_

class Game;
class Player;
class Move;

class NextBrickChooser {
protected:
  Player *player;
public:
  NextBrickChooser();
  virtual ~NextBrickChooser();
  virtual Move* do_move() = 0;
  void set_player(Player *player);
};

#endif /* NEXTBRICKCHOOSER_H_ */
