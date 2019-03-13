#include "Tetris.h"
#include "game.h"
Tetris::Tetris() :xSize(WIDTH), ySize(HEIGHT), BlockSize(30),
					xBoard(0), yBoard(0), tab(0, 0, 30),
					gameover(false), Score(0),
					speed(0.5),level(0), down(false)
{

	loadFromFile();
	FallBlock.SetBoard(xBoard,yBoard,BlockSize);
	respawnblock();

}

Tetris::~Tetris()
{
}

void Tetris::loadFromFile()									///zaladowanie form z pliku oraz utworzenie listy form
{
	std::ifstream File;
	File.open("forms.txt");
	if (!File.good())
	{
		std::cout << "nie mozna otworzyc pliku!\n";
	}
	
	while (!File.eof())
	{
		Blocktype ksztalt[4][4];
		int i;

		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				File >> i;
				ksztalt[x][y]=(Blocktype)i;
			}
		}

		Forms b(xBoard, yBoard, BlockSize);
		b.SetType(ksztalt);
		listform.push_back(b);
		
	}
	File.close();
}

void Tetris::Update(float dt)										///update gry
{ float speed2;
	if (down)
	{
		
		speed2 = 0 ;
	}
	else
	{
		speed2 = speed;
	}
		timer += dt;

		if (timer >= speed2 && !gameover)
		{
			sf::Vector2i poz = FallBlock.GetPosition();
			bool canfall = true;
			for (int x = 0; x < 4; x++)
			{
				for (int y = 0; y < 4; y++)
				{
					if (FallBlock.GetBlock(x, y) != Blocktype::empty)
					{
						auto v = poz;
						v.x += (x - 1); v.y += y - 1;

						if (tab.Gettype(v.x, v.y + 1) != Blocktype::empty)
						{
							canfall = false;
						}
					}
				}
			}

			if (canfall)
				FallBlock.SetPosition(sf::Vector2i(FallBlock.GetPosition().x, FallBlock.GetPosition().y + 1));
			else
				{
					tab.Settype(FallBlock);//przypisywanie do planszy
					if (isEmpty())
					{
						
						respawnblock();
						down = false;
						checkBoard();
					}
					else
					{
						gameover = true;

						Game::Instance().LoadScene("gameover");

					}
				}
			timer = 0;
		}
}

void Tetris::draw(sf::RenderTarget & t, sf::RenderStates states) const						///rysowanie tablicy i blokow
{
	
	t.draw(tab);
	t.draw(FallBlock);

}

void Tetris::KeybordEvents(sf::Event &e)					///obsluga klawiszy
{
	if (e.type==sf::Event::KeyReleased)
	{
		if (e.key.code == sf::Keyboard::A)
		{
			if(canrotate())
				FallBlock.Rotateleft();
		}
		if (e.key.code == sf::Keyboard::D)
		{
			if(canrotate())
				FallBlock.Rotateright();
		}
		if (e.key.code == sf::Keyboard::Right)
		{
			gorigth();
			if(collide())
				goleft();
		}

		if (e.key.code == sf::Keyboard::Left)
		{
			goleft();
			if (collide())
				gorigth();
		}	

		if (e.key.code == sf::Keyboard::Down)
		{
			down = true;
		}
	}

}

bool Tetris::collide()												///sprawdzanie, czy wystapila kolizja
{
	for (size_t y = 0; y < 4; y++)
	{
		for (size_t x = 0; x < 4; x++)
		{
			if (FallBlock.GetBlock(x, y) != Blocktype::empty)
			{
				auto pos = FallBlock.GetPosition();

				if (pos.x - 1 + x > xSize)
					return true;

				if (pos.y - 1 + y> ySize)
					return true;

				if (pos.x - 1 + x < 0)
					return true;

				if (pos.y - 1 + y < 0)
					return true;

				if (tab.Gettype(pos.x - 1 + x, pos.y - 1 + y) != Blocktype::empty)
					return true;
			}
		}
	}

	return false;
}


void Tetris::setlevel(int score)					///ustalanie poziomu
{
	for (int i = 0; i < score; i++)
	{
		if (score > 3 * i)
		{
			level++;
			speed -= (speed / 10);
		}
	}
}


void Tetris::respawnblock()											///losowanie nowego bloku
{
	int t;
	t = rand();
	FallBlock.SetType(listform[t]);
	
	FallBlock.SetPosition(sf::Vector2i(xSize / 2, 0));
}

int Tetris::rand()															///funkcja losujaca
{
	std::uniform_int_distribution<> uid3{ 0, (int)listform.size()-1 };
	
	return uid3(e);
}

void Tetris::goleft()																							///przesuniecie bloku w lewo
{
		FallBlock.SetPosition(sf::Vector2i(FallBlock.GetPosition().x-1, FallBlock.GetPosition().y));

}

void Tetris::gorigth()	///przesuniecie bloku w prawo
{
		FallBlock.SetPosition(sf::Vector2i(FallBlock.GetPosition().x +1, FallBlock.GetPosition().y));
}
	
bool Tetris::isEmpty()				///sprawdzanie, czy pole jest puste
{
	bool empty = true;
	sf::Vector2i v=sf::Vector2i(WIDTH / 2, 0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tab.Gettype(v.x+i, v.y+j) != Blocktype::empty)
				empty = false;
		}
	}
	return empty;
}

void Tetris::checkBoard()										///sprawdzanie tablicy, usuwanie linii, ustawienie nowego poziomu
{
	for (size_t y = ySize-2; y != 0; y--)
	{
		bool line = true;

		for (size_t x = 1; x < xSize -1; x++)
		{
			if (tab.Gettype(x, y) == Blocktype::empty)
			{
				line = false;
			}
		}

		if (line)
		{
			for (int y2 = y-1; y2 != 0; y2--)
			{
				for (size_t x2 = 1; x2 < xSize-1; x2++)
				{
					tab.Settype(sf::Vector2i(x2, y2 + 1), tab.Gettype(x2, y2));
					
				}
			}
			Score++;
			setlevel(Score);
		}
	}
}



bool Tetris::canrotate()										///sprawdzenie czy mo¿emy siê obrocic
{
	sf::Vector2i poz = FallBlock.GetPosition();
	bool can = true;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (FallBlock.GetBlock(x, y) != Blocktype::empty)
			{
				auto v = poz;
				v.x += (x - 1); v.y += y - 1;

				if (tab.Gettype(v.x -1, v.y) == Blocktype::grey 
					|| tab.Gettype(v.x+1,v.y) == Blocktype::grey)
				{
					can = false;
				}
			}
		}
	}

	return can;
}

