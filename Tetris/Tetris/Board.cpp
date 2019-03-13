#include "Board.h"

Board::Board(int a, int b,int s)				///konstruktor tablicy 
{
	Boardsize = s;
	tab = new Block*[WIDTH];

	for (int y = 0; y < WIDTH; y++)
		tab[y] = new Block[HEIGHT];


	for (int x = 0; x < WIDTH; x++)
	for (int y = 0; y < HEIGHT; y++) 
	{
		tab[x][y].init(x * Boardsize +a, y * Boardsize +b, Boardsize);

		if (x == 0 || y == HEIGHT - 1||x==WIDTH-1)
		{
			tab[x][y].SetType(Blocktype::grey);
		}
		else tab[x][y].SetType(Blocktype::empty);
	}
}


Board::~Board()								///destruktor tablicy
{
	for (int i = 0; i < WIDTH; i++)
	{
		delete[] tab[i];
	}
	delete[] tab;
}

void Board::Settype(Forms f)								///ustalenie typu(koloru) bloku na podstwie formy
{
	sf::Vector2i poz = f.GetPosition();
	for (int x = 0; x < 4;x++)
		for (int y= 0; y< 4; y++)
		{
			if (f.GetBlock(x,y) != Blocktype::empty)
			{
				auto v = poz;
				tab[v.x+x-1][v.y+y-1].SetType(f.GetBlock(x,y));
			}
		}
}

void Board::Settype(sf::Vector2i v, Blocktype t)						///ustalenie typu na tablicy
{
	tab[v.x][v.y].SetType(t);
}

void Board::draw(sf::RenderTarget & t, sf::RenderStates) const				///rysowanie tablicy
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			t.draw(tab[x][y]);
		}
	}

}
