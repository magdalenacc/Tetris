#include "Button.h"


Button::Button(unsigned short Bx, unsigned short By,				
	unsigned short Bwidth, unsigned short Bheight,
	sf::Text Btext, sf::Color Bcolor) : 
	x(Bx), y(By), width(Bwidth),height(Bheight),text(Btext)
{
	button.setPosition(sf::Vector2f(x, y));
	button.setSize(sf::Vector2f(width, height));
	button.setFillColor(Bcolor);
	text.setPosition(sf::Vector2f((float)(x+width/2-(Btext.getGlobalBounds().width/2) ),
								  ((float)(y + height / 2)- Btext.getGlobalBounds().height/2)));
	
}

Button::~Button()
{

}


void Button::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
	target.draw(button, states);
	target.draw(text, states);
	if (state == 1)
	{
		target.draw(line1, 2, sf::LinesStrip);
		target.draw(line2, 2, sf::LinesStrip);
		target.draw(line3, 2, sf::LinesStrip);
		target.draw(line4, 2, sf::LinesStrip);

	}
	
}

bool Button::check(sf::Event& event)
{
	if (((event.mouseButton.x > x) && (event.mouseButton.x<x + width)) &&
		(event.mouseButton.y>y) && (event.mouseButton.y < y + height))
	{
		return true;
	}
	else
		return false;
}

bool Button::checkABOVE(sf::Event& event)
{
	if (((event.mouseMove.x > x) && (event.mouseMove.x<x + width)) &&
		(event.mouseMove.y>y) && (event.mouseMove.y < y + height))
	{
		return true;
	}
	else
		return false;
}