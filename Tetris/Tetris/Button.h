#pragma once

#include <SFML/Graphics.hpp>

class Button : public sf::Drawable
{
public:
	Button(unsigned short, unsigned short, unsigned short, unsigned short, sf::Text, sf::Color);
	///konstruktor przycisku, podajemy: wsp. x, wsp. y, szerokosc, wysokosc, tekst, color


	bool check(sf::Event&);						///sprawdzamy czy kliknelismy przycisk
	bool checkABOVE(sf::Event& event);			///sprawdzamy ruch przycisku

	~Button();

	void setState(unsigned short Fstate)			///ustawienie stanu przycisku
	{
		state = Fstate;
	}

private:
	virtual void draw(sf::RenderTarget&, sf::RenderStates)const;		///rysowanie przycisku
	unsigned short state;												///stan przycisku 
	unsigned short x = 0, y = 0, width = 0, height = 0;

	sf::Text text;						///tekst na przycicku
	sf::RectangleShape button;			///przycisk prostok¹tny
	sf::Color color;					///color przycisku
	
	sf::Vertex line1[2] =				
	{
		sf::Vertex(sf::Vector2f((float)x - 1,(float)y - 1)),
		sf::Vertex(sf::Vector2f((float)x + 401,(float)y - 1))
	};
	sf::Vertex line2[2] =
	{
		sf::Vertex(sf::Vector2f((float)x + 401,(float)y - 1)),
		sf::Vertex(sf::Vector2f((float)x + 401, (float)y + 101))
	};
	sf::Vertex line3[2] =
	{
		sf::Vertex(sf::Vector2f((float)x - 1,(float)y + 101)),
		sf::Vertex(sf::Vector2f((float)x + 401,(float)y + 101))
	};
	sf::Vertex line4[2] =
	{
		sf::Vertex(sf::Vector2f((float)x-1,(float)y-1)),
		sf::Vertex(sf::Vector2f((float)x-1,(float)y+101))
	};
};
