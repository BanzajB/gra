#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

#include <iostream>

class gracz
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

					//PrivF

	void initTexture();
	void initSprite();

public:

	gracz();
	virtual ~gracz();


					//Funkcje
	void move(const float dirX, const float dirY);

	void update();

	//do renderowania sprita
	void render(sf::RenderTarget& target);
};

