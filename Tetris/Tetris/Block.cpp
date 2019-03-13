#include "Block.h"

Block::Block(float xpoz, float ypoz, float bsize):Blocksize(bsize)		
{
	position.x = xpoz;
	position.y = ypoz;

	obrazek.setPosition(position);
}


void Block::init(float xpoz, float ypoz, float bsize)				///inicjalizacja bloku
{
	position.x = xpoz;
	position.y = ypoz;
	Blocksize = bsize;

	obrazek.setPosition(position);
}

void Block::SetType(Blocktype t)									///ustawienie typu bloku (koloru)
{
	type = t;
	switch (type)
	{
	case Blocktype::empty : 
	{
		tekstura.loadFromFile("Images/white.png");
		obrazek.setTexture(tekstura);
	} break;
	case Blocktype::grey:
	{
		tekstura.loadFromFile("Images/grey.png");
		obrazek.setTexture(tekstura);
	}break;
	case Blocktype::yellow:
	{
		tekstura.loadFromFile("Images/yellow.png");
		obrazek.setTexture(tekstura);
	}break;

	case Blocktype::red:
	{
		tekstura.loadFromFile("Images/red.png");
		obrazek.setTexture(tekstura);
	}break;
	case Blocktype::green:
	{
		tekstura.loadFromFile("Images/green.png");
		obrazek.setTexture(tekstura);
	}break;
	case Blocktype::blue:
	{
		tekstura.loadFromFile("Images/blue.png");
		obrazek.setTexture(tekstura);
	}break;
	default:
		tekstura.loadFromFile("Images/blue.png");
		obrazek.setTexture(tekstura);
		break;
	}
	obrazek.setScale(Blocksize / obrazek.getTexture()->getSize().x , Blocksize / obrazek.getTexture()->getSize().y);
}



void Block::draw(sf::RenderTarget &target , sf::RenderStates states) const					///rysowanie bloku
{
	target.draw(obrazek);
}

