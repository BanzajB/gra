#include "Przeciwnik.h"



void Przeciwnik::initVariables()
{
	this->licznikPunktów = rand() % 8 + 3;           //rand() % 8 wartoœci od 0-7;           wartoœci miêdzy 3 a 10
	this-> type          = 0; 
	this->speed          = static_cast<float>(this->licznikPunktów/2);        //rzutoawanie;   speed jest float wiêc musimy wrtoœæ z licznika punktów zrzutowaæ na float
	this-> hpMax         = static_cast<int>(this->licznikPunktów);
	this-> hp            = this->hpMax;                                   //aktualne hp przeciwnika
	this-> damage        = this->licznikPunktów;
	this-> points        = this->licznikPunktów /3;                  //liczba punktów co siê dotaje po zniszeczniu przeciwnika
}

void Przeciwnik::initKsztalt()
{
	this->ksztalt.setRadius(this->licznikPunktów *3);                           //wielkoœæ przeciwników
	this->ksztalt.setPointCount(this->licznikPunktów);                          // kszta³t w zale¿noœæi od iloœci k¹tów
	this->ksztalt.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));                  // random color
}

Przeciwnik::Przeciwnik(float poz_x, float poz_y)
{
	
	this->initVariables();
	this->initKsztalt();
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

const int& Przeciwnik::getPunkty() const
{
	return this->points;
}

const int& Przeciwnik::getDamage() const
{
	return this->damage;
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
