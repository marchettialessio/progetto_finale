#include "LateralBox.h"

namespace monopoly   	
{
	LateralBox::LateralBox() : category_{Category::standard}, building_{LateralBox::Building::none}, owner_{nullptr}, price_{10,5,5,4,8}, Box("S") {}

	LateralBox::LateralBox(const std::string &name, Category category) : Box(name), category_{category}, building_{LateralBox::Building::none}, owner_{nullptr}
	{			
		switch(category)
		{
			case Category::economy:
				price_ = {6,3,3,2,4};
				break;
			
			case Category::standard:
				price_ = {10,5,5,4,8};
				break;
			
			case Category::luxury:
				price_ = {20,10,10,7,14};
				break;
		}
	}
	
	LateralBox::LateralBox(const std::string &name, Category category, Player* owner) 
	: Box(name), category_{category}, building_{LateralBox::Building::none}, owner_{owner}
	{
		switch(category)
		{
			case Category::economy:
				price_ = {6,3,3,2,4};
				break;
			
			case Category::standard:
				price_ = {10,5,5,4,8};
				break;
			
			case Category::luxury:
				price_ = {20,10,10,7,14};
				break;
		}
	}

	LateralBox::LateralBox(const LateralBox& other) {}

	LateralBox::LateralBox(LateralBox&& other) {}
	
	LateralBox& LateralBox::operator=(const LateralBox& other) {}
	
	int LateralBox::get_price(const int type) const
	{
		if(type >= 0 && type <= 4)
			return price_[type];
		
		return price_[0];
	
	}
	
	bool LateralBox::sell(Player* owner)
	{				
		if(owner != nullptr && owner->decrease_balance(price_[0]))
		{
			if(owner_ != nullptr)
				owner_->increment_balance(price_[0]);
			
			owner_ = owner;	
			return true;
		}
		
		return false;	
	}
	
	bool LateralBox::upgrade()
	{
		if(owner_==nullptr || building_ == Building::hotel)
		{
			return false;
		}
		
		switch(building_)
		{
			case Building::none:
				if(!owner_->decrease_balance(price_[1]))
					return false;
					
				building_ = LateralBox::Building::house;
				break;
			
			case Building::house:
				if(!owner_->decrease_balance(price_[2]))
					return false;
					
				building_ = LateralBox::Building::hotel;
				break;
		}
		
		return true;
		
	}
	
	void LateralBox::clear()
	{
		building_ = LateralBox::Building::none;
		owner_ = nullptr;
	}
	
	std::string LateralBox::show_box() const
	{
		std::string building = this->get_name();
		
		if(building_ == LateralBox::Building::house)
		{
			building += "*";
		}
		else if(building_ == LateralBox::Building::hotel)
		{
			building += "^";
		}
		
		return building;
	}
	
	//mancano i setter / getter ove necessari
		

	std::ostream& operator<<(std::ostream& out, const LateralBox& other) { return out << other.show_box(); } //redefinition
}
