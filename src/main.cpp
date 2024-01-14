#include "GameBoard.h"
#include "Dice.h"
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;
using namespace monopoly;

bool random_probability(unsigned int probability_percent)
{
	unsigned int generated_number = rand() % probability_percent;
	if(generated_number < probability_percent)
	{
	    return true;
	}
	return false;
}
    
unsigned int Roll() 
{
	unsigned int fist_roll = 1 ;//+ (rand() % 6);
	unsigned int second_roll = 1 ;//+ (rand() % 6);
	return fist_roll + second_roll;
}

void play_bot(GameBoard& current_gameboard, Player* player)
{
	player->set_last_roll(Roll());
	
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
		player->set_last_roll(Roll());
		
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


int main(int argc, char *argv[])
{
	
	//Box* b = new AngularBox("Start", 500);
	//Player* tester = new Player("Tester", 100);
	//Box* b2 = new LateralBox("Lucca", LateralBox::Category::standard, tester);
	
	std::vector<Player*> player = {new Player("Tester", 1300), new Player("Tester", 1440), new Player("Tester", 1220), new Player("Tester", 1001)};

	/*if( dynamic_cast<LateralBox*>(b2) )
	{
		dynamic_cast<LateralBox*>(b2)->upgrade();	
	}
	
	cout << "Angular: " << b->show_box() << " Lateral: " << b2->show_box() << endl;*/
	
	GameBoard test = GameBoard(player);	
	
	/*dynamic_cast<LateralBox*>(test.get_box(2))->sell(player.at(0));
	dynamic_cast<LateralBox*>(test.get_box(15))->sell(player.at(1));
	dynamic_cast<LateralBox*>(test.get_box(23))->sell(player.at(2));
	dynamic_cast<LateralBox*>(test.get_box(26))->sell(player.at(3));
	dynamic_cast<LateralBox*>(test.get_box(18))->upgrade();
	dynamic_cast<LateralBox*>(test.get_box(25))->upgrade();*/

	
	//test.show_gameboard();
	
	for(int i=0; i<400; i++)
	{
		for(int j=0; j<4; j++)
		{
			play_bot(test, player.at(j));
		}
		
		std::system("clear");
		test.show();
		usleep(180000);
	}
	
	
	
	test.show();
	
	return 0;
}
