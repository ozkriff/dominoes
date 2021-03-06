// See LICENSE file for copyright and license details.

#include "game.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include "aichooser.h"
#include "humanchooser.h"
#include "misc.h"

void Game::generate_tiles() {
   for (int left = 0; left <= 6; ++left) {
      for (int right = 0; right <= left; ++right) {
         deck.push_back(new Tile(left, right));
      }
   }
   std::random_shuffle(deck.begin(), deck.end());
#if 1
   print_tiles_list(&deck);
#endif
}

int Game::get_players_count() {
   int players_count;
   do {
      printf("Enter players count (2 or 4): ");
      scanf("%i", &players_count);
   } while (players_count != 4 && players_count != 2);
   return players_count;
}

void Game::get_players() {
   int players_count = get_players_count();
   for (int i = 0; i < players_count; ++i) {
      printf("Is player %i - ai? (y/n) ", i);
      char answer[10];
      scanf("%9s", answer);
      NextTileChooser *chooser;
      if (strcmp(answer, "y") == 0) {
         chooser = new AiChooser();
      } else if(strcmp(answer, "n") == 0) {
         chooser = new HumanChooser();
      } else {
         // TODO
         die("'%s'?!?!? [y] OR [n]!\n", answer);
      }
      players.push_back(new Player(this, chooser));
   }
}

Game::Game() {
   get_players();
}

Game::~Game() {
   clean_pointer_container(&deck);
   clean_pointer_container(&players);
   clean_pointer_container(&moves);
}

int Game::run() {
   generate_tiles();
   for (PlayersList::iterator player = players.begin();
         player != players.end(); ++player)
   {
      int tiles_num = 5;
      for (int i = 0; i < tiles_num; ++i) {
         Tile *b = deck.back();
         (*player)->tiles.push_back(b);
         deck.pop_back();
      }
   }
#if 1
   for (PlayersList::iterator player = players.begin();
         player != players.end(); ++player)
   {
      print_tiles_list(&(*player)->tiles);
   }
#endif
   while (1) {
      for (PlayersList::iterator player = players.begin();
            player != players.end(); ++player)
      {
         Move *move = (*player)->do_move();
         if (!move)
            die("BAD MOVE!!!\n");
         printf("move type %i\n", move->get_type());
         moves.push_back(move);
      }
   }
   return EXIT_SUCCESS;
}
