#ifndef MONOPOLY_DICE_H_
#define MONOPOLY_DICE_H_

#include <ostream>

namespace monopoly   	
{
	class Dice
	{
		public:
		
			/**
			*	Default constructor.
			*	Create a default instance of Dice.
			*
			Dice();
			
			/**
			*	Class constructor.
			*	Create an instance of Dice.
			* 
			* 	@param ...
			*
			Dice(/*param*/
			
			/**
			*	Destructor.
			*
			~Dice();
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of Dice to copy.
			*
			Dice(const Dice& other);
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of Dice to move.
			*
			Dice(Dice&& other);
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of Dice to assign.
			*
			Dice& operator=(const Dice& other);
			*/
			Dice() = delete;
			
			static unsigned int Roll () {}; //gestire la generazione dei 2 dadi
			

	};
	
	//std::ostream& operator<<(std::ostream& out, const Dice& other); //redefinition
}

#endif //MONOPOLY_DICE_H_
