#include "templatePattern.h"
#include <iostream>

int templatemain()
{
	Game* Cardgame = new CardGame();
	Cardgame->play();
	Game* Chessgame = new ChessGame();
	Chessgame->play();
	return 0;
}