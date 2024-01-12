#ifndef MONOPOLY_PLAYER_H_
#define MONOPOLY_PLAYER_H_

#include <ostream>
#include <string>

namespace monopoly   	
{
	class Player
	{
		public:
		
			/**
			*	Default constructor.
			*	Create a default instance of Player.
			*/
			Player();
			
			/**
			*	Class constructor.
			*	Create an instance of Player.
			* 
			* 	@param name	the name of the Player
			* 	@param balance 	the starting balance of the Player
			*/
			Player(const std::string& name, int balance);
			
			/**
			*	Destructor.
			*/
			virtual ~Player() = default;
			
			/**
		 	*	Copy constructor.
		 	* 
		 	*	@param other an instance of Player to copy.
		 	*	=delete against slicing
			*/
			Player(const Player& other) = delete;
			
			/**
		 	*	Move constructor.
		 	* 
		 	*	@param other an instance of Player to move.
		 	*	=delete against slicing
			*/
			Player(Player&& other) = delete;
			
			/**
			* 	Assignment operator.
			* 
			* 	@param other an instance of Player to assign.
			*/
			Player& operator=(const Player& other) = delete;
			
			int get_balance() const { return balance_; }
			
			bool is_playing() { return balance_ >= 0; }
			
			void increment_balance(const int amount);
			
			bool decrease_balance(const int amount);
			
			bool is_in_game_() {return in_game_;}

			virtual void play(GameBoard current_gameboard) = 0;
			
			//bool start_increment() 
			
			protected: 
				unsigned int current_position_;
				unsigned int last_roll_;
				std::string name_;
				int balance_;
				bool in_game_ = true;
				
				static constexpr int DEFAULT_BALANCE = 100;

	};
	
	std::ostream& operator<<(std::ostream& out, const Player& other); //redefinition
}

#endif //MONOPOLY_PLAYER_H_
