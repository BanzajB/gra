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
	Pocisk(sf::Texture* texture, float poz_x, float poz_y, float dx, float dy, float speed); // zmienne lokalne 
	virtual ~Pocisk();

	//Accesor                     by dostaæ siê do sekcji private ( funkcja get(granice))
	const sf::FloatRect granice() const;

	void update();
	void render(sf::RenderTarget* target);
};

