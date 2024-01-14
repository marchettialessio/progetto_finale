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
			const std::string FILE_NAME = "log.txt";	
			
			std::ofstream open_file();
			
			
		public:
			
			void log_start(Player* player, int bonus);
			
			void log_dice(Player* player, int n);
			
			void log_advance(Player* player, int n);
			
			void log_sold(Player* player, std::string bonus);
			
			void log_upgrade(Player* player, int bonus);
			
			void log_overnight_stay(Player* player, int bonus);
			
			void log_game_over(Player* player, int bonus);
			
			void log_winner(Player* player, int bonus);
			
			void log_loser(Player* player, int bonus);

	};
	
}

#endif //MONOPOLY_LOG_
