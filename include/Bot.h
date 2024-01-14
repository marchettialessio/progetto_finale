// #ifndef MONOPOLY_BOT_H_
// #define MONOPOLY_BOT_H_

// #include <cstdlib>
// #include "Player.h"
// #include "Dice.h"
// #include "AngularBox.h"
// #include "LateralBox.h"
// #include "GameBoard.h"


// namespace monopoly   	
// {
// 	class Bot : public Player
// 	{
// 		public:
		
// 			/**
// 			*	Default constructor.
// 			*	Create a default instance of Bot.
// 			*/
// 			Bot();
			
// 			/**
// 			*	Class constructor.
// 			*	Create an instance of Human.
// 			* 
// 			* 	@param name	the name of the Player
// 			* 	@param balance 	the starting balance of the Player
// 			*/
// 			Bot(const std::string& name, int balance);
			
// 			/**
// 			*	Destructor.
// 			*/
// 			~Bot();
			
// 			/**
// 		 	*	Copy constructor.
// 		 	* 
// 		 	*	@param other an instance of Bot to copy.
// 			*/
// 			Bot(const Bot& other);
			
// 			/**
// 		 	*	Move constructor.
// 		 	* 
// 		 	*	@param other an instance of Bot to move.
// 			*/
// 			Bot(Bot&& other);
			
// 			/**
// 			* 	Assignment operator.
// 			* 
// 			* 	@param other an instance of Bot to assign.
// 			*/
// 			Bot& operator=(const Bot& other);
			
// 			void play(GameBoard& current_gameboard);

// 		private:

// 			/**
// 			* 	returns a boolean based on the realization of an event, given a probability
// 			* 
// 			* 	@param probability_percent probability that the event will occur.
// 			*	@return true if event occur
// 			*/
// 			bool random_probability(unsigned int probability_percent);
			

// 	};
	
// 	std::ostream& operator<<(std::ostream& out, const Bot& other); //redefinition
// }

// #endif //MONOPOLY_BOT_H_
