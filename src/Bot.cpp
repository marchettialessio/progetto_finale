// #include "Bot.h"
// #include "cstring"

// namespace monopoly
// {
// 	Bot::Bot() : Player() {}

// 	Bot::Bot(const std::string &name, int balance) : Player(name, balance) {}

//     bool Bot::random_probability(unsigned int probability_percent)
//     {
//         unsigned int generated_number = rand() % probability_percent;
//         if(generated_number < probability_percent)
//         {
//             return true;
//         }
//         return false;
//     }

// 	void Bot::play(GameBoard& current_gameboard)
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

// 			if(random_probability(GameBoard::BOT_ACTION_PROBABILITY))
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

// 			if(random_probability(GameBoard::BOT_ACTION_PROBABILITY))
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
