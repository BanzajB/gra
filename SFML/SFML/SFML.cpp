
#include <iostream>
#include <random>
//  #include <cstdlib>

#include "Gra.h"

using namespace std;
using namespace sf;



int main() {
	
	//Init Game engine / Okno

	Gra gra;




	// otwieranie okna
	while (gra.running())
	{
		//Update
		gra.update();

		//Render
		gra.render();


	}


	return 0;
}