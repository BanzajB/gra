#include "Przeciwnik.h"

void Przeciwnik::initKsztalt()
{
	this->ksztalt.setRadius(rand() % 20 + 20);
	this->ksztalt.setPointCount(rand() % 20 + 3);
	this->ksztalt.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

void Przeciwnik::initVariables()
{
	this-> type     = 0;
	this->speed     = 2.f;
	this-> hpMax    = 10;
	this-> hp       = 0;
	this-> damage   = 1;
	this-> points   = 5;
}

Przeciwnik::Przeciwnik(float poz_x, float poz_y)
{
	this->initKsztalt();
	this->initVariables();
	this->ksztalt.setPosition(poz_x, poz_y);
	
}

Przeciwnik::~Przeciwnik()
{
}

//Accessor
const sf::FloatRect Przeciwnik::getObrys() const
{
	return this->ksztalt.getGlobalBounds();
}


//F
void Przeciwnik::update()
{
	this->ksztalt.move(0.f, this->speed);
}

void Przeciwnik::render(sf::RenderTarget* target)
{
	target->draw(this->ksztalt);
}
