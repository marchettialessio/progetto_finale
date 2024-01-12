#ifndef MONOPOLY_GAMEBOARD_H_
#define MONOPOLY_GAMEBOARD_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iomanip>
#include "AngularBox.h"
#include "LateralBox.h"

namespace monopoly   	
{
	class GameBoard
	{
		public:
		
			/**
			*	Default constructor.
			*	Create a default instance of GameBoard.
			*/
			GameBoard();
			
			/**
			*	Class constructor.
			*	Create an instance of GameBoard.
			* 
			* 	@param players of the game. Length must be 4 for this version
			*/
			GameBoard(std::vector<Player*> players);
			
			/**
			*	Destructor.
			*/
			~GameBoard() = default;
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of GameBoard to copy.
			*/
			GameBoard(const GameBoard& other);
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of GameBoard to move.
			*/
			GameBoard(GameBoard&& other);
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of GameBoard to assign.
			*/
			GameBoard& operator=(const GameBoard& other);
			
			void show_gameboard() const;
			
			void show_players() const;
			
			void show() const;
			
			bool is_angular_box(int position) const;
			
			Box* get_box(int position);
			
			static constexpr int MAX_SIZE = 28; //must be divisible by 4
			static constexpr int START = 0;
			static constexpr int NUM_PLAYER = 4;
			
			private:
				std::vector<Box*> gameboard_;
				std::vector<Player*> player_;
				
				static constexpr int ECONOMY = 8;
				static constexpr int STANDARD = 10;
				static constexpr int LUXURY = 6;


	};
	
	std::ostream& operator<<(std::ostream& out, const GameBoard& other); //redefinition
}

#endif //MONOPOLY_GAMEBOARD_H_
