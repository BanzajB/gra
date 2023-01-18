#include "Opcje.h"

Opcje::Opcje(float width, float height)
{
	if (!font.loadFromFile("textures/pixelmix.ttf"))
	{
		std::cout << " ERROR: Nie laduje sie czcionka Opcje " << std::endl;
	}

	if (!fontv2.loadFromFile("textures/pixelsix14.ttf"))
	{
		std::cout << " ERROR: Nie laduje sie czcionka Opcje " << std::endl;
	}


	this->Tytol.setFont(fontv2);
	this->Tytol.setCharacterSize(120);
	this->Tytol.setFillColor(sf::Color(4, 225, 247, 200));
	this->Tytol.setString(" OPCJE");
	this->Tytol.setPosition(sf::Vector2f(width / 10, height / 3));



	this->opcje_txt[0].setFont(font);
	this->opcje_txt[0].setFillColor(sf::Color::Yellow);
	this->opcje_txt[0].setString("==ZAPISZ==");
	this->opcje_txt[0].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 1));

	this->opcje_txt[1].setFont(font);
	this->opcje_txt[1].setFillColor(sf::Color::White);
	this->opcje_txt[1].setString("==WCZYTAJ==");
	this->opcje_txt[1].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 2));

	this->opcje_txt[2].setFont(font);
	this->opcje_txt[2].setFillColor(sf::Color::White);
	this->opcje_txt[2].setString("==Trudnosc==");
	this->opcje_txt[2].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 3));

	wybrane = 0;
}

Opcje::~Opcje()
{

}

void Opcje::draw(sf::RenderWindow& window)
{
	window.draw(Tytol);

	for (int i = 0; i < MAX_LICZBA_POL; i++)
	{
		window.draw(opcje_txt[i]);
	}
}

void Opcje::MoveUp()
{
	if (wybrane - 1 >= 0)
	{
		opcje_txt[wybrane].setFillColor(sf::Color::White);
		wybrane--;
		opcje_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

void Opcje::MoveDown()
{
	if (wybrane + 1 < MAX_LICZBA_POL)
	{
		opcje_txt[wybrane].setFillColor(sf::Color::White);
		wybrane++;
		opcje_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

int Opcje::getWybrane()
{
	return wybrane;
}

