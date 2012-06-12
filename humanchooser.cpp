// See LICENSE file for copyright and license details.

#include "humanchooser.h"
#include <cstdio>
#include <list>
#include <iterator>
#include "misc.h"
#include "movepass.h"
#include "moveput.h"
#include "movegetmore.h"
#include "game.h"
#include "brick.h"

HumanChooser::HumanChooser()
  : NextBrickChooser()
{
}

void HumanChooser::print_indexed_list(const BricksList *list) {
  int i = 0;
  BricksList::const_iterator it = list->begin();
  while (it != list->end()) {
    printf("%d: ", i);
    (*it)->print();
    printf("  ");
    ++it;
    ++i;
  }
  putchar('\n');
}

void HumanChooser::put_snake() {
  printf("Snake: ");
  print_bricks_list(&player->game->snake->bricks);
  printf("Hand: ");
  print_indexed_list(&player->bricks);
  printf("Enter index: ");
  int brick_index;
  scanf("%d", &brick_index);
  // TODO check input
  printf("Left(1) or right(2) snake end (1/2): ");
  int left_or_right;
  if (scanf("%d", &left_or_right) != 1)
    die("HumanChooser::put_snake(): scanf");
  // TODO check input
  std::list<Brick*>::iterator brick = player->bricks.begin();
  std::advance(brick, brick_index);
  if (left_or_right == 2 ) {
    player->game->snake->add_brick_right(*brick);
  } else if (left_or_right == 2 ) {
    player->game->snake->add_brick_left(*brick);
  } else {
    // TODO error
  }
  player->bricks.erase(brick);
  // goto promt_again;
  // TODO generate Move object
}

Move* HumanChooser::do_move() {
  printf("HumanChooser::do_move(): ...\n");
promt_again: // TODO replace with while()
  printf(
      "1 print snake\n"
      "2 print hand\n"
      "3 print others\n"
      "4 snake\n"
      "5 pass\n"
      "6 take\n"
      "...: ");
  int n;
  int status = scanf("%d", &n);
  if (status != 1) {
    die("status != 1.\n");
  }
  switch (n) {
  case 1:
    printf("Snake: ");
    print_bricks_list(&player->game->snake->bricks);
    goto promt_again;
    break;
  case 2:
    printf("Hand: ");
    print_bricks_list(&player->bricks);
    goto promt_again;
    break;
  case 3:
    // PRINT OTHERS TODO
    // print_bricks_list(player->bricks);
    break;
  case 4:
    put_snake();
    return new MovePut();
    break;
  case 5:
    // pass
    // TODO generate Move object
    return new MovePass();
    break;
  case 6:
    // take
    // TODO add snake.check_brick
    return new MoveGetMore();
    break;
  default:
    // TODO
    die("");
    break;
  }
  die("");
  return NULL;
}
