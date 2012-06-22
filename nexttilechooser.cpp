// See LICENSE file for copyright and license details.

#include "nexttilechooser.h"
#include <cassert>
#include <cstdio>

NextTileChooser::NextTileChooser()
   : player(NULL)
{
}

NextTileChooser::~NextTileChooser() {
}

void NextTileChooser::set_player(Player *new_player) {
   assert(new_player);
   player = new_player;
}
