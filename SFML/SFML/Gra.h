#pragma once

#include<map>
#include"gracz.h"
#include"Pocisk.h"


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


						//Gracz (wskaŸnik)
	gracz* player;


	void initPlayer();
	void initTextures();


public:
									//Konstruktor  / Destruktor
	Gra();
	virtual ~Gra();

	//Accessors / U¿ywane do pobierane danych z privte
	//const bool running() const;


	//Funkcje

	
	void run();
	void pollEvents();
	void updateEvents();
	void updateInput();
	void updatePociski();
	void update();
	void render();
};

