#ifndef MONOPOLY_ANGULARBOX_H_
#define MONOPOLY_ANGULARBOX_H_

#include <ostream>
#include "Box.h"

namespace monopoly   	
{
	class AngularBox final : public Box
	{
		public:
			/**
			*	Default constructor.
			*	Create a default instance of AngularBox: NON-STARTING-BOX.
			*/
			AngularBox() : start_bonus_{0}, is_start_{false}, Box(" ") {}
			
			/**
			*	Class constructor.
			*	Create an instance of AngularBox.
			* 
			* 	@name  the box identifier
			* 	@param	start_bonus	the bonus given by the starting box
			*				if is 0 the AngularBox isn't a starting box
			*/
			AngularBox(const std::string &name, unsigned int start_bonus);
			
			/**
			*	Destructor.
			*/
			~AngularBox() override = default; //no dangling pointer
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of AngularBox to copy.
			*/
			AngularBox(const AngularBox& other);
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of AngularBox to move.
			*/
			AngularBox(AngularBox&& other);
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of AngularBox to assign.
			*/
			AngularBox& operator=(const AngularBox& other);
			
			unsigned int start_bonus() const { return start_bonus_; }
			
			std::string show_box() const override;

			
		private:
			
			unsigned int start_bonus_;
			bool is_start_;
	};
	
	std::ostream& operator<<(std::ostream& out, const AngularBox& other); //redefinition
}

#endif //MONOPOLY_ANGULARBOX_H_
