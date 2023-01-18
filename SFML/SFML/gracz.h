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


	int hp;
	int hpMax;



					//PrivF

	void initVariables();
	void initTexture();
	void initSprite();
	//void initPsition();


public:

	gracz();
	virtual ~gracz();

	//Accessor
	const sf::Vector2f& getPozycja() const;
	const sf::FloatRect getObrys() const;

	const int& getHp() const;
	const int& getHpMax() const;

	


	//Modifiers
	void setPozycja(const sf::Vector2f poz);
	void setPozycja(const float x, const float y);

	void setHp(const int hp);
	void loseHp(const int value);

	void setReload(const float a);
	void setSpeed(const float speed);


					//Funkcje
	void move(const float dirX, const float dirY);

	const bool resetReload();

	void updateReload();
	void update();

	//do renderowania sprita
	void render(sf::RenderTarget& target);
};

