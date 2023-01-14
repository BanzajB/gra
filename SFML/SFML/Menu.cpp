#include "Menu.h"

Menu::Menu(float width, float height)
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
	this->Tytol.setCharacterSize(120);
	this->Tytol.setFillColor(sf::Color(4, 225, 247, 200));
	this->Tytol.setString(" SPACE \nSHOOTER");
	this->Tytol.setPosition(sf::Vector2f(width / 10, height /3));

	this->menu_txt[0].setFont(font);
	this->menu_txt[0].setFillColor(sf::Color::Yellow);
	this->menu_txt[0].setString("==GRAJ==");
	this->menu_txt[0].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL +1) * 1));

	this->menu_txt[1].setFont(font);
	this->menu_txt[1].setFillColor(sf::Color::White);
	this->menu_txt[1].setString("==OPCJE==");
	this->menu_txt[1].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 2));

	this->menu_txt[2].setFont(font);
	this->menu_txt[2].setFillColor(sf::Color::White);
	this->menu_txt[2].setString("==WYJSCIE==");
	this->menu_txt[2].setPosition(sf::Vector2f(width / 1.5, height / (MAX_LICZBA_POL + 1) * 3));

	wybrane = 0;
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	window.draw(Tytol);

	for (int i = 0; i < MAX_LICZBA_POL; i++)
	{
		window.draw(menu_txt[i]);
	}
}

void Menu::MoveUp()
{
	if (wybrane - 1 >= 0)
	{
		menu_txt[wybrane].setFillColor(sf::Color::White);
		wybrane--;
		menu_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown()
{
	if (wybrane + 1 < MAX_LICZBA_POL)
	{
		menu_txt[wybrane].setFillColor(sf::Color::White);
		wybrane++;
		menu_txt[wybrane].setFillColor(sf::Color::Yellow);
	}
}

int Menu::getWybrane()
{
	return wybrane;
}





















//void Menu::initFont()
//{
//	if (!this->czcionka.loadFromFile("textures/pixelmix.ttf"))
//		std::cout << "ERROR: Czcionka do menu niezaladowana" << std::endl;
//
//}
//
//void Menu::initText()
//{
//	this->Menu_txt.setFont(this->czcionka);
//	this->Menu_txt.setCharacterSize(50);
//	this->Menu_txt.setFillColor(sf::Color::Yellow);
//	this->Menu_txt.setString("Menu");
//
//	this->Menu_txt.setPosition(400, 400);
//
//}
//
//void Menu::pola()
//{
//	this->pola_string = { "START GAME", "OPTIONS", "EXIT" };
//
//	for (unsigned int i = 0; i < pola_string.size(); i++)
//	{
//		//sf::Text polaOpcji(pola_string[i], czcionka, 30);
//		polaOpcji.setString(pola_string[i]);
//		polaOpcji.setFont(czcionka);
//		polaOpcji.setCharacterSize(30);
//
//		polaOpcji.setPosition(400, 150 + i * 50);       //po³o¿enie okienek
//		pola_txt.push_back(polaOpcji);
//	}
//}
//
//void Menu::Ramka()
//{
//	ramka.setSize(sf::Vector2f(250, 50));
//	ramka.setFillColor(sf::Color::Transparent);
//	ramka.setOutlineThickness(5);
//	ramka.setOutlineColor(sf::Color(254, 212, 101, 0.28));
//
//}
//
////Menu::Menu(float width, float height)
////{
////
////}
//
//Menu::~Menu()
//{
//}
//
//int Menu::getPozycja()
//{
//	return ;
//}

