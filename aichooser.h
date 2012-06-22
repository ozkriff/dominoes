// See LICENSE file for copyright and license details.

#ifndef AICHOOSER_H_
#define AICHOOSER_H_

#include "nexttilechooser.h"

class AiChooser : public NextTileChooser {
public:
   AiChooser();
   virtual Move* do_move();
};

#endif /* AICHOOSER_H_ */
