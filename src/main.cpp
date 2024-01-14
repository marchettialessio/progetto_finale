#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace monopoly;

int main(int argc, char *argv[])
{
	std::vector<Player*> player = {new Player("Player_1", 1300), new Player("Player_2", 1440), new Player("Player_3", 1220), new Player("Player_4", 1001)};

	GameBoard gameboard = GameBoard(player);	
	
	for(int i=0; i<400; i++)
	{
		for(int j=0; j<4; j++)
		{
			play_bot(gameboard, player.at(j));
		}
		
		std::system("clear");
		test.show();
		usleep(180000);
	}
	
	
	
	test.show();
	
	return 0;
}
