#pragma once
#include <SFML/Graphics.hpp>
#include <conio.h>

class Scene : public sf::Drawable
{
public:
	virtual void KeybordEvents(sf::Event&) = 0;
	virtual void Update(float dt) = 0;
	virtual ~Scene() = default;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const =0;
};