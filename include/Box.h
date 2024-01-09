#ifndef MONOPOLY_BOX_H_
#define MONOPOLY_BOX_H_

#include <iostream>
#include <string>

namespace monopoly   	
{
	class Box
	{
		public:
		
			/**
			*	Default constructor.
			*	Create a default instance of Box.
			*/
			Box() : name_{"none"} {}
			
			/**
			*	Class constructor.
			*	Create an instance of Box.
			* 
			* 	@param name the string which identifies the box
			*/
			Box(const std::string &name) : name_{name} {}
			
			/**
			*	Destructor.
			*/
			virtual ~Box() = default; // = 0; 
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of Box to copy.
		 	*	=delete against slicing
			*/
			Box(const Box& other) = delete;
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of Box to assign.
			*	=delete against slicing
			*/
			Box& operator=(const Box& other) = delete;
		
		//protected:
		
			/**
			* 	name_ getter.
			*
			*  	@return	the string of the box's name	
			*/
			std::string get_name() const { return name_; }
			
			/**
			* 	name_ setter.
			*
			*  	@param	the string of the box's name	
			*/
			void set_name(const std::string& name) { name_ = name; }
			
			virtual std::string show_box() const { return this->get_name(); }
			
		private:
			std::string name_;

	};
	
	inline std::ostream& operator<<(std::ostream& out, const Box& other) { return out << other.show_box(); } //redefinition
}

#endif //MONOPOLY_BOX_H_
