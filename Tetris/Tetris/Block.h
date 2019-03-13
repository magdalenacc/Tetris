#pragma once
#include <SFML\Graphics.hpp>
#include "Blocktype.h"


class Block:public sf::Drawable
{
public:
	Block() = default;			///domyslny konstruktor klocka
	Block(float, float, float);///konstruktor klocka - podajemy wspolrzedna x, y i rozmiar boku
	virtual ~Block()=default;
	void init(float, float, float);

	void SetType(Blocktype);
	const Blocktype GetType() const					///zwracamy typ bloku
	{
		return type;
	}
	//void SetTexture(sf::Texture);

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;


protected:

	///tekstura (z folderu Images)
	sf::Texture tekstura;
	///obrazek
	sf::Sprite obrazek;
	///pozycja
	sf::Vector2f position;
	///typ bloku
	Blocktype type;
	///rozmar bloku
	float Blocksize;
};