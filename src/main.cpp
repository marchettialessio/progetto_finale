#include "Human.h"
#include "Bot.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace monopoly;

int main(int argc, char *argv[])
{
	
	// Box* b = new AngularBox("Start", 500);
	// Player* tester = new Human("Tester", 100);
	// Box* b2 = new LateralBox("Lucca", LateralBox::Category::standard, tester);

	// if( dynamic_cast<LateralBox*>(b2) )
	// {
	// 	dynamic_cast<LateralBox*>(b2)->upgrade();	
	// }
	
	// cout << "Angular: " << b->show_box() << " Lateral: " << b2->show_box() << endl;
	
	// GameBoard test = GameBoard();	
	// test.show_gameboard();
	
	Player* human = new Human("HUMAN", 100);
	Player* bot1 = new Bot("BOT1", 100);
	Player* bot2 = new Bot("BOT2", 100);
	Player* bot3 = new Bot("BOT3", 100);

	GameBoard* test = new GameBoard({human, bot1, bot2, bot3});

	int i = 0;

	while(true)
	{
		int cnt = i % 4;
		Player* p = test->get_player(cnt);
		p->play(*test);
		test->show();
		std::cout << "premi un tasto per prossimo turno";
		std::string tmp;
		std::cin >> tmp;
	}
	
	return 0;
}
