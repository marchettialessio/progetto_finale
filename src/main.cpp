#include "GameBoard.h"
#include "Human.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace monopoly;

int main(int argc, char *argv[])
{
	
	Box* b = new AngularBox("Start", 500);
	Player* tester = new Human("Tester", 100);
	Box* b2 = new LateralBox("Lucca", LateralBox::Category::standard, tester);

	if( dynamic_cast<LateralBox*>(b2) )
	{
		dynamic_cast<LateralBox*>(b2)->upgrade();	
	}
	
	cout << "Angular: " << b->show_box() << " Lateral: " << b2->show_box() << endl;
	
	GameBoard test = GameBoard();	
	test.show_gameboard();
	
	
	return 0;
}
