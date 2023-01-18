#include "Pilk.h"

Plik::Plik(float width, float height)
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
	this->Tytol.setCharacterSize(70);
	this->Tytol.setFillColor(sf::Color(4, 225, 247, 200));
	this->Tytol.setString(" ZAPIS/WCZYTANIE \n       Z PLIKU");
	this->Tytol.setPosition(sf::Vector2f(width / 10, height / 3));



	this->plik_txt[0].setFont(font);
	this->plik_txt[0].setFillColor(sf::Color::Yellow);
	this->plik_txt[0].setString("==ZAPIS 1 ==");
	this->plik_txt[0].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 1));

	this->plik_txt[1].setFont(font);
	this->plik_txt[1].setFillColor(sf::Color::White);
	this->plik_txt[1].setString("==ZAPIS 2 ==");
	this->plik_txt[1].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 2));

	this->plik_txt[2].setFont(font);
	this->plik_txt[2].setFillColor(sf::Color::White);
	this->plik_txt[2].setString("==ZAPIS 3 ==");
	this->plik_txt[2].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 3));

	wybrane = 0;
}

Plik::~Plik()
{

}

void Plik::draw(sf::RenderWindow& window)
{
	window.draw(Tytol);

	for (int i = 0; i < MAX_LICZBA_POL; i++)
	{
		window.draw(plik_txt[i]);
	}
}

void Plik::MoveUp()
{
	if (wybrane - 1 >= 0)
	{
		plik_txt[wybrane].setFillColor(sf::Color::White);
		wybrane--;
		plik_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

void Plik::MoveDown()
{
	if (wybrane + 1 < MAX_LICZBA_POL)
	{
		plik_txt[wybrane].setFillColor(sf::Color::White);
		wybrane++;
		plik_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

int Plik::getWybrane()
{
	return wybrane;
}

