#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

#include <iostream>

#define MAX_LICZBA_POL 3

class Tryb
{
private:
	int wybrane;
	sf::Font font;
	sf::Text menu_txt[MAX_LICZBA_POL];

	sf::Font fontv2;
	sf::Text Tytol;

public:
	Tryb(float width, float height);
	//Menu();
	virtual ~Tryb();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getWybrane();   //do wybierania pól
};
