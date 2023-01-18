#pragma once

#include<time.h>
#include<map>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>

#include"gracz.h"
#include"Pocisk.h"
#include"Przeciwnik.h"
#include"Menu.h"
#include"Exit.h"
#include"Opcje.h"
#include"Tryb.h"
#include"Pilk.h"


// Okno jako klasa / game engine
//tworzymy funkcje

using namespace sf;

const int MAX_USERS = 3;

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
	std::map<std::string, Texture*> textures;    //alokacja pamiêci, mapuje dwie cechy razem (dla ka¿dego stringa daje teksturê)
	std::vector<Pocisk*> pocisk;

	//GUI
	Font czcionka;
	Font czcionkav2;  //ta bez linii
	Text Punkty_txt;

	Text GameOver_txt;


	//T³o
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

	//Opcje
	Opcje* opcje;
				



	//Plik
	Plik* plik;

	bool flag;


	//struktura

	struct User {             
		std::string name;
		unsigned pkt;
		int Hp;
		//int pozm;
	};

	User users[MAX_USERS];

	//Trudnosc
	Tryb* tryb;
	int poziom;
	

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
	void initMenu();

	void initPrzeciwnicy();


public:
									//Konstruktor  / Destruktor
	Gra();
	virtual ~Gra();

	//Accessors / U¿ywane do pobierane danych z privte
	//const bool running() const;


	//Funkcje


	//Plik
	void zapisStruct(int nr);
	void pobranieStruct(int nr);

	void zapis(User users[], int nr, std::string file );
	void odczyt(User users[], int nr, std::string file);
	
	void run();

	void pollEvents();
	//void cooldown(int seconds);


	//update
	void updateEvents();
	void updateInput();

	void updateGUI();
	void updateTlo();
	void updateKolizja();

	void updatePociski();
	void updatePrzeciwnicy();

	void updateMenu();
	void updateExit();
	void updateOpcje();
	void updatePlik();
	void updateTryb();

	void update();

	//render
	void renderMenu();
	void renderHelp();
	void renderExit();
	void renderOpcje();
	void renderPlik();
	void renderTryb();

	void renderGUI();
	void renderTlo();
	void render();
};

