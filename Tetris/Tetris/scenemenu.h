#pragma once
#include "scene.h"
#include "Button.h"
#include <memory>

class SceneMenu : public Scene
{
public:
	SceneMenu();
	virtual ~SceneMenu() = default;

	virtual void KeybordEvents(sf::Event&) override;
	virtual void Update(float dt) override;

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
protected:
	///tekst na przycisku play
	sf::Text text_play;
	///tekst na przycisku quit								
	sf::Text text_quit;	
	///wykorzystywana czcionka							
	sf::Font font;								
	
	///przycisk play
	std::unique_ptr< Button> play_button;			
	///przycisk quit
	std::unique_ptr< Button> quit_button;			
};