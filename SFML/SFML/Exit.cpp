#include "Exit.h"

Exit::Exit(float width, float height)
{
	if (!font.loadFromFile("textures/pixelmix.ttf"))
	{
		std::cout << " ERROR: Nie laduje sie czcionka exit " << std::endl;
	}

	this->exit_txt[0].setFont(font);
	this->exit_txt[0].setFillColor(sf::Color::Yellow);
	this->exit_txt[0].setString("==GRAJ DALEJ==");
	this->exit_txt[0].setPosition(sf::Vector2f(width / (MAX_LICZBA_POL + 1) * 1 -100 , height / 2));

	this->exit_txt[1].setFont(font);
	this->exit_txt[1].setFillColor(sf::Color::White);
	this->exit_txt[1].setString("==WYJDZ==");
	this->exit_txt[1].setPosition(sf::Vector2f(width / (MAX_LICZBA_POL + 1) * 2 -100 , height / 2));

	

	wybrane = 0;
}

Exit::~Exit()
{

}

void Exit::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POL; i++)
	{
		window.draw(exit_txt[i]);
	}
}

void Exit::MoveUp()
{
	if (wybrane - 1 >= 0)
	{
		exit_txt[wybrane].setFillColor(sf::Color::White);
		wybrane--;
		exit_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

void Exit::MoveDown()
{
	if (wybrane + 1 < MAX_LICZBA_POL)
	{
		exit_txt[wybrane].setFillColor(sf::Color::White);
		wybrane++;
		exit_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

int Exit::getWybrane()
{
	return wybrane;
}