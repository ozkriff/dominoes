// See LICENSE file for copyright and license details.

#ifndef NEXTTILECHOOSER_H_
#define NEXTTILECHOOSER_H_

class Game;
class Player;
class Move;

class NextTileChooser {
protected:
   Player *player;
public:
   NextTileChooser();
   virtual ~NextTileChooser();
   virtual Move* do_move() = 0;
   void set_player(Player *player);
};

#endif /* NEXTTILECHOOSER_H_ */
