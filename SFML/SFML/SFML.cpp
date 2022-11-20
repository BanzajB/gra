#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <random>
//  #include <cstdlib>
#include <Windows.h>

using namespace std;
using namespace sf;




int main() {
	RenderWindow window(VideoMode(1500, 1000), "okno");
	Event event;


	

	



	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Black);

		 
			
		
		
		window.display();

	}



	return 0;
}