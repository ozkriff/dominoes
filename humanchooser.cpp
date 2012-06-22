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
#include "tile.h"

HumanChooser::HumanChooser()
   : NextTileChooser()
{
}

void HumanChooser::print_indexed_list(const TilesList *list) {
   int i = 0;
   TilesList::const_iterator tile = list->begin();
   while (tile != list->end()) {
      printf("%d: ", i);
      (*tile)->print();
      printf("   ");
      ++tile;
      ++i;
   }
   putchar('\n');
}

void HumanChooser::put_snake() {
   printf("Snake: ");
   print_tiles_list(&player->game->snake.tiles);
   printf("Hand: ");
   print_indexed_list(&player->tiles);
   printf("Enter index: ");
   int tile_index;
   scanf("%d", &tile_index);
   // TODO check input
   printf("Left(1) or right(2) snake end (1/2): ");
   int left_or_right;
   if (scanf("%d", &left_or_right) != 1)
      die("HumanChooser::put_snake(): scanf");
   // TODO check input
   std::list<Tile*>::iterator tile = player->tiles.begin();
   std::advance(tile, tile_index);
   if (left_or_right == 2 ) {
      player->game->snake.add_tile_right(*tile);
   } else if (left_or_right == 1 ) {
      player->game->snake.add_tile_left(*tile);
   } else {
      // TODO error
   }
   player->tiles.erase(tile);
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
      print_tiles_list(&player->game->snake.tiles);
      goto promt_again;
      break;
   case 2:
      printf("Hand: ");
      print_tiles_list(&player->tiles);
      goto promt_again;
      break;
   case 3:
      // PRINT OTHERS TODO
      // print_tiles_list(player->tiles);
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
      // TODO add snake.check_tile
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
