#include "scenemenu.h"
#include "game.h"
#include "Button.h"

SceneMenu::SceneMenu()								///konstruktor klasy scenemenu, ustalamy czciocke i tworzymy przyciski "play" oraz "quit"
{

	font.loadFromFile("arialbi.ttf");
	text_play.setFont(font);
	text_play.setString("play");

	play_button = std::make_unique<Button>(Button(200, 50, 400, 100, text_play, sf::Color::Blue));

	text_quit.setFont(font);
	text_quit.setString("quit");

	quit_button = std::make_unique<Button>(Button(200, 316, 400, 100, text_quit, sf::Color::Blue));
}


void SceneMenu::KeybordEvents(sf::Event& e)			///obsluga przyciskow 
{
	

	if (e.type == sf::Event::MouseButtonPressed)
	{
		if (play_button->check(e))
		{
			Game::Instance().LoadScene("game");
			return;
		}
		
		if (quit_button->check(e))
		{
			Game::Instance().Exit();
		}
	}
	
	if (e.type == sf::Event::MouseMoved)
	{
		if (play_button->checkABOVE(e))
		{
			play_button->setState(1);
		}
		else
		{
			play_button->setState(0);
		}

		if (quit_button->checkABOVE(e))
		{
			quit_button->setState(1);
		}
		else
		{
			quit_button->setState(0);
		}
	}
}

void SceneMenu::Update(float dt)																///funkcja update jest pusta, poniewaz w tej scenie nie musimy nic updatowac
{
}

void SceneMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const					///rysowanie przyciskow
{
	
	
	target.draw(*play_button);
	target.draw(*quit_button);
}
