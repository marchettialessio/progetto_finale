/**
 *	
 *	@author Matteo Milan
 * 
 */

#include "Player.h"

namespace monopoly   	
{
	Player::Player() : balance_{DEFAULT_BALANCE}, name_{"none"}, current_position_{0} {}

	Player::Player(const std::string& name, int balance) : balance_{balance}, name_{name}, current_position_{0} {} 
	
	void Player::increment_balance(const int amount)
	{
		balance_ += amount;
	}
	
	bool Player::decrease_balance(const int amount)
	{
		if(balance_ >= amount)
		{
			balance_ -= amount;
			return true;
		}
		
		return false;
	}


	std::ostream& operator<<(std::ostream& out, const Player& other) 
	{
		return out << "Name: " << other.get_name() << " balance: " << other.get_balance() << std::endl;
	}
	
}
