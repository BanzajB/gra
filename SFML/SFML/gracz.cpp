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
}

gracz::gracz()
{
	this->initTexture();
	this->initSprite();
}

gracz::~gracz()
{
}


			//Funkcje
void gracz::update()
{
}

void gracz::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
