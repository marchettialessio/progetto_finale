#include "AngularBox.h"

namespace monopoly   	
{	
	AngularBox::AngularBox(const std::string &name, unsigned int start_bonus) : Box(name)
	{
		if(start_bonus > 0)
		{
			start_bonus_ = start_bonus;
			is_start_ = true;
		}
		else
		{
			AngularBox(); //delegating constructor
		}
	}

	AngularBox::AngularBox(const AngularBox& other)
	{
		AngularBox(other.get_name(), other.start_bonus_);
	}

	//move constructor: set previous object to undefine state
	//previous objet after move not usable	
	AngularBox::AngularBox(AngularBox&& other)
	{
		AngularBox(other.get_name(), other.start_bonus_);
		
		other.set_name("");		
		other.start_bonus_ = 0;
		other.is_start_ = false;
	}

	AngularBox& AngularBox::operator=(const AngularBox& other)
	{
		this->set_name(other.get_name());
	
		start_bonus_ = other.start_bonus_;
		is_start_ = other.is_start_;
		
		return *this;
	}
	
	std::string AngularBox::show_box() const
	{
		return this->Box::show_box();
	}
			
	
	std::ostream& operator<<(std::ostream& out, const AngularBox& other) { return out << "LateralBox: " << other.show_box(); } 
}

