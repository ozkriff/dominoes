// See LICENSE file for copyright and license details.

#include "player.h"
#include <cstdio>
#include "nextbrickchooser.h"

Player::Player(Game *game, NextBrickChooser *chooser)
  : game(game),
    chooser(chooser)
{
  printf("Player::Player\n");
  chooser->set_player(this);
}

Player::~Player() {
}

Move* Player::do_move() {
  return chooser->do_move();
}
