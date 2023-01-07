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
	this->videoMode.height = 800;
	this->videoMode.width = 1080;

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

void Gra::initGUI()
{
	//Czcionka
	if(!this->czcionka.loadFromFile("textures/PixelFlag.ttf"))
	std::cout << "ERROR nie uda³o siê zaladowaæ czcionki! " << std::endl;

	// Init tekstu do punktów
	this->Punkty_txt.setFont(this->czcionka);
	this->Punkty_txt.setCharacterSize(30);
	this->Punkty_txt.setFillColor(sf::Color::Yellow);
	this->Punkty_txt.setString("AMOGUS");                        //dajemy stringa na nasza czcionkê 

	//Init Game Over 
	this->GameOver_txt.setFont(this->czcionka);
	this->GameOver_txt.setCharacterSize(100);
	this->GameOver_txt.setFillColor(sf::Color::Yellow);
	this->GameOver_txt.setString("GAME OVER!"); 
	this->GameOver_txt.setPosition(
		this->window->getSize().x /2.f - this->GameOver_txt.getGlobalBounds().width /2.f,
		this->window->getSize().y /2.f - this->GameOver_txt.getGlobalBounds().height /2.f); 


	// Init player GUI
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f));
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(150.f, 10.f));

	this->playerHpBarTlo = this->playerHpBar;
	this->playerHpBarTlo.setFillColor(sf::Color(40, 70, 200, 100));
	//this->playerHpBarTlo.setPosition();
}

void Gra::initTlo()
{
	if (!this->Tlo.loadFromFile("textures/Tlo.jpg"))
		std::cout << "ERROR :: T³o nie za³adowane" << std::endl;

	this->TloSprite.setTexture(this->Tlo);
	this->TloSprite.setColor(Color(200, 200, 100, 100));
}

void Gra::initPunktacja()
{
	this->points = 0;
}

void Gra::initPrzeciwnicy()
{
	this->spawnTimerMax = 50.f;
	this->spawnTimer = spawnTimerMax;
}

// Konstruktor 
Gra::Gra()
{
	//this->initVariable();
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initTlo();
	this->initPunktacja();
	this->initPlayer();
	this->initPrzeciwnicy();
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

	for (auto* i : this->przeciwnicy)
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



//Functions														==============================================================


void Gra::run()										         // odpalanie gry
{
	while (this->window->isOpen())
	{
		this->pollEvents();

		if(this->player->getHp() > 0)         //zatrzymanie gry na skutek utraty ¿ycia
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

			//Menu
		case Event::KeyReleased:
			if (this->ev.key.code == Keyboard::Up) 
			{
				pozycja--;
				if (pozycja < 0) pozycja = this->pozycja->
			}
		}


	}
}

/*void Gra::cooldown(int seconds)
{
	clock_t start = clock();
	clock_t period = seconds * CLOCKS_PER_SEC;
	clock_t elapsed;                             //czas który up³yn¹

	do {
		elapsed = clock() - start;
	} while (elapsed < period);
}
*/

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

	if (Keyboard::isKeyPressed(Keyboard::Space) && this->player->resetReload())    //resetReload zwraca true
	{
		this->pocisk.push_back(new Pocisk(this->textures["POCISK"], this->player->getPozycja().x + 25.f, this->player->getPozycja().y - 15.f, 0.f, -1.f, 4.f));  // push_back dodaje elementy rzosze¿aj¹c vektor "pocisk"
	}

}

void Gra::updateGUI()
{
	std::stringstream ss;             // do ustawiania punktów jako stringi 

	ss << "Punkty:  " << this->points;

	this->Punkty_txt.setString(ss.str());


	//Update playerGUI
	//this->player->setHp(5);
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax() ;
	this->playerHpBar.setSize(Vector2f(300.f *hpPercent, this->playerHpBar.getSize().y));           // da siê zrobieæ setScale
	
}

void Gra::updateTlo()
{
}

void Gra::updateKolizja()
{
	if (this->player->getObrys().left < 0.f)                                     // kolizja z lew¹ stron¹ okienka
	{
		this->player->setPozycja(0.f, this->player->getObrys().top);
	}

	else if (this->player->getObrys().left + this->player->getObrys().width >= this->window->getSize().x)                // kolizja z praw¹ stron¹ 
	{
		this->player->setPozycja(this->window->getSize().x - this->player->getObrys().width, this->player->getObrys().top);
	}


	if (this->player->getObrys().top < 0.f)                                     // kolizja z gór¹ okienka
	{
		this->player->setPozycja(this->player->getObrys().left, 0.f);
	}
	else if (this->player->getObrys().top + this->player->getObrys().height >= this->window->getSize().y)            // kolizja z do³em 
	{
		this->player->setPozycja(this->player->getObrys().left, this->window->getSize().y - this->player->getObrys().height);
	}
}

void Gra::updatePociski()
{
	unsigned licznik = 0;

	for (auto* naboj : this->pocisk)                               // nabój to pojedyñczy pocisk; "pocisk" odnosi sie do ka¿dego pocisku (wektora pocisków)
	{
		naboj->update();


		if (naboj->getObrysPck().top + naboj->getObrysPck().height < 0.f)  //kasowanie pocisków gdy wyjd¹ poza ekaran
		{

			delete this->pocisk.at(licznik);	                   //delete do kasowania rzeczy tworzonych przez new  // licznik to klucz w mapowaniu  
			this->pocisk.erase(this->pocisk.begin() + licznik);    //kasowanie z wektora, kasujemy ten pociski co jako piwrwszy wylecaia³
			//--licznik;

			//std::cout << this->pocisk.size() +1 << "\n";          //zliczanie naboji na ekranie
		}
		++licznik;
	}
}

void Gra::updatePrzeciwnicy()
{
	this->spawnTimer += 0.5f;                                        //przeciwnicy ci¹gle siê pojawiaj¹ 
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->przeciwnicy.push_back(new Przeciwnik(rand()% (this->window->getSize().x) -50.f, -100.f));
		this->spawnTimer = 0.f;
	}

	/* if (1 > 0)
	{
		cooldown(3);
		this->przeciwnicy.push_back(new Przeciwnik(rand() % (this->videoMode.width) - 30, rand() % (this->videoMode.height) - 30));
	}
	*/




	//Interakcja nabój-przeciwnik


	for (int i = 0; i < this->przeciwnicy.size(); ++i)							// i - numeracja przeciwników
	{
		bool  przeciwnik_erased = false;

		this->przeciwnicy[i]->update();										//przciwnicy pojawiaj¹ siê ci¹gle

		for (size_t k = 0; k < this->pocisk.size() && !przeciwnik_erased; k++)                 //kolizja     // size_t - typ ca³kowity bez znaku (unsigned int), mieœci rozmiar dowolnego obiektu
		{
		

			if (this->pocisk[k]->getObrysPck().intersects(this->przeciwnicy[i]->getObrys()))
			{
				this->points += this->przeciwnicy[i]->getPunkty();            //getPunkty zwraca wartoœc punktów za przeciwnika 

				delete this->pocisk[k];
				this->pocisk.erase(this->pocisk.begin() + k);

				delete this->przeciwnicy[i];
				this->przeciwnicy.erase(this->przeciwnicy.begin() + i);
				przeciwnik_erased = true;
			}
			
		}
		


		//Usuwanie przeciwników

		
		if (!przeciwnik_erased)                                           //true musi byæ by if siê wykona³
		{
			if (this->przeciwnicy[i]->getObrys().top > this->window->getSize().y)  //usuwanie przeciwników z do³u okienka
			{
				delete this->przeciwnicy[i];
				this->przeciwnicy.erase(this->przeciwnicy.begin() + i);
			//	std::cout << this->przeciwnicy.size() << std::endl;            //zliczanie przzeciwników
				przeciwnik_erased = true;
			}


			else if (przeciwnicy[i]->getObrys().intersects(this->player->getObrys()))        // usuwanie przeciwników przy kolizji z graczem 
			{

																							// w player->initDamage ustawiamy wartoœæ; musi byæ przed skasowaniem przeciwnika
				this->player->loseHp(this->przeciwnicy[i]->getDamage());					//this->player->loseHp(1);

				delete this->przeciwnicy[i];
				this->przeciwnicy.erase(this->przeciwnicy.begin() + i);
				przeciwnik_erased = true;
				
			}								
		}
	}
}


void Gra::update()             //wa¿na kolejnoœæ
{
	

	this->updateInput();

	this->player->update();

	this->updateKolizja();

	this->updatePociski();

	this->updatePrzeciwnicy();

	this->updateGUI();

	this->updateTlo();
}

/// <summary>
///                     renderowanie 
/// </summary>

void Gra::renderGUI()
{
	this->window->draw(this->Punkty_txt);

	this->window->draw(this->playerHpBarTlo);
	this->window->draw(this->playerHpBar);
}

void Gra::renderTlo()
{
	this->window->draw(this->TloSprite);
}

void Gra::render()
{
	this->window->clear();

	this->renderTlo();     //T³o

	//tu bêdziemy rysowaæ grê

	for (auto* naboj : this->pocisk)   // naboj to 1 pocisk
	{
		naboj->render(this->window);
	}

	this->player->render(*this->window);

	for (auto* a : this->przeciwnicy)  // a to 1 przeciwnik
	{
		a->render(this->window);
	}

	this->renderGUI();

	//Game over scren
	if (this->player->getHp() <= 0)
	this->window->draw(this->GameOver_txt);

	this->window->display();
}