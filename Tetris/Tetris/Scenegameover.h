#pragma once
#include "scene.h"
#include "Button.h"
#include <memory>

class Scenegameover:public Scene
{
public:
	Scenegameover();
	virtual ~Scenegameover() = default;

	virtual void KeybordEvents(sf::Event&) override;
	virtual void Update(float dt) override;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
protected:
	sf::Text text_play;
	sf::Text text_quit;
	sf::Font font;

	sf::Text text_gameover;

	std::unique_ptr< Button> play_button;
	std::unique_ptr< Button> quit_button;


};