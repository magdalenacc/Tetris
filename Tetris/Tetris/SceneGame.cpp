#include "SceneGame.h"

SceneGame::SceneGame()
{
	font.loadFromFile("arialbi.ttf");
	text.setFont(font);
	text.setString("gra");
}

void SceneGame::KeybordEvents(sf::Event& e)					///obsluga przyciskow 
{
	game.KeybordEvents(e);
}

void SceneGame::Update(float dt)							///obsluga update'u 
{
	game.Update(dt);
}

void SceneGame::draw(sf::RenderTarget & target, sf::RenderStates states) const					///rysowanie  gry
{
	game.draw(target, states);
}
