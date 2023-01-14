#pragma once

#include<time.h>
#include<map>
#include<string>
#include<sstream>
#include"gracz.h"
#include"Pocisk.h"
#include"Przeciwnik.h"
#include"Menu.h"
#include"Exit.h"


// Okno jako klasa / game engine
//tworzymy funkcje

using namespace sf;


class Gra
{
private:
									//Private functions
	//void initVariable();

	void initWindow(); 
	

	//Variables
							//Okno jako pointer
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Resources  Pociski
	std::map<std::string, Texture*> textures;    //alokacja pami�ci, mapuje dwie cechy razem (dla ka�dego stringa daje tekstur�)
	std::vector<Pocisk*> pocisk;

	//GUI
	Font czcionka;
	Font czcionkav2;  //ta bez linii
	Text Punkty_txt;

	Text GameOver_txt;


	//T�o
	sf::Texture Tlo;
	sf::Sprite TloSprite;

	//Punktacja
	unsigned points;

	//Menu

	//bool wcisk();
	int pozycja = 0;
	Menu*menu;

	//Help
	Text Help_txt;

	//Exit
	Exit* exit;
						//Gracz (wska�nik)
	gracz* player;

					// GUI gracza -  �ycie
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarTlo;


	//Przeciwnicy

	float spawnTimer;
	float spawnTimerMax;
	std::vector<Przeciwnik*> przeciwnicy;    //wektor by mie� kilku przeciwnik�w

	
	

	void initPlayer();
	void initTextures();
	void initGUI();
	void initTlo();
	void initPunktacja();
	void initMenu();

	void initPrzeciwnicy();


public:
									//Konstruktor  / Destruktor
	Gra();
	virtual ~Gra();

	//Accessors / U�ywane do pobierane danych z privte
	//const bool running() const;


	//Funkcje

	
	void run();

	void pollEvents();
	//void cooldown(int seconds);
	void updateEvents();
	void updateInput();

	void updateGUI();
	void updateTlo();
	void updateKolizja();

	void updatePociski();
	void updatePrzeciwnicy();
	void update();

	
	void renderMenu();
	void renderExit();

	void renderGUI();
	void renderTlo();
	void render();
};

