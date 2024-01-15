#include "Game.h"

namespace monopoly
{
	bool random_probability(unsigned int probability_percent)
	{
		unsigned int generated_number = rand() % probability_percent;
		if (generated_number < probability_percent)
		{
			return true;
		}
		return false;
	}

	unsigned int roll(unsigned int n_dice, unsigned int max_value)
	{
		unsigned int value_roll;

		for (int i = 0; i < n_dice; i++)
		{
			value_roll += 1 + (rand() % max_value);
		}

		return value_roll;
	}

	void play_bot(GameBoard &current_gameboard, Player *player)
	{
		std::srand(std::time(NULL));
		player->set_last_roll(roll(2, 6));
		Log::log_dice(player->get_name(), player->get_last_roll());

		if (player->get_current_position() + player->get_last_roll() >= GameBoard::MAX_SIZE)
		{
			Box *start_box = current_gameboard.get_box(GameBoard::START);
			player->set_balance(player->get_balance() + dynamic_cast<AngularBox *>(start_box)->start_bonus());
			Log::log_start(player->get_name(), dynamic_cast<AngularBox *>(start_box)->start_bonus());
		}

		player->set_current_position((player->get_current_position() + player->get_last_roll()) % GameBoard::MAX_SIZE);
		Log::log_advance(player->get_name(), player->get_current_position());

		Box *current_box = current_gameboard.get_box(player->get_current_position());

		if (!dynamic_cast<LateralBox *>(current_box))
		{
			Log::log_game_over(player->get_name());
			return;
		}

		if (dynamic_cast<LateralBox *>(current_box)->is_for_sale())
		{

			if (random_probability(GameBoard::BOT_ACTION_PROBABILITY))
			{
				if (dynamic_cast<LateralBox *>(current_box)->sell(player))
				{
					Log::log_sold(player->get_name(), dynamic_cast<LateralBox *>(current_box)->get_name());
				}
			}
			Log::log_game_over(player->get_name());

			return;
		}

		if (!dynamic_cast<LateralBox *>(current_box)->is_box_owner(player))
		{
			if (!dynamic_cast<LateralBox *>(current_box)->stay(player))
			{
				player->set_in_game(false);
				Log::log_game_over(player->get_name());
				Log::log_loser(player->get_name());
				return;
			}
			Log::log_overnight_stay(player->get_name(), dynamic_cast<LateralBox *>(current_box)->get_owner()->get_name(), dynamic_cast<LateralBox *>(current_box)->get_price((int)dynamic_cast<LateralBox *>(current_box)->get_category()), dynamic_cast<LateralBox *>(current_box)->get_name());
			Log::log_game_over(player->get_name());

			return;
		}

		if (!dynamic_cast<LateralBox *>(current_box)->has_last_upgrade())
		{
			LateralBox::Building building = dynamic_cast<LateralBox *>(current_box)->get_building();

			if (random_probability(GameBoard::BOT_ACTION_PROBABILITY))
			{
				if (!dynamic_cast<LateralBox *>(current_box)->upgrade())
				{
					std::cout << "You do not have enough money." << std::endl;
					Log::log_game_over(player->get_name());
					return;
				}
				Log::log_upgrade(player->get_name(), dynamic_cast<LateralBox *>(current_box)->get_name());
			}
		}
		Log::log_game_over(player->get_name());
	}

	void play_human(GameBoard &current_gameboard, Player *player)
	{
		std::srand(std::time(NULL));
		player->set_last_roll(roll(2, 6));
		Log::log_dice(player->get_name(), player->get_last_roll());

		if (player->get_current_position() + player->get_last_roll() >= GameBoard::MAX_SIZE)
		{
			Box *start_box = current_gameboard.get_box(GameBoard::START);
			player->set_balance(player->get_balance() + dynamic_cast<AngularBox *>(start_box)->start_bonus());
			Log::log_start(player->get_name(), dynamic_cast<AngularBox *>(start_box)->start_bonus());
		}

		player->set_current_position((player->get_current_position() + player->get_last_roll()) % GameBoard::MAX_SIZE);
		Log::log_advance(player->get_name(), player->get_current_position());

		Box *current_box = current_gameboard.get_box(player->get_current_position());

		if (!dynamic_cast<LateralBox *>(current_box))
		{
			Log::log_game_over(player->get_name());

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

			if (response == 'Y')
			{
				if (dynamic_cast<LateralBox *>(current_box)->sell(player))
				{
					Log::log_sold(player->get_name(), dynamic_cast<LateralBox *>(current_box)->get_name());
				}
			}
			Log::log_game_over(player->get_name());
			return;
		}

		if (!dynamic_cast<LateralBox *>(current_box)->is_box_owner(player))
		{
			if (!dynamic_cast<LateralBox *>(current_box)->stay(player))
			{
				player->set_in_game(false);
				Log::log_game_over(player->get_name());
				Log::log_loser(player->get_name());
				return;
			}
			Log::log_overnight_stay(player->get_name(), dynamic_cast<LateralBox *>(current_box)->get_owner()->get_name(), dynamic_cast<LateralBox *>(current_box)->get_price((int)dynamic_cast<LateralBox *>(current_box)->get_category()), dynamic_cast<LateralBox *>(current_box)->get_name());
			Log::log_game_over(player->get_name());

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

			if (response == 'Y')
			{
				if (!dynamic_cast<LateralBox *>(current_box)->upgrade())
				{
					std::cout << "You do not have enough money." << std::endl;
					Log::log_game_over(player->get_name());
					return;
				}
				Log::log_upgrade(player->get_name(), dynamic_cast<LateralBox *>(current_box)->get_name());
			}
		}
		Log::log_game_over(player->get_name());
	}

	
	std::vector<int> player_order()
	{
		std::vector<int> order;
		order.resize(GameBoard::NUM_PLAYER, -1);
		
		std::srand(std::time(NULL));
		
		for(int i=0; i<GameBoard::NUM_PLAYER; i++) //position i in the vector identify the player position (0 -> NUM_PLAYER-1)
		{
			unsigned int position = GameBoard::NUM_PLAYER - roll(1,GameBoard::NUM_PLAYER);
			
			if(order.at(position) == -1)
			{
				order.at(position) = i;	//i is the player in taht position (ex. player 3 in first position: i=2, position=0)
			}
			else
			{
				while(order.at(position) != -1)
				{
					position = GameBoard::NUM_PLAYER - roll(1,GameBoard::NUM_PLAYER);
				}
				order.at(position) = i;	
			}
		}
		
		return order;
	}
}
