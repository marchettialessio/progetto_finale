/**
 *	
 *	@author Alessio Marchetti
 * 
 */

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
	/**
	 *
	 * 	@return boolean = true if an event occur, given a percentage of probability
	 */
	bool random_probability(unsigned int probability_percent);
    
	/**
	 *
	 * 	@return a random value of a roll of two dice
	 */
	unsigned int roll(unsigned int n_dice, unsigned int max_value);

	/**
	 *
	 * 	play a turn in case the player is a bot
	 */
	void play_bot(GameBoard& current_gameboard, Player* player);

	/**
	 *
	 * 	play a turn in case the player is a human
	 */
	void play_human(GameBoard& current_gameboard, Player* player);
	
	std::vector<int> player_order();
			
}

#endif //MONOPOLY_GAME_H_
