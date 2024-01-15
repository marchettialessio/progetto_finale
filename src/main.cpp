#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace monopoly;

int main(int argc, char *argv[])
{

	constexpr int MAX_ROUND = 20; //max number of round 
	
	std::vector<Player*> player = {new Player("Player_1", 100), new Player("Player_2", 100), new Player("Player_3", 100), new Player("Player_4", 100)};

	GameBoard gameboard = GameBoard(player);
	
	std::vector<int> order = player_order();
	
	std::string arg (argv[1]);
	
	if(argc < 2 || arg == "computer")
	{
		for(int i=0; i<MAX_ROUND; i++)
		{
			for(int j=0; j<player.size(); j++)
			{
				if(player.at(order.at(j))->is_in_game_())
					play_bot(gameboard, player.at(order.at(j)));
					
				std::system("clear");
				gameboard.show();
				usleep(305000);
			}
			
			std::system("clear");
			gameboard.show();
			usleep(15000);
		}
	}
	
	if(arg == "human")
	{
		for(int i=0; i<MAX_ROUND; i++)
		{
			std::system("clear");
			gameboard.show_gameboard();
			usleep(15000);
			
			cout << endl;
				
			if(player.at(order.at(0))->is_in_game_())
					play_human(gameboard, player.at(order.at(0)));
					
			for(int j=1; j<player.size(); j++)
			{
				if(player.at(order.at(j))->is_in_game_())
					play_bot(gameboard, player.at(order.at(j)));
					
				std::system("clear");
				gameboard.show_gameboard();
				usleep(305000);
			}
			
			std::system("clear");
			gameboard.show_gameboard();
			usleep(15000);
		}
	}
	
	cout << endl;
	cout << "\033[1;31mWinner is player: \033[0m" << winner(player)+1 << endl;
	
	//destroyer of player pointer
	for(int i=0; i<4; i++)
	{
		delete player.at(i);
	}
	
	return 0;
}
