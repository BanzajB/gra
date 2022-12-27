
#include <iostream>
#include <random>
//  #include <cstdlib>

#include "Gra.h"
#include<time.h>

using namespace std;
using namespace sf;



int main() {

	srand(time(NULL));
	
	//Init Game engine / Okno

	Gra gra;

	gra.run();
	


	return 0;
}