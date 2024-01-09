#include "GameBoard.h"

namespace monopoly   	
{
	GameBoard::GameBoard() : player_{nullptr, nullptr, nullptr, nullptr}
	{
	
		gameboard_.resize(MAX_SIZE);
		for(int i=0; i<MAX_SIZE; i++)
		{
				gameboard_.at(i) = new AngularBox("X",10);
		}
		//angular box insertion
		for(int i=0; i<4; i++)
		{
			if(i == 7)
				gameboard_.at(0) = new AngularBox("P", 20);
			else
				gameboard_.at(MAX_SIZE/4 * i) = new AngularBox();
		}
		
		//lateral box insertion
		
		int economy_count = 0;
		int standard_count = 0;
		int luxury_count = 0;		
		
		std::srand(std::time(NULL));
		int rand;
			
		for(int i=1; i<MAX_SIZE; i++)
		{		
			if(!is_angular_box(i))
			{
				//randomize the box position
				rand = (std::rand() % 3);
				
				if(rand == 0 && economy_count < ECONOMY)
				{
					gameboard_.at(i) = new LateralBox("E", LateralBox::Category::economy);
					economy_count++;
				}
				else if(rand == 2 && luxury_count < LUXURY)
				{
					gameboard_.at(i) = new LateralBox("L", LateralBox::Category::luxury);
					luxury_count++;	
				}
				else if(standard_count < STANDARD)
				{
					gameboard_.at(i) = new LateralBox("S", LateralBox::Category::standard);
					standard_count++;	
				}
				else if(economy_count < ECONOMY)
				{
					gameboard_.at(i) = new LateralBox("E", LateralBox::Category::economy);
					economy_count++;
				}
				else
				{
					gameboard_.at(i) = new LateralBox("L", LateralBox::Category::luxury);
					luxury_count++;	
				}
			}
			
		}
	}

	GameBoard::GameBoard(std::vector<Player*> players)
	{
		
		GameBoard();
		
		player_ = players;
		player_.resize(4);
	}
	
	GameBoard::GameBoard(const GameBoard& other) {}
	
	GameBoard::GameBoard(GameBoard&& other) {}

	GameBoard& GameBoard::operator=(const GameBoard& other) {}
	
	void GameBoard::show_gameboard() const 
	{
		/*for(int i=0; i < MAX_SIZE/4 + 1 ; i++)
		{				
			std::cout << "  " << i+1 << "  ";
		}
		
		std::cout << std::endl;*/
		
		for(int i=0; i < MAX_SIZE/4 + 1; i++)
		{	
			std::cout << "|" << gameboard_[i]->show_box() << "| ";
		}
		
		std::cout << std::endl;
		
		for(int i=1; i < MAX_SIZE/4; i++)
		{
			for(int j=0; j < MAX_SIZE/4 + 1; j++)
			{
				if(j==0)
					std::cout << "|" << gameboard_[MAX_SIZE - i]->show_box() << "|";
					
				else if(j == MAX_SIZE/4)
					std::cout << " |" << gameboard_[MAX_SIZE/4 + i]->show_box() << "|";
					
				else
					std::cout << "    ";
			}
			std::cout << std::endl;
		}
		
		for(int i = 3 * MAX_SIZE/4; i > 2 * MAX_SIZE/4 - 1; i--)
		{
			std::cout << "|" << gameboard_[i]->show_box() << "| " ;
		}
		
		
		std::cout << std::endl;
	}
	
	void GameBoard::show_players() const {}
	
	void GameBoard::show() const {}
	
	bool GameBoard::is_angular_box(int position)
	{
		return position == 0 || (position % (MAX_SIZE/4) == 0);
	}
	
	std::ostream& operator<<(std::ostream& out, const GameBoard& other)
	{
		return out << "";
	} 
}

