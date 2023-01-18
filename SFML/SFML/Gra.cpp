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
	this->player->setPozycja(this->window->getSize().x / 2.f,
		this->window->getSize().y / 2.f );

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

	//Czcionkav2
	if (!this->czcionkav2.loadFromFile("textures/pixelmix.ttf"))
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

	//Menu
	this->menu = new Menu(window->getSize().x, window->getSize().y);

	//Help (me!)
	this->Help_txt.setFont(this->czcionkav2);
	this->Help_txt.setCharacterSize(20);
	this->Help_txt.setOutlineThickness(1);
	this->Help_txt.setOutlineColor(sf::Color::White);
	this->Help_txt.setFillColor(sf::Color::Black);
	this->Help_txt.setString("/Przykladowa instrukcja\n         do gry/");
	this->Help_txt.setPosition(
		this->window->getSize().x / 2.f - this->Help_txt.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->Help_txt.getGlobalBounds().height / 2.f);

	//Exit
	this->exit = new Exit(window->getSize().x, window->getSize().y);

	//Opcje
	this->opcje = new Opcje(window->getSize().x, window->getSize().y);

	//Plik
	this->plik = new Plik(window->getSize().x, window->getSize().y);

	//Trudnoœæ
	this->tryb = new Tryb(window->getSize().x, window->getSize().y);
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

	delete this->menu;
	delete this->exit;
	delete this->opcje;
	delete this->tryb;
	delete this->plik;

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

/// <summary>
///                                 Plik
/// </summary>

void Gra::zapisStruct(int nr)
{
	

	int i = nr - 1;
		std::cout << "Wprowadz nick dla gracza nr:  " << nr << " name: ";
		std::cin >> users[i].name;

		
		users[i].pkt = this->points;

		
		users[i].Hp = this->player->getHp();

	//	users[i].pozm = poziom;
}

void Gra::pobranieStruct(int nr)
{
	//std::stringstream ss;

	int i = nr - 1;
	std::cout << "Nick gracza " << nr <<"  "<< users[i].name << std::endl;

	this->points = users[i].pkt;
	//ss << "Punkty:  " << this->points;
	//this->Punkty_txt.setString(ss.str());


	this->player->setHp(users[i].Hp);
}




void Gra::zapis(User users[], int nr, std::string file)
{
	std::ofstream outFile;
	outFile.open(file);

	if (outFile.good() == true) {
		std::cout << "Otwarto plik!" << std::endl;

		int i = nr - 1;
			outFile  << users[i].name << " " << users[i].pkt << " " << users[i].Hp << std::endl;
		

		outFile.close();
		std::cout << "Data written to file successfully!" << std::endl;
	}
	else std::cout << "NIe uda³o siêotworzyæ pliku" << std::endl;
}

void Gra::odczyt(User users[], int nr, std::string file)
{
	std::ifstream inFile;
	inFile.open(file);

	if (inFile.good() == true) {
		std::cout << "Otwarto plik!" << std::endl;

		int i = nr - 1;
		inFile >> users[i].name >> users[i].pkt >> users[i].Hp;
			
		

		inFile.close();
		std::cout << "Data read from file successfully!" << std::endl;
	}
	else std::cout << "NIe uda³o siêotworzyæ pliku" << std::endl;
}

//Functions														==============================================================




void Gra::run()										         // odpalanie gry
{
	while (this->window->isOpen())
	{
		this->pollEvents();
		 
		// casey eventów
		switch (pozycja) {
		case 0:
			//this->updateEvents();				//Menu
			this->renderMenu();
			
			break;
		
		case 1:

			if (this->player->getHp() > 0)			//Gra
				this->update();

			this->render();
			break;

		case 2:
			this->renderHelp();

			break;

		case 3:
			this->renderExit();						//Exit
			break;

		case 4:
			this->renderOpcje();						//Opcje
			break;

		case 5:
			this->renderPlik();						//Plik
			break;

		case 6:
			this->renderTryb();						//Trudnosc
			break;




		}



	//	this->renderMenu();
	//
	//	if(this->player->getHp() > 0 )         //zatrzymanie gry na skutek utraty ¿ycia
	//	this->update();
	//
	//	this->render();
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


			//Exit

			if (this->ev.key.code == Keyboard::Escape)
			{
				this->pozycja = 3;
			}
		
			//Powrót do Menu

			if (this->ev.key.code == Keyboard::K)
				this->pozycja = 0;
			
			//Help
		if(pozycja == 1)
			if (this->ev.key.code == Keyboard::F1)
				this->pozycja = 2;

			break;




			
		
		case Event::KeyReleased:


			//Help
		if(pozycja == 2)
			if (this->ev.key.code == Keyboard::F1)
				this->pozycja = 1;


			switch (pozycja)
			{
			//Menu

				case 0:                                           
					this->updateMenu();
					break;
					
			//Exit

				case 3:
					this->updateExit();
					break;
				

			//Opcje

				case 4:
					this->updateOpcje();
					
					break;

			//Plik

				case 5:
					this->updatePlik();
					break;

			//Trudnosc
				case 6:
					
					this->updateTryb();
					break;
			}	 


		break;
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
		if (this->poziom == 1 || this->poziom == 2 || this->poziom == 3)
		{
			this->przeciwnicy.push_back(new Przeciwnik(rand() % (this->window->getSize().x) - 50.f, -100.f));
			this->spawnTimer = 0.f;
		}

		if (this->poziom == 2 || this->poziom == 3)
		{
			this->przeciwnicy.push_back(new Przeciwnik(rand() % (this->window->getSize().x) - 50.f, -100.f));
			this->spawnTimer = 0.f;
		}

		if(this->poziom == 3)
		{
			this->przeciwnicy.push_back(new Przeciwnik(rand() % (this->window->getSize().x) - 50.f, -100.f));
			this->spawnTimer = 0.f;

			
		}

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


void Gra::updateMenu()
{
	if (this->ev.key.code == Keyboard::Up)
		this->menu->MoveUp();

	if (this->ev.key.code == Keyboard::Down)
		this->menu->MoveDown();

	if (this->ev.key.code == Keyboard::Return)
	{
		switch (this->menu->getWybrane())             //Wybieramy pozycjê z Menu
		{
		case 0:
		{
			std::cout << "Wybrano 'NOWA GRA' " << std::endl;

			
			
			//this->initTextures();
			
			this->initPunktacja();
			this->initPlayer();
			this->initPrzeciwnicy();

			
			
			pozycja = 6;


			break;
		}
		case 1:
		{
			std::cout << "Wybrano 'KONTYNUUJ' " << std::endl;
			pozycja = 1;

			break;
		}
		case 2:
		{
			std::cout << "Wybrano 'Opcje' " << std::endl;
			pozycja = 4;
			break;
		}
		case 3:
		{
			std::cout << "Wybrano 'Wyjscie' " << std::endl;
			this->window->close();
			break;
		}
		}
	}
}


void Gra::updateExit()
{
	if (this->ev.key.code == Keyboard::Left)
		this->exit->MoveUp();

	if (this->ev.key.code == Keyboard::Right)
		this->exit->MoveDown();

	if (this->ev.key.code == Keyboard::Return)
	{
		switch (this->exit->getWybrane())             //Wybieramy pozycjê z Menu Exit
		{
		case 0:
		{
			std::cout << "Wybrano 'Graj dalej' " << std::endl;
			pozycja = 1;

			break;
		}
		case 1:
		{
			std::cout << "Wybrano 'Wyjdz' " << std::endl;
			this->window->close();
			break;
		}
		}

	}
}


void Gra::updateOpcje()
{
	if (this->ev.key.code == Keyboard::Up)
		this->opcje->MoveUp();

	if (this->ev.key.code == Keyboard::Down)
		this->opcje->MoveDown();

	if (this->ev.key.code == Keyboard::Return)
	{
		switch (this->opcje->getWybrane())           //Wybieramy pozycjê z Menu Opcji
		{
		case 0:
		{
			std::cout << "Wybrano 'Zapis' " << std::endl;
			flag = true;
			pozycja = 5;
			
			break;
		}
		case 1:
		{
			std::cout << "Wybrano 'Wczytaj' " << std::endl;
			flag = false;
			pozycja = 5;
			break;
		}
		case 2:
		{
			std::cout << "Wybrano 'Trudnosc' " << std::endl;
			pozycja = 6;
			break;
		}


		}

	}
}



void Gra::updatePlik()
{
	if (this->ev.key.code == Keyboard::Up)
		this->plik->MoveUp();

	if (this->ev.key.code == Keyboard::Down)
		this->plik->MoveDown();

	if (this->ev.key.code == Keyboard::Return)
	{
		switch (this->plik->getWybrane())           //Wybieramy pozycjê z Menu Opcji
		{
		case 0:
		{
			std::cout << "Wybrano 'Zapis 1' " << std::endl;
			
			if(flag)
			{
				this->zapisStruct(1);
				this->zapis(users, 1, "textures/users.txt");
			}
			else{
				this->odczyt(users, 1, "textures/users.txt");
				this->pobranieStruct(1);
				pozycja = 6;
			}
			break;
		}
		case 1:
		{
			std::cout << "Wybrano 'Zapis 2' " << std::endl;
			if (flag)
			{
				this->zapisStruct(2);
				this->zapis( users, 2, "textures/users2.txt");
			}
			else {
				this->odczyt(users, 2, "textures/users2.txt");
				this->pobranieStruct(2);
				pozycja = 6;
			}
			break;
		}
		case 2:
		{
			std::cout << "Wybrano 'Zapis 3' " << std::endl;
			if (flag)
			{
				this->zapisStruct(3);
				this->zapis(users, 3 , "textures/users3.txt");
			}
			else {
				this->odczyt(users, 3, "textures/users3.txt");
				this->pobranieStruct(3);
				pozycja = 6;
			}
			break;
		}
		}
	}
}

void Gra::updateTryb()
{
	if (this->ev.key.code == Keyboard::Left)
		this->tryb->MoveUp();

	if (this->ev.key.code == Keyboard::Right)
		this->tryb->MoveDown();

	if (this->ev.key.code == Keyboard::Return)
	{
		switch (this->tryb->getWybrane())             
		{
		case 0:
		{
			std::cout << "Wybrano 'Latwy' " << std::endl;

			this->spawnTimerMax = 50.f;
			this->player->setSpeed(3.f);
			this->player->setReload(20.f);

			poziom = 1;
			pozycja = 1;
			

			break;
		}
		case 1:
		{
			std::cout << "Wybrano 'Sredni' " << std::endl; //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			this->player->setReload(30.f);
			this->spawnTimerMax = 30.f;
			poziom = 2;

			pozycja = 1;
			break;
		}
		case 2:
		{
			std::cout << "Wybrano 'Trudny' " << std::endl;

			this->spawnTimerMax =20.f ;       // bazowo 50.f
			this->player->setSpeed(2.1f);       // bazowa prêdkoœæ = 3.f
			this->player->setReload(50.f);			//bazowo 20.f

			poziom = 3;

			pozycja = 1;
			break;
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

void Gra::renderMenu()            // Renderowanie Menu
{
	this->window->clear();
	this->renderTlo();
	this->menu->draw(*this->window);
	this->window->display();
}

void Gra::renderHelp()
{
	//	this->window->clear();
	this->window->draw(this->Help_txt);		

	this->window->display();
}

void Gra::renderExit()
{
	this->window->clear();
	this->renderTlo();
	this->exit->draw(*this->window);
	this->window->display();
}

void Gra::renderOpcje()   
{
	this->window->clear();
	this->renderTlo();
	this->opcje->draw(*this->window);
	this->window->display();
}

void Gra::renderPlik()
{
	this->window->clear();
	this->renderTlo();
	this->plik->draw(*this->window);
	this->window->display();

}

void Gra::renderTryb()
{
	this->window->clear();
	this->renderTlo();
	this->tryb->draw(*this->window);
	this->window->display();

}





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

	//this->renderMenu();


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

