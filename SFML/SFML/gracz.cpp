#include "gracz.h"

void gracz::initVariables()
{
	this->movementSpeed = 3.f;

	this->reloadCooldownMax = 20.f;
	this->reloadCooldown = this->reloadCooldownMax;

	this->hpMax = 50;
	this-> hp = this->hpMax;

}

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
	
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

gracz::~gracz()
{
}

const int& gracz::getHp() const
{
	return hp;
}

const int& gracz::getHpMax() const
{
	return this->hpMax;
}

const sf::Vector2f& gracz::getPozycja() const										 //pobieramy pozycjê statku
{
	return this->sprite.getPosition();
}


void gracz::move(const float dirX, const float dirY)								//ruch
{
	this->sprite.move(this->movementSpeed *dirX, this->movementSpeed *dirY);
}

const sf::FloatRect gracz::getObrys() const										//granice sprita
{
	return this->sprite.getGlobalBounds();
}

const bool gracz::resetReload()													//prze³adowanie 
{
	if (this->reloadCooldown >= this->reloadCooldownMax)
	{
		this->reloadCooldown = 0.f;
		return true;
	}

	return false;
}

void gracz::updateReload()
{
	if (this->reloadCooldown < this->reloadCooldownMax)
		this->reloadCooldown += 1.f;
}

//const bool gracz::resetReload()
//{
//	return false;
//}


//Modifiers


void gracz::setPozycja(const sf::Vector2f poz)                            //Pozycja
{
	this->sprite.setPosition(poz);
}

void gracz::setPozycja(const float x, const float y)						//Pozycja drugi sposób
{
	this->sprite.setPosition(x, y);
}




void gracz::setHp(const int hp)
{
	this->hp = hp;
}

void gracz::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}


void gracz::update()
{
	this->updateReload();
}

//Funkcje


void gracz::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}




