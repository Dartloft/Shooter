#include "SFML/Graphics.hpp"
#include "Juego.h"
#include "Enemigo.h"


int main()
{
	srand(time(NULL));

	Juego* partida1;

	partida1 = new Juego(800,600,"Shooter");


	return 0;
}