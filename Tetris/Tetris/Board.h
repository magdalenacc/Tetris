#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"
#include "Forms.h"
#include "Blocktype.h"
#include <vector>
#define WIDTH 14
#define HEIGHT	20

class Board : public sf::Drawable
{
public:
	Board(int, int,int s);
	~Board();

	Blocktype Gettype(int x, int y) const
	{
		return tab[x][y].GetType();
	}

	void Settype(Forms);
	
	void Settype(sf::Vector2i, Blocktype);

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
protected:
	///tablica blokow alokowana dynamicznie
	Block **tab;
	///pozycja startowa planszy
	int xBoard;	
	///pozycja startowa planszy
		int yBoard;
		///rozmiar tablicy
		int Boardsize;
};


