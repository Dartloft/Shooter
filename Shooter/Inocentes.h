#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>

using namespace sf;

class Inocentes
{
private:
	Texture txt_inocente;
	Sprite spr_inocente;

	Clock* reloj1;
	Time* tiempo1;

public:
	Inocentes(Vector2f(posicion1));
	Sprite get_sprite1();

};