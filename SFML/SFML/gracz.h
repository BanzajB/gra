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

	float reloadCooldown;
	float reloadCooldownMax;

					//PrivF

	void initVariables();
	void initTexture();
	void initSprite();

public:

	gracz();
	virtual ~gracz();

	//Accessor
	const sf::Vector2f& getPozycja() const;
	const sf::FloatRect getObrys() const;


					//Funkcje
	void move(const float dirX, const float dirY);

	const bool resetReload();

	void updateReload();
	void update();

	//do renderowania sprita
	void render(sf::RenderTarget& target);
};

