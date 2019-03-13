#pragma once
#include <SFML\Graphics.hpp>
#include "Block.h"
#include "Blocktype.h"
#include <random>
class Forms: public sf::Drawable
{
public:
	///domyslny konstruktor form
	Forms()=default;
	///destruktor											
	~Forms();			
	///konstruktor formy										
	Forms(float xBoard, float yBoard, float s);					

	void SetPosition(sf::Vector2i);
	const sf::Vector2i GetPosition() { return position; }			///zwrocenie pozycji

	void SetBlock(int, int, Block);
	const Blocktype GetBlock(int x, int y) const					///zwrocenie typu bloku
	{
		return form[x][y].GetType();
	}

	void SetBoard(float, float, float);

	void SetType(int x, int y, Blocktype type)						///ustalenie typu bloku
	{ form[x][y].SetType(type); }

	void SetType(Blocktype t[4][4]);
	
	void Rotateleft();
	void Rotateright();

	void SetType(Forms t);

	// Inherited via Drawable
	virtual void draw(sf::RenderTarget &, sf::RenderStates) const override;

protected:
	///tablica blokow 4x4
	Block form[4][4];
	///pozycja
	sf::Vector2i position;
	///obrazek
	sf::Sprite kwadrat;
	///wspolrzedna x
	int xBoard;
	///wspolrzedna y
	int yBoard;
	///rozmiar bloku
	float Blocksize;

	
	
};