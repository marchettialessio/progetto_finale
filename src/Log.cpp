/**
 *	
 *	@author Alessio Marchetti
 * 
 */

#include "Log.h"

namespace monopoly
{
    void Log::log_start(std::string player_name, int bonus)
    {
        std::string string = "Player " + player_name + " passed by the start and collected " + std::to_string(bonus) + " fiorins";
        write_on_file(string);
    }

    void Log::log_dice(std::string player_name, int n)
    {
        std::string string = "Player " + player_name + " rolled the dice and got a value of " + std::to_string(n);
        write_on_file(string);
    }

    void Log::log_advance(std::string player_name, int n)
    {
        std::string string = "Player " + player_name + " arrived at the box " + std::to_string(n);
        write_on_file(string);
    }

    void Log::log_sold(std::string player_name, std::string land_name)
    {
        std::string string = "Player " + player_name + " bought the land " + land_name;
        write_on_file(string);
    }

    void Log::log_upgrade(std::string player_name, std::string land_name)
    {
        std::string string = "Player " + player_name + " he built a house on the land " + land_name;
        write_on_file(string);
    }

    void Log::log_overnight_stay(std::string owner_name, std::string paying_player_name, int stay_price, std::string land_name)
    {
        std::string string = "Player " + paying_player_name + " paid " + std::to_string(stay_price) + " fiorins to player " + owner_name + "for overnight stay in the box" + land_name;
        write_on_file(string);
    }

    void Log::log_game_over(std::string player_name)
    {
        std::string string = "Player " + player_name + " finished the turn";
        write_on_file(string);
    }

    void Log::log_loser(std::string player_name)
    {
        std::string string = "Player " + player_name + " was eliminated";
        write_on_file(string);
    }

    void Log::log_winner(std::string player_name)
    {
        std::string string = "Player " + player_name + " won the match";
        write_on_file(string);
    }

    void Log::write_on_file(std::string string)
    {
        std::ofstream myfile;
        myfile.open("../log.txt", std::ios::app);
        myfile << string << std::endl;
        myfile.close();
        return;
    }
}