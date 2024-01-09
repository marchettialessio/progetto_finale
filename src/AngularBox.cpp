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

	AngularBox::AngularBox(const AngularBox& other){}

	AngularBox::AngularBox(AngularBox&& other){}

	AngularBox& AngularBox::operator=(const AngularBox& other){}
	
	std::string AngularBox::show_box() const
	{
		return this->Box::show_box();
	}
			
	
	std::ostream& operator<<(std::ostream& out, const AngularBox& other) { return out << other.show_box(); } //redefinition
}

