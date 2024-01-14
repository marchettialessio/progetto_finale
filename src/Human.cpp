// #include "Human.h"
// #include "cstring"

// namespace monopoly
// {
// 	Human::Human() : Player() {}

// 	Human::Human(const std::string &name, int balance) : Player(name, balance) {}

// 	void Human::play(GameBoard& current_gameboard)
// 	{

// 		last_roll_ = Dice::Roll();
// 		if (current_position_ + last_roll_ < GameBoard::MAX_SIZE)
// 		{
// 			Box *start_box = current_gameboard.get_box(GameBoard::START);
// 			this->balance_ += dynamic_cast<AngularBox *>(start_box)->start_bonus();
// 		}
// 		current_position_ = (current_position_ + last_roll_) % GameBoard::MAX_SIZE;

// 		Box *current_box = current_gameboard.get_box(current_position_);

// 		if (!dynamic_cast<LateralBox *>(current_box))
// 		{
// 			return;
// 		}

// 		if (dynamic_cast<LateralBox *>(current_box)->is_for_sale())
// 		{
// 			char response;

// 			do
// 			{
// 				std::cout << "Do you want to buy the property? (Y / N):";
// 				std::cin >> response;
// 				std::cout << std::endl;
// 			} while (toupper(response) != 'Y' && toupper(response) != 'N');

// 			if(response == 'Y')
// 			{
// 				dynamic_cast<LateralBox *>(current_box)->sell(this);
// 			}
// 			return;
// 		}

// 		if (!dynamic_cast<LateralBox *>(current_box)->is_box_owner(this))
// 		{
// 			if (!dynamic_cast<LateralBox *>(current_box)->stay(this))
// 			{
// 				this->in_game_ = false;
// 			}
// 			return;
// 		}

// 		if (dynamic_cast<LateralBox *>(current_box)->has_last_upgrade())
// 		{
// 			LateralBox::Building building = dynamic_cast<LateralBox *>(current_box)->get_building();
// 			char response;

// 			do
// 			{
// 				std::cout << "Do you want to upgrade your property? (Y / N):";
// 				std::cin >> response;
// 				std::cout << std::endl;
// 			} while (toupper(response) != 'Y' && toupper(response) != 'N');

// 			if(response == 'Y')
// 			{
// 				if(dynamic_cast<LateralBox *>(current_box)->upgrade())
// 				{
// 					std::cout << "You do not have enough money." << std::endl; 				
// 				}
// 			}
// 			return;
// 		}
// 	}
// }
