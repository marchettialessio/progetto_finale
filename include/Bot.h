#ifndef MONOPOLY_BOT_H_
#define MONOPOLY_BOT_H_

#include <ostream>

namespace monopoly   	
{
	class Bot
	{
		public:
		
			/**
			*	Default constructor.
			*	Create a default instance of Bot.
			*/
			Bot();
			
			/**
			*	Class constructor.
			*	Create an instance of Bot.
			* 
			* 	@param ...
			*/
			Bot(/*param*/);
			
			/**
			*	Destructor.
			*/
			~Bot();
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of Bot to copy.
			*/
			Bot(const Bot& other);
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of Bot to move.
			*/
			Bot(Bot&& other);
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of Bot to assign.
			*/
			Bot& operator=(const Bot& other);
			

	};
	
	std::ostream& operator<<(std::ostream& out, const Bot& other); //redefinition
}

#endif //MONOPOLY_BOT_H_
