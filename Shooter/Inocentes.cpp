#include "SFML/Graphics.hpp"
#include "Inocentes.h"
#include <stdlib.h>

using namespace sf;

Inocentes::Inocentes(Vector2f posicion1)
{
	int numero_inocentes;

	numero_inocentes = rand() % 2 + 1;

	std::string path1;

	path1 = "inocente" + std::to_string(numero_inocentes) + ".png";
	txt_inocente.loadFromFile(path1);
	spr_inocente.setTexture(txt_inocente);

	spr_inocente.setPosition(posicion1);

	reloj1 = new Clock;
	tiempo1 = new Time;
	*tiempo1 = reloj1->getElapsedTime();
}

Sprite Inocentes::get_sprite1()
{
	return spr_inocente;
}

