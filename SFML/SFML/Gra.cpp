#include "Gra.h"


using namespace sf;
//Tutaj deklarujemy funkcje


// Prywatne Funkcje
/*void Gra::initVariable()
{
	this->window = nullptr;
}
*/

void Gra::initWindow()
{
	//zamiast na twardo wymiary w RenderWidndow to mamy w zmiennych
	this->videoMode.height = 1000;
	this->videoMode.width = 1400;

	this ->window = new RenderWindow(this->videoMode, "Space shootage");

	//ograniczmy iloœæ klatek
	this->window->setFramerateLimit(144);

	//wy³¹czamy vsync(synchr. pionow¹)
	this->window->setVerticalSyncEnabled(false);

}



void Gra::initPlayer()
{
	this->player = new gracz();
}

void Gra::initTextures()
{
	this->textures["POCISK"] = new Texture();
	this->textures["POCISK"]->loadFromFile("textures/laser.png");
}

// Konstruktor 
Gra::Gra()
{
	//this->initVariable();
	this->initWindow();
	this->initTextures();
	this->initPlayer();
}

// Destruktor / Niszczy obiekty klass stworzone przez konstruktor
Gra::~Gra()
{
	delete this->window;
	delete this->player;

	//Kasowanie tekstur

	for (auto  &i : this->textures)  //równoczeœnie z deklaracj¹ nastêpuje inicjalizacja zmiennej wartoœci¹ (auto - samo decyduje o typie zmienniej)
	{                                          // for dla kolejnych tekstur przypisuje kolejne wartoœci i po tym iteruje
		delete i.second;                        // w mapie mapowan¹ wartoœæ kasuje, a nie klucz
	}

	for (auto* i : this->pocisk)  // kasowanie pocisków
	{
		delete i;
	}
}

//Accessors / Mo¿emy odpaliæ onko które mamy w private

/*const bool Gra::running() const
{
	return this->window->isOpen();
}
*/





//Functions


void Gra::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Gra::pollEvents()
{
	//u¿ywamy thiss bo window to wzkaŸnik
	while (this ->window ->pollEvent(this ->ev)) 
	{
		if (this ->ev.type == Event::Closed)
			this ->window->close();

		switch (this ->ev.type)
		{
		case Event::KeyPressed:
			if (this ->ev.key.code == Keyboard::J)
				this->window->close();
			break;
		}
	}
}

void Gra::updateEvents()
{
	
}

void Gra::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::W))
		this->player->move(0.f, -1.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->player->move(1.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		this->player->move(0.f, 1.f);

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		this->pocisk.push_back(new Pocisk(this->textures["POCISK"], this->player->getPozycja().x, this->player->getPozycja().y, 0.f, 0.f, 0.f));  // push_back dodaje elementy rzosze¿aj¹c vektor "pocisk"
	}

}

void Gra::updatePociski()
{
	for (auto* i : this->pocisk)   // i to bêd¹ pociski
	{
		i->update();
	}
}


void Gra::update()
{
	this->pollEvents();

	this->updateInput();

	this->updatePociski();
}

void Gra::render()
{
	this->window->clear(Color::Blue);

	//tu bêdziemy rysowaæ grê
	this->player->render(*this->window);

	for (auto* i : this->pocisk)   // i to bêd¹ pociski
	{
		i->render(this->window);
	}

	this->window->display();
}