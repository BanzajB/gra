#include "gracz.h"

void gracz::initTexture()
{
	//Loud a teksture z pliku
	if (!this->texture.loadFromFile("textures/ship.png"))
	{
		std::cout << " nie uda³o za³adowaæ tekstury z pliku \n" << std::endl;
	}
}

void gracz::initSprite()
{
	//Set a tekstura do sprajta
	this->sprite.setTexture(this->texture); //kiedy u¿ywamy rectangleShape mo¿e byæ potrzeba u¿ycia & przed thiss w referencji

	//ustawiamy wielkoœæ statku (sprita)
	this->sprite.scale(0.1f, 0.1f);

}

gracz::gracz()
{
	this->movementSpeed = 3.f;

	this->initTexture();
	this->initSprite();
}

gracz::~gracz()
{
}

const sf::Vector2f& gracz::getPozycja() const   //pobieramy pozycjê statku
{
	return this->sprite.getPosition();
}


void gracz::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed *dirX, this->movementSpeed *dirY);
}

//Funkcje


void gracz::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
