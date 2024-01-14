#include "Dice.h"

namespace monopoly
{
    static unsigned int Roll () 
    {
        unsigned int fist_roll = 1 + (rand() % 6);
        unsigned int second_roll = 1 + (rand() % 6);
        return fist_roll + second_roll;
    }
}