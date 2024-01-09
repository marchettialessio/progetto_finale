#ifndef MONOPOLY_HUMAN_H_
#define MONOPOLY_HUMAN_H_

#include <ostream>

namespace monopoly   	
{
	class Human
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
			* 	@param ...
			*/
			Human(/*param*/);
			
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
			

	};
	
	std::ostream& operator<<(std::ostream& out, const Human& other); //redefinition
}

#endif //MONOPOLY_HUMAN_H_
