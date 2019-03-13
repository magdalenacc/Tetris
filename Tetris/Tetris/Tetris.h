#pragma once
#include <SFML\Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Forms.h"
#include "Board.h"
#include "Blocktype.h"
#include <vector>
#include <random>
#define WIDTH 14
#define HEIGHT	20

class Tetris : public sf::Drawable 
{
public:
	Tetris();
	~Tetris();
	void loadFromFile();
	void Update(float dt);
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	void KeybordEvents(sf::Event&);

	void respawnblock();

	int rand();

	void goleft();
	void gorigth();

	bool isEmpty();
	
	bool canrotate();
	void checkBoard();
	bool collide();

protected:
	///lista form
	std::vector<Forms> listform;				

	///wynik
	int Score;
	///x - szerokosc tablicy
	int xSize;									
	///y - wysokosc tablicy
	int ySize;									
	///wspolrzednia x polozenia na tablicy
	int xBoard;
	///wspolrzednia y polozenia na tablicy
	int yBoard;									
	///rozmiar formy(4)
	int BlockSize;								
	///czcionka
	sf::Font font;								
	
	void setlevel(int);							

	///typ bloku (kolor)
	Blocktype typeblock;
	///predkosc spadania
	float speed;
	///level
	int level;	
	///flaga wskazujaca, czy przegralismy czy nie
	bool gameover;	
	///zmienna pomocnicza
	float timer;								
	///flaga wskazujaca, czy wcisnelismy strzalke w dol czy nie
	bool down;									
	///silnik liczb losowych
	std::default_random_engine e;	
	///biezacy klocek
	Forms FallBlock;
	///tablica (plansza)
	Board tab;	
};
									