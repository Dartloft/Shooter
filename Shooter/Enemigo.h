#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

class Enemigo
{
private:
	Texture txt_vaqueromalo;
	Sprite spr_vaqueromalo;

	Clock* reloj1;
	Time* tiempo1;

public:
	Enemigo(Vector2f(posicion));
	Sprite get_sprite();
	float get_seconds();

};

