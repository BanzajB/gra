#include "Pocisk.h"

Pocisk::Pocisk()
{

}

Pocisk::Pocisk(sf::Texture* texture,float poz_x, float poz_y, float dx, float dy, float speed)
{
	this->shape.setTexture(*texture);  //ustawiamy teksturê na sprita
	
	this->shape.scale(0.1f, 0.05f);
	
	this->shape.setPosition(poz_x, poz_y);

	this->kierunek.x = dx;
	this->kierunek.y = dy;
	this->movementSpeed = speed;
}

Pocisk:: ~Pocisk()
{

}

//Accesor

const sf::FloatRect Pocisk::granice() const
{
	return this->shape.getGlobalBounds();
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

