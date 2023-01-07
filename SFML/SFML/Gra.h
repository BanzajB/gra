#pragma once

#include<time.h>
#include<map>
#include<string>
#include<sstream>
#include"gracz.h"
#include"Pocisk.h"
#include"Przeciwnik.h"
#include"Menu.h"


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

	//Resources
	std::map<std::string, Texture*> textures;    //alokacja pamiêci, mapuje dwie cechy razem (dla ka¿dego stringa daje teksturê)
	std::vector<Pocisk*> pocisk;

	//GUI
	Font czcionka;
	Text Punkty_txt;

	Text GameOver_txt;


	//T³o
	sf::Texture Tlo;
	sf::Sprite TloSprite;

	//Punktacja
	unsigned points;

	//Menu

	int pozycja = 0;
	Menu* menu;

						//Gracz (wskaŸnik)
	gracz* player;

					// GUI gracza -  ¿ycie
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarTlo;


	//Przeciwnicy

	float spawnTimer;
	float spawnTimerMax;
	std::vector<Przeciwnik*> przeciwnicy;    //wektor by mieæ kilku przeciwników

	
	

	void initPlayer();
	void initTextures();
	void initGUI();
	void initTlo();
	void initPunktacja();

	void initPrzeciwnicy();


public:
									//Konstruktor  / Destruktor
	Gra();
	virtual ~Gra();

	//Accessors / U¿ywane do pobierane danych z privte
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

	void renderGUI();
	void renderTlo();
	void render();
};

