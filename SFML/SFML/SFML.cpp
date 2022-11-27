#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
//  #include <cstdlib>
#include <Windows.h>

using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow* window;

	void initWindow();



public:
	Game();
	virtual ~Game();

	
};







int main() {
	RenderWindow window(VideoMode(1500, 1000), "Space shootage");
	Event event;


	



	// otwieranie okna
	while (window.isOpen()) {

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			switch (event.type)
			{
			case Event::KeyPressed:
				if (event.key.code == Keyboard::Escape)
					window.close();
				break;
			}
		}

		window.clear(Color::Black);

		 
			
		
		
		window.display();

	}
	


	return 0;
}