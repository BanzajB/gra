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
	this->videoMode.width = 1500;

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

// Konstruktor 
Gra::Gra()
{
	//this->initVariable();
	this->initWindow();
	this->initPlayer();
}

// Destruktor / Niszczy obiekty klass stworzone przez konstruktor
Gra::~Gra()
{
	delete this->window;
	delete this->player;
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


void Gra::update()
{
	this->pollEvents();
}

void Gra::render()
{
	this->window->clear(Color::Blue);

	//tu bêdziemy rysowaæ grê
	this->player->render(*this->window);

	this->window->display();
}