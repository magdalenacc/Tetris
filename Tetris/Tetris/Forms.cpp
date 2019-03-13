#include "Forms.h"


Forms::~Forms()
{
}

Forms::Forms(float xBoard, float yBoard, float s)
{
	SetBoard(xBoard, yBoard, s);
}

void Forms::SetPosition(sf::Vector2i v)					///ustalenie pozycji
{
	position = v;
	for (int x = -1; x < 3; x++)
	{
		for (int y = -1; y < 3; y++)
		{
			form[x+1][y+1].init((v.x+x) * Blocksize+xBoard,( v.y+y) * Blocksize+yBoard, Blocksize);
		}
	}
		
}


void Forms::SetBlock(int xs, int ys, Block t)					///ustalenie bloku w formie
{
	form[xs][ys] = t;
}

void Forms::SetBoard(float x, float y, float s)					///ustalenie blokow
{
	Blocksize = s;
	xBoard = x;
	yBoard = y;

	for (int y = 0; y < 4; y++)
		for (int x = 0; x < 4; x++)
		{
			form[y][x].init(y, x, s);
		}

}

void Forms::SetType(Blocktype t[4][4])				///ustalenie typow na podstawie tablicy typow bloku
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			form[x][y].SetType(t[x][y]);
		}
	}
}

void Forms::Rotateleft()								///obrot w lewo
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = y + 1; x < 4; x++)
		{
			auto tmp = form[y][x].GetType();
			form[y][x].SetType( form[x][y].GetType());
			form[x][y].SetType( tmp);
		}
	}

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 4; y++)
		{

			auto t=form[x][y].GetType() ;
				form[x][y].SetType(form[3 - x][y].GetType());
				form[3 - x][y].SetType(t);
		}
	}
}

void Forms::Rotateright()					///obrot w prawo
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = y + 1; x < 4; x++)
		{
			auto tmp = form[y][x].GetType();
			form[y][x].SetType(form[x][y].GetType());
			form[x][y].SetType(tmp);
		}
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			auto t = form[x][y].GetType();
			form[x][y].SetType(form[ x][3-y].GetType());
			form[ x][3-y].SetType(t);
		}
	}
}

void Forms::SetType(Forms t)								///ustalenie typu na podstawie typu formy		
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			form[x][y].SetType(t.form[x][y].GetType());
		}
	}
}




void Forms::draw(sf::RenderTarget & target, sf::RenderStates states) const				///rysowanie
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (form[x][y].GetType() != Blocktype::empty)
				target.draw(form[x][y]);
		}
	}
}



