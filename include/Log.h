#ifndef MONOPOLY_LOG_
#define MONOPOLY_LOG_

#include <string>
#include <fstream>
#include "Player.h"

namespace monopoly
{
	class Log
	{
	private:

		static void write_on_file(std::string string);

	public:
		static void log_start(std::string player_name, int bonus);

		static void log_dice(std::string player_name, int n);

		static void log_advance(std::string player_name, int n);

		static void log_sold(std::string player_name, std::string land_name);

		static void log_upgrade(std::string player_name, std::string land_name);

		static void log_overnight_stay(std::string owner_name, std::string paying_player_name, int stay_price, std::string land_name);

		static void log_game_over(std::string player_name);

		static void log_winner(std::string player_name);

		static void log_loser(std::string player_name);
	};

}

#endif // MONOPOLY_LOG_
