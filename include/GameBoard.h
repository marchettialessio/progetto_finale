/**
 *	
 *	@author Filippo Aghi
 * 
 */

#ifndef MONOPOLY_GAMEBOARD_H_
#define MONOPOLY_GAMEBOARD_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>

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
			~GameBoard() = default; //pointer to players deleted by box destructor
			
			/**
		 	*	Copy constructor not allowed.
		 	* 
		 	*	@param other an instance of GameBoard to copy.
			*/
			GameBoard(const GameBoard& other) = delete;
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of GameBoard to move.
			*/
			GameBoard(GameBoard&& other);
			
			/**
			* 	Assignment operator not allowed.
			* 
			* 	@param other an instance of GameBoard to assign.
			*/
			GameBoard& operator=(const GameBoard& other) = delete;
			
			void show_gameboard() const;
			
			void show_players() const;
			
			void show() const;
			
			bool is_angular_box(int position) const;
			
			Box* get_box(int position);
			
			static constexpr int MAX_SIZE = 28; //must be divisible by 4
			static constexpr int START = 0;
			static constexpr int NUM_PLAYER = 4;
			static constexpr int BOT_ACTION_PROBABILITY = 25;
			
			private:
			
				//unique_ptr to avoid dangling pointer when vector is destroyed
				//shared_ptr permit copy despite a loss of performance		
				//we use a vector instead of a matrix to save empty spaces in the center of the board
				std::vector<std::unique_ptr<Box>> gameboard_;
				std::vector<Player*> player_;
				
				static constexpr int ECONOMY = 8;
				static constexpr int STANDARD = 10;
				static constexpr int LUXURY = 6;
				
				const std::vector<char> MATRIX = {'A','B','C','D','E','F','G','H'};


	};
	
	std::ostream& operator<<(std::ostream& out, const GameBoard& other); //redefinition
}

#endif //MONOPOLY_GAMEBOARD_H_
