#include "game.h"
#include "scenemenu.h"
#include <Windows.h>
#include <iostream>
#include "SceneGame.h"
#include "scenemenu.h"
#include "Scenegameover.h"

Game::Game()											///konstruktor klasy game
	:scene(new SceneMenu),								///tworzymy nowa scene Menu
	window( sf::VideoMode(1280,720),"Tetris")			///definiuje tryb wideo (szerokosc, wysokosc, bpp)
{
	window.setFramerateLimit(60);						
}

void Game::update(float dt)								///metoda uaktualniajaca gre
{	
	scene->Update(dt);									
}

void Game::events()										///ustalamy reakcje na zdarzenia podczas gry - zamykanie okna
{
	sf::Event e;
	if (window.pollEvent(e))							
	{
		if (e.type == sf::Event::Closed)				
			Exit();										
		scene->KeybordEvents(e);						

		if (e.type == sf::Event::KeyPressed)			
		{
			if (e.key.code == sf::Keyboard::Escape)		
			{	
				Game::Instance().Exit();				
			}
		}
	}

}

void Game::renderer()									///metoda renderujaca gre
{
	window.clear();										
	window.draw(*scene);								
	window.display();									
}

Game::~Game()
{
}

void Game::Start()										///start gry
{
	sf::Clock clock;
	sf::Time time ;
	while (window.isOpen())								
	{	
		time = clock.restart();
		
		update(time.asSeconds());
		events();
		renderer();
	}
}

void Game::Exit()										///zamykanie gry
{
	window.close();
}

void Game::LoadScene(std::string name)					///zaladowanie scen
{
	if (name == "menu")
	{
		scene.reset(new SceneMenu());
	}

	if (name == "game")
	{
		scene.reset(new SceneGame());
	}

	if (name == "gameover")
		scene.reset(new Scenegameover());
}