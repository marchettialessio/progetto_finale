#ifndef MONOPOLY_HUMAN_H_
#define MONOPOLY_HUMAN_H_

#include <iostream>
#include <cstdlib>
#include "GameBoard.h"
#include "Dice.h"
#include "AngularBox.h"
#include "LateralBox.h"

namespace monopoly   	
{
	class Human : public Player
	{
		public:
		
			/**
			*	Default constructor.
			*	Create a default instance of Human.
			*/
			Human();
			
			/**
			*	Class constructor.
			*	Create an instance of Human.
			* 
			* 	@param name	the name of the Player
			* 	@param balance 	the starting balance of the Player
			*/
			Human(const std::string& name, int balance);
			
			/**
			*	Destructor.
			*/
			~Human();
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of Human to copy.
			*/
			Human(const Human& other);
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of Human to move.
			*/
			Human(Human&& other);
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of Human to assign.
			*/
			Human& operator=(const Human& other);
			
			void play(GameBoard& current_gameboard);
			
	};
	
	std::ostream& operator<<(std::ostream& out, const Human& other); //redefinition
}

#endif //MONOPOLY_HUMAN_H_
