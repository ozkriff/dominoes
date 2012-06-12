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

void Game::generate_bricks() {
  for (int left = 0; left <= 6; ++left) {
    for (int right = 0; right <= left; ++right) {
      all_bricks->push_front(new Brick(left, right));
    }
  }
  {
    std::vector<Brick*> tmp(all_bricks->begin(), all_bricks->end());
    std::random_shuffle(tmp.begin(), tmp.end());
    std::copy(tmp.begin(), tmp.end(), all_bricks->begin());
  }
#if 1
  print_bricks_list(all_bricks);
#endif
}

int Game::get_players_count() {
  int players_count;
  do {
    printf("Еnter players count (2 or 4): ");
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
    NextBrickChooser *chooser;
    if (strcmp(answer, "y") == 0) {
      chooser = new AiChooser();
    } else if(strcmp(answer, "n") == 0) {
      chooser = new HumanChooser();
    } else {
      // TODO
      die("'%s'?!?!? [y] OR [n]!\n", answer);
    }
    players->push_back(new Player(this, chooser));
  }
}

Game::Game()
  : snake(new Snake),
    players(new PlayersList),
    moves(new MovesList),
    all_bricks(new BricksList)
{
  get_players();
}

Game::~Game() {
}

int Game::run() {
  generate_bricks();
  for (PlayersList::iterator it = players->begin();
      it != players->end(); ++it)
  {
    int bricks_num = 5;
    for (int i = 0; i < bricks_num; ++i) {
      Brick *b = all_bricks->front();
      (*it)->bricks.push_back(b);
      all_bricks->pop_front();
    }
  }
#if 1
  for (PlayersList::iterator pi = players->begin();
      pi != players->end(); ++pi)
  {
    print_bricks_list(&(*pi)->bricks);
  }
#endif
  while (1) {
    for (PlayersList::iterator it = players->begin();
        it != players->end(); ++it)
    {
      Move *move = (*it)->do_move();
      if (!move)
        die("BAD MOVE!!!\n");
      printf("move type %i\n", move->get_type());
      moves->push_back(move);
    }
  }
  return EXIT_SUCCESS;
}
