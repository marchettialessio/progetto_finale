#ifndef MONOPOLY_GAME_H_
#define MONOPOLY_GAME_H_

#include "GameBoard.h"
#include "Player.h"
#include "Log.h"

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>


namespace monopoly   	
{
	bool random_probability(unsigned int probability_percent);
    
	unsigned int roll(unsigned int n_dice, unsigned int max_value);

	void play_bot(GameBoard& current_gameboard, Player* player);

	void play_human(GameBoard& current_gameboard, Player* player);
	
	int winner(std::vector<Player*> player);
	
	std::vector<int> player_order();
			
}

#endif //MONOPOLY_GAME_H_

