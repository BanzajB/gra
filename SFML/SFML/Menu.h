#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

#include <iostream>

#define MAX_LICZBA_POL 4

class Menu
{
private:
	int wybrane;
	sf::Font font;
	sf::Text menu_txt[MAX_LICZBA_POL];

	sf::Font fontv2;
	sf::Text Tytol;

public:
	Menu(float width, float height);
	//Menu();
	virtual ~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int getWybrane();   //do wybierania pól
};



































//class Menu
//{
//private:
//
//	sf::Font czcionka;
//	sf::Text Menu_txt;
//
//	sf::RectangleShape ramka;
//
//	std::vector<std::string> pola_string;
//	std::vector<sf::Text> pola_txt;
//	sf::Text &polaOpcji;
//
//	int aktualnie_wybrane;
//
//	void initFont();
//	void initText();
//
//	void pola();
//	void Ramka();
//
//	
//
//public:
//	Menu(float width, float height);
//
//	virtual ~Menu();
//
//	//int getPozycja();
//};
