// See LICENSE file for copyright and license details.

#include "nextbrickchooser.h"
#include <cassert>
#include <cstdio>

NextBrickChooser::NextBrickChooser()
   : player(NULL)
{
}

NextBrickChooser::~NextBrickChooser() {
}

void NextBrickChooser::set_player(Player *new_player) {
   assert(new_player);
   player = new_player;
}
