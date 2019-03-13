#pragma once

#include "scene.h"
#include "Board.h"
#include "Forms.h"
#include "Tetris.h"
#include <memory>
class SceneGame : public Scene
{
public:
	SceneGame();
	virtual ~SceneGame() = default;
	virtual void KeybordEvents(sf::Event&) override;
	virtual void Update(float dt) override;

	virtual void draw(sf::RenderTarget &, sf::RenderStates) const override;
protected:
	sf::Text text;						
	sf::Font font;
	
	///obiekt gry
	Tetris game;
};