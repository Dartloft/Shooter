#include "SFML/Graphics.hpp"
#include "Enemigo.h"
#include <stdlib.h>

using namespace sf;

Enemigo::Enemigo(Vector2f posicion)
{
	int numero_enemigo;

	numero_enemigo = rand() % 4 + 1;

	std::string path;
	
	path = "vaqueromalo" + std::to_string(numero_enemigo) + ".png";
	txt_vaqueromalo.loadFromFile(path);
	spr_vaqueromalo.setTexture(txt_vaqueromalo);

	spr_vaqueromalo.setPosition(posicion);
	


	reloj1 = new Clock;
	tiempo1 = new Time;
	*tiempo1 = reloj1->getElapsedTime();

	
}

Sprite Enemigo::get_sprite()
{
	return spr_vaqueromalo;
}

float Enemigo::get_seconds()
{
	*tiempo1 = reloj1->getElapsedTime();
	return tiempo1->asSeconds();
}