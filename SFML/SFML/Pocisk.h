#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

#include <iostream>


class Pocisk
{
private:
	sf::Sprite shape; // by nie ³adowaæ za ka¿dym raze mtekstury pocisku
	

	sf::Vector2f kierunek;
	float movementSpeed;


public:
	Pocisk();
	Pocisk(sf::Texture& texture, float dx, float dy, float speed); // zmienne lokalne
	virtual ~Pocisk();

	void update();
	void render(sf::RenderTarget* target);
};

