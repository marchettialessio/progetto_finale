#include "Game.h"

namespace monopoly   	
{
	bool random_probability(unsigned int probability_percent)
	{
		unsigned int generated_number = rand() % probability_percent;
		if(generated_number < probability_percent)
		{
		    return true;
		}
		return false;
	}
	    
	unsigned int roll() 
	{
		std::srand(std::time(NULL));
		unsigned int fist_roll = 1 ;//+ (rand() % 6);
		unsigned int second_roll = 1 ;//+ (rand() % 6);
		return fist_roll + second_roll;
	}

	void play_bot(GameBoard& current_gameboard, Player* player)
	{
		player->set_last_roll(roll());
		
		if (player->get_current_position() + player->get_last_roll() >= GameBoard::MAX_SIZE)
		{
			Box *start_box = current_gameboard.get_box(GameBoard::START);
			player->set_balance( player->get_balance() + dynamic_cast<AngularBox *>(start_box)->start_bonus());
		}

		player->set_current_position((player->get_current_position() + player->get_last_roll()) % GameBoard::MAX_SIZE);

		Box *current_box = current_gameboard.get_box(player->get_current_position());

		if (!dynamic_cast<LateralBox *>(current_box))
		{
			return;
		}

		if (dynamic_cast<LateralBox *>(current_box)->is_for_sale())
		{

			if(random_probability(GameBoard::BOT_ACTION_PROBABILITY))
			{
				dynamic_cast<LateralBox *>(current_box)->sell(player);
			}
			return;
		}

		if (!dynamic_cast<LateralBox *>(current_box)->is_box_owner(player))
		{
			if (!dynamic_cast<LateralBox *>(current_box)->stay(player))
			{
				player->set_in_game(false);
			}
			return;
		}


		if (!dynamic_cast<LateralBox *>(current_box)->has_last_upgrade())
		{
			LateralBox::Building building = dynamic_cast<LateralBox *>(current_box)->get_building();

			if(random_probability(GameBoard::BOT_ACTION_PROBABILITY))
			{
				if(dynamic_cast<LateralBox *>(current_box)->upgrade())
				{
					std::cout << "You do not have enough money." << std::endl; 				
				}
			}
			return;
		}
	}

	void play_human(GameBoard& current_gameboard, Player* player)
	{
		
		player->set_last_roll(roll());
		
		if (player->get_current_position() + player->get_last_roll() >= GameBoard::MAX_SIZE)
		{
			Box *start_box = current_gameboard.get_box(GameBoard::START);
			player->set_balance( player->get_balance() + dynamic_cast<AngularBox *>(start_box)->start_bonus());
		}
		
		player->set_current_position((player->get_current_position() + player->get_last_roll()) % GameBoard::MAX_SIZE);

		Box *current_box = current_gameboard.get_box(player->get_current_position());

		if (!dynamic_cast<LateralBox *>(current_box))
		{
			return;
		}

		if (dynamic_cast<LateralBox *>(current_box)->is_for_sale())
		{
			char response;

			do
			{
				std::cout << "Do you want to buy the property? (Y / N):";
				std::cin >> response;
				std::cout << std::endl;
			} while (toupper(response) != 'Y' && toupper(response) != 'N');

			if(response == 'Y')
			{
				dynamic_cast<LateralBox *>(current_box)->sell(player);
			}
			return;
		}

		if (!dynamic_cast<LateralBox *>(current_box)->is_box_owner(player))
		{
			if (!dynamic_cast<LateralBox *>(current_box)->stay(player))
			{
				player->set_in_game(false);
			}
			return;
		}

		if (!dynamic_cast<LateralBox *>(current_box)->has_last_upgrade())
		{
			LateralBox::Building building = dynamic_cast<LateralBox *>(current_box)->get_building();
			char response;

			do
			{
				std::cout << "Do you want to upgrade your property? (Y / N):";
				std::cin >> response;
				std::cout << std::endl;
			} while (toupper(response) != 'Y' && toupper(response) != 'N');

			if(response == 'Y')
			{
				if(dynamic_cast<LateralBox *>(current_box)->upgrade())
				{
					std::cout << "You do not have enough money." << std::endl; 				
				}
			}
			return;
		}
	}	
}

