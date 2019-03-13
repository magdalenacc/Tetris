#pragma once
#include <string>
#include <memory>
#include "Scene.h"
#include <SFML\Graphics.hpp>


class Game
{
public:
	static Game & Instance()
	{
		static Game	game;					
		return game;
	}

	void Start();
	void Exit();
	void LoadScene(std::string name);

protected:
	Game();
	void update(float dt);
	void events();
	void renderer();
	
	~Game();
	///renderowane okno
	sf::RenderWindow window;
	///scena ktora bedziemy wyswietlac				
	std::unique_ptr<Scene> scene;			
};