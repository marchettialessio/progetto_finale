#include "LateralBox.h"

namespace monopoly   	
{
	LateralBox::LateralBox() : category_{Category::standard}, building_{LateralBox::Building::none}, owner_{nullptr}, price_{10,5,5,4,8}, Box("S") {}

	LateralBox::LateralBox(const std::string &name, Category category) : LateralBox(name, category, nullptr)
	{}
	
	LateralBox::LateralBox(const std::string &name, Category category, Player* owner) 
	: Box(name), category_{category}, building_{LateralBox::Building::none}, owner_{owner}
	{
		switch(category)		//price setting based on category
		{
			case Category::economy:
				price_ = ECONOMY_PRICE;
				break;
			
			case Category::standard:
				price_ = STANDARD_PRICE;
				break;
			
			case Category::luxury:
				price_ = LUXURY_PRICE;
				break;
		}
	}

	LateralBox::LateralBox(const LateralBox& other)
	: Box(other.get_name()), category_{other.category_}, building_{other.building_}
	{	
		owner_ = other.owner_;		//shallow copy due to slicing and players management
	}

	LateralBox::LateralBox(LateralBox&& other) 
	: Box(other.get_name()), category_{other.category_}, building_{other.building_}
	{
		other.category_ = LateralBox::Category::standard;
		other.building_ = LateralBox::Building::none;
		
		//delete other.owner_;
	}
	
	LateralBox& LateralBox::operator=(const LateralBox& other) 
	{
		this->set_name(other.get_name());
		
		category_ = other.category_;
		building_ = other.building_;
		owner_ = other.owner_;		//shallow copy due to slicing and players management
		
		return *this;
	}
	
	int LateralBox::get_price(const int type) const
	{
		if(type >= 0 && type <= price_.size())
			return price_.at(type);
		
		return price_.at(0);
	
	}
	
	bool LateralBox::sell(Player* owner)
	{				
		if(owner != nullptr && owner->decrease_balance(price_[(int) Price::lot_price]))
		{
			if(owner_ != nullptr)
				owner_->increment_balance(price_[(int) Price::lot_price]);
			
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
		
		switch(building_)		//check for upgrade and available balance based on next building upgrade
		{
			case Building::none:
				if(!owner_->decrease_balance(price_[(int) Price::house_price]))
					return false;
					
				building_ = LateralBox::Building::house;
				break;
			
			case Building::house:
				if(!owner_->decrease_balance(price_[(int) Price::hotel_price]))
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
	
	bool LateralBox::has_last_upgrade() const
	{
		return building_ == LateralBox::Building::hotel;
	}
	
	bool LateralBox::is_box_owner(const Player* player) const
	{
		if(owner_ == nullptr)
			return false;
			
		return owner_ == player;
	}
	
	bool LateralBox::stay(Player* player)
	{
		if(player == nullptr || owner_ == nullptr)
		{
			return false;
		}
		
		switch(building_)	//check for overnight staying and available balance based on category
		{
			case Building::house:
				if(!player->decrease_balance(price_[(int) Price::house_stay])) 
					return false;
				
				owner_->increment_balance(price_[(int) Price::house_stay]);
				break;
			
			case Building::hotel:
				if(!player->decrease_balance(price_[(int) Price::hotel_stay]))
					return false;
					
				owner_->increment_balance(price_[(int) Price::hotel_stay]);
				break;
		}
		
		return true;	
	}	

	std::ostream& operator<<(std::ostream& out, const LateralBox& other) { return out << "LateralBox: " << other.show_box(); }
}
