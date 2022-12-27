#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>

#include <iostream>

class Przeciwnik
{
private:
	sf::CircleShape ksztalt;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initKsztalt();
	void initVariables();

public:
	Przeciwnik(float poz_x, float poz_y);
	virtual ~Przeciwnik();

	// Accessor
	const sf::FloatRect getObrys() const;

	//F
	void update();
	void render(sf::RenderTarget* target);
};

