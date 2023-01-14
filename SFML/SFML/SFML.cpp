
#include <iostream>
#include <random>
//  #include <cstdlib>

#include "Gra.h"
#include<time.h>
#include<locale.h>

using namespace std;
using namespace sf;



int main() {

	srand(time(NULL));
	setlocale(LC_CTYPE, "Polish");
	
	//Init Game engine / Okno

	Gra gra;

	gra.run();
	


	return 0;
}