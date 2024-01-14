#ifndef MONOPOLY_GAME_H_
#define MONOPOLY_GAME_H_

#include "GameBoard.h"
#include "Player.h"

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


namespace monopoly   	
{
	bool random_probability(unsigned int probability_percent);
    
	unsigned int roll();

	void play_bot(GameBoard& current_gameboard, Player* player);

	void play_human(GameBoard& current_gameboard, Player* player);
			
}

#endif //MONOPOLY_GAME_H_
