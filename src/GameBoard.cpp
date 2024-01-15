#include "GameBoard.h"

namespace monopoly   	
{
	GameBoard::GameBoard() : GameBoard({nullptr, nullptr, nullptr, nullptr}) {} //delegating constructor

	GameBoard::GameBoard(std::vector<Player*> players) : player_{players}
	{	
		if(players.size() > GameBoard::NUM_PLAYER)
			player_.resize(GameBoard::NUM_PLAYER);
			
		gameboard_.resize(GameBoard::MAX_SIZE);
			
		//angular box insertion
		for(int i=0; i<4; i++)
		{
			if(i == GameBoard::START)
				gameboard_.at(0) = std::unique_ptr<Box>(new AngularBox("P", 20));
			else
				gameboard_.at(MAX_SIZE/4 * i) = std::unique_ptr<Box>(new AngularBox());
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
					gameboard_.at(i) = std::unique_ptr<Box>(new LateralBox("E", LateralBox::Category::economy));
					economy_count++;
				}
				else if(rand == 2 && luxury_count < LUXURY)
				{
					gameboard_.at(i) = std::unique_ptr<Box>(new LateralBox("L", LateralBox::Category::luxury));
					luxury_count++;	
				}
				else if(standard_count < STANDARD)
				{
					gameboard_.at(i) = std::unique_ptr<Box>(new LateralBox("S", LateralBox::Category::standard));
					standard_count++;	
				}
				else if(economy_count < ECONOMY)
				{
					gameboard_.at(i) = std::unique_ptr<Box>(new LateralBox("E", LateralBox::Category::economy));
					economy_count++;
				}
				else
				{
					gameboard_.at(i) = std::unique_ptr<Box>(new LateralBox("L", LateralBox::Category::luxury));
					luxury_count++;	
				}
			}
			
		}
	}

	
	GameBoard::GameBoard(GameBoard&& other) 
	{
		player_ = std::move(other.player_);
		gameboard_ = std::move(other.gameboard_);
	}
	
	void GameBoard::show_gameboard() const 
	{ 
		std::vector<int> position;	//contains the position of the players
		
		for(int i=0; i < NUM_PLAYER; i++)
		{
			position.push_back(player_.at(i)->get_current_position());
		}
	
		std::cout << " ";
		
		for(int i=0; i < MAX_SIZE/4 + 1 ; i++)	//column indicator printing (1 2 3 ... MAX_SIZE + 1)
		{				
			std::cout << "  " << i+1 << "  ";
		}
		
		std::cout << std::endl;
		
		std::cout << MATRIX.at(0);	
		
		for(int i=0; i < MAX_SIZE/4 + 1; i++)	//first row printing (box from 1 to MAX_SIZE/4 +1 = *8* )
		{	
			std::string out = "";
			
			out.append("|").append(gameboard_[i]->show_box());
			
			for(int k=0; k < NUM_PLAYER; k++)	//players insertion
			{
				if(i == position.at(k))
					out.append(std::to_string(k+1));
			}
			
			out.append("|");
			
			if(out.length() == 3)	//formatting
				out.insert(0," ").insert(out.length()," ");
			else if(out.length() == 4)
				out.insert(0," ");
			
			std::cout << out;
		}
		
		std::cout << std::endl;
		
		for(int i=1; i < MAX_SIZE/4; i++)	//middle row printing (box of first *1* and last *8* column )
		{		
			for(int j=0; j < MAX_SIZE/4 + 1; j++)
			{
				std::string out = "";
				
				if(j==0)
				{
					std::cout << MATRIX.at(i % (MAX_SIZE/4));
					out.append("|").append(gameboard_[MAX_SIZE - i]->show_box());
				}
					
				else if(j == MAX_SIZE/4)
					out.append("|").append(gameboard_[MAX_SIZE/4 + i]->show_box());
					
				else
					out += "     ";
					
				for(int k=0; k < NUM_PLAYER; k++)	//players insertion
				{
					if(j == 0 && MAX_SIZE - i == position.at(k))
						out.append(std::to_string(k+1));
						
					if(j == MAX_SIZE/4 && MAX_SIZE/4 + i == position.at(k))
						out.append(std::to_string(k+1));
				}
				
										
				if(out != "     ")
					out.append("|");
					
				if(out.length() == 3)	//formatting
					out.insert(0," ").insert(out.length()," ");
				else if(out.length() == 4)
					out.insert(0," ");
					
				std::cout << out;
			}
		
			std::cout << std::endl;
		}
		
		std::cout << MATRIX.at(7);
				
		for(int i = 3 * MAX_SIZE/4; i > 2 * MAX_SIZE/4 - 1; i--)	//last row printing (box of row H)
		{
			std::string out = "";
			
			out.append("|").append(gameboard_[i]->show_box());
			
			for(int k=0; k < NUM_PLAYER; k++)	//players insertion
			{
				if(i == position.at(k))
					out.append(std::to_string(k+1));
			}
			
			out.append("|");
			
			if(out.length() == 3)	//formatting
				out.insert(0," ").insert(out.length()," ");
			else if(out.length() == 4)
				out.insert(0," ");
			
			std::cout << out;
		}
		
		
		std::cout << std::endl;
	}
	
	void GameBoard::show_players() const 
	{
	
		std::vector<std::string> out;
		
		for(int i=0; i < NUM_PLAYER; i++)
		{
			std::string p = "Player #";
			
			p += std::to_string(i+1) + ": ";
			
			out.push_back(p);
		}

		
		for(int i=0; i < MAX_SIZE; i++)
		{
			if(dynamic_cast<LateralBox*>(gameboard_.at(i).get()))
			{
				for(int j=0; j < GameBoard::NUM_PLAYER; j++)
				{
					if(dynamic_cast<LateralBox*>(gameboard_.at(i).get())->is_box_owner(player_.at(j)))
					{
						if(i <= MAX_SIZE/4)
							out.at(j) += "A" + std::to_string(i+1) + " "; 
							
						else if(i <= MAX_SIZE/2)
							out.at(j) += MATRIX.at(i % (MAX_SIZE/4)) + std::to_string(8) + " "; 
							
						else if(i <= 3 * MAX_SIZE/4)
							out.at(j) += "H" + std::to_string(MAX_SIZE/4 - (i % (MAX_SIZE/4)) + 1) + " "; 
							
						else
							out.at(j) += MATRIX.at(MAX_SIZE/4 - (i % (MAX_SIZE/4))) + std::to_string(1) + " "; 
					}
				}
			}
		
		}
		
		for(int i=0; i < GameBoard::NUM_PLAYER; i++)
		{
			if(out.at(i) == "Player #" + std::to_string(i+1) + ": ")
				out.at(i) += "no property";
		}
		
		std::cout << "Players property: " << std::endl;
		
		for(int i=0; i < GameBoard::NUM_PLAYER; i++)
		{
			std::cout << out.at(i) << std::endl;

		}
		
	}
	
	void GameBoard::show() const 
	{
		std::cout << std::endl;
	
		this->show_gameboard();
		
		std::cout << std::endl;
		
		this->show_players();
		
		std::cout << std::endl;
		
		std::cout << "Players balance: " << std::endl;
		
		for(int i=0; i < GameBoard::NUM_PLAYER; i++)
		{
			if(player_.at(i) != nullptr)
				std::cout << "Player #" << std::to_string(i+1) << ": " << player_.at(i)->get_balance() << std::endl;
			else
				std::cout << "Player #" << std::to_string(i+1) << ": " << "none" << std::endl;

		}
	
	}
	
	bool GameBoard::is_angular_box(int position) const
	{
		return position == 0 || (position % (MAX_SIZE/4) == 0);
	}
	
	Box* GameBoard::get_box(int position)
	{
		return gameboard_.at(position).get(); //if position is out_of_range throw out_of_range_exception
	}
	
	std::ostream& operator<<(std::ostream& out, const GameBoard& other)
	{
		return out << "GameBoard: >size " << GameBoard::MAX_SIZE << ">player in game " << GameBoard::NUM_PLAYER << std::endl;
	} 
}

