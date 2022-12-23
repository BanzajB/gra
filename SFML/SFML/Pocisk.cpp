#include "Pocisk.h"

Pocisk::Pocisk()
{

}

Pocisk::Pocisk(sf::Texture& texture, float dx, float dy, float speed)
{
	this->shape.setTexture(texture);  //ustawiamy teksturê na sprita
	this->kierunek.x = dx;
	this->kierunek.y = dy;
	this->movementSpeed = speed;
}

Pocisk:: ~Pocisk()
{

}

void Pocisk::update()
{
	// Ruch przez mno¿enie wektora
	this->shape.move(this->movementSpeed * this->kierunek);
}

void Pocisk::render(sf::RenderTarget*target)
{
	target->draw(this->shape);
}

