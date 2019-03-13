#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"




int main()
{
	Game::Instance().Start();	///tworzymy instancje klasy game
	///dzieki uzyciu wzorca Singleton zapewniamy, ze bêdziemy miec 1. instancje naszej gry

	return 0;
}