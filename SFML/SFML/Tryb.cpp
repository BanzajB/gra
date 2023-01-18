#include "Tryb.h"

Tryb::Tryb(float width, float height)
{
	if (!font.loadFromFile("textures/pixelmix.ttf"))
	{
		std::cout << " ERROR: Nie laduje sie czcionka menu " << std::endl;
	}

	if (!fontv2.loadFromFile("textures/pixelsix14.ttf"))
	{
		std::cout << " ERROR: Nie laduje sie czcionka menu " << std::endl;
	}


	this->Tytol.setFont(fontv2);
	this->Tytol.setCharacterSize(70);
	this->Tytol.setFillColor(sf::Color(4, 225, 247, 200));
	this->Tytol.setString(" Wybierz poziom trudnosci");
	this->Tytol.setPosition(sf::Vector2f(width / 10, height / 7));



	this->menu_txt[0].setFont(font);
	this->menu_txt[0].setFillColor(sf::Color::Yellow);
	this->menu_txt[0].setString("==Latwy==");
	this->menu_txt[0].setPosition(sf::Vector2f(width / (MAX_LICZBA_POL + 1) * 1 - 100, height /2 ));

	this->menu_txt[1].setFont(font);
	this->menu_txt[1].setFillColor(sf::Color::White);
	this->menu_txt[1].setString("==Sredni==");
	this->menu_txt[1].setPosition(sf::Vector2f(width / (MAX_LICZBA_POL + 1) * 2 - 100, height / 2));

	this->menu_txt[2].setFont(font);
	this->menu_txt[2].setFillColor(sf::Color::White);
	this->menu_txt[2].setString("==Trudny==");
	this->menu_txt[2].setPosition(sf::Vector2f(width / (MAX_LICZBA_POL + 1) * 3 - 100, height / 2));


	wybrane = 0;
}

Tryb::~Tryb()
{

}

void Tryb::draw(sf::RenderWindow& window)
{
	window.draw(Tytol);

	for (int i = 0; i < MAX_LICZBA_POL; i++)
	{
		window.draw(menu_txt[i]);
	}
}

void Tryb::MoveUp()
{
	if (wybrane - 1 >= 0)
	{
		menu_txt[wybrane].setFillColor(sf::Color::White);
		wybrane--;
		menu_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

void Tryb::MoveDown()
{
	if (wybrane + 1 < MAX_LICZBA_POL)
	{
		menu_txt[wybrane].setFillColor(sf::Color::White);
		wybrane++;
		menu_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

int Tryb::getWybrane()
{
	return wybrane;
}

