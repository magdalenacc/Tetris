#include "Scenegameover.h"
#include "game.h"
#include "Button.h"

Scenegameover::Scenegameover()
{



	font.loadFromFile("arialbi.ttf");
	text_play.setFont(font);
	text_play.setString("new game");

	text_gameover.setFont(font);
	text_gameover.setString("game over");

	play_button = std::make_unique<Button>(Button(200, 150, 400, 100, text_play, sf::Color::Blue));

	text_quit.setFont(font);
	text_quit.setString("quit");

	quit_button = std::make_unique<Button>(Button(200, 316, 400, 100, text_quit, sf::Color::Blue));
}


void Scenegameover::KeybordEvents(sf::Event& e)
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

void Scenegameover::Update(float dt)
{
}

void Scenegameover::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	target.draw(text_gameover);
	target.draw(*play_button);
	target.draw(*quit_button);
}