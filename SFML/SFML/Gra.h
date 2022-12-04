#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

// Okno jako klasa / game engine
//tworzymy funkcje

using namespace sf;


class Gra
{
private:
	//Private functions
	void initVariable();
	void initWindow();
	//Variables
		//Okno jako pointer
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;


public:
	//Konstruktor  / Destruktor
	Gra();
	virtual ~Gra();

	//Accessors / U¿ywane do pobierane danych z privte
	const bool running() const;


	//Funkcje
	void pollEvents();
	void update();
	void render();
};

