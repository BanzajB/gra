#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

#include <iostream>

#define MAX_LICZBA_POL 2

class Exit
{
private:
	int wybrane;
	sf::Font font;
	sf::Text exit_txt[MAX_LICZBA_POL];

public:
	Exit(float width, float height);
	//Menu();
	virtual ~Exit();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int getWybrane();   //do wybierania pól
};

