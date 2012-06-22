// See LICENSE file for copyright and license details.

#include "aichooser.h"
#include "game.h"
#include "movepass.h"

AiChooser::AiChooser()
   : NextTileChooser()
{
}

Move* AiChooser::do_move() {
   return new MovePass();
}
