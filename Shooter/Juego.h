#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Enemigo.h"


using namespace sf;

class Juego
{
private:
	RenderWindow* ventana1;

	Texture txt_fondo;
	Sprite spr_fondo;

	Texture* txt_3;
	RectangleShape* rectangulo;

	Texture txt_mira;
	Sprite spr_mira;

	

	Event* evento1;
	Enemigo* vaqueromalo[4];

	int vidas;
	int puntos;
	int fps;
	bool GameOver;
	bool slot_vaqueromalo[4];

	Clock* reloj1;
	Time* tiempo1;
	float tiempo2;

	Font* fuente1;
	Text* texto_vidas;
	Text* texto_Pvidas;
	Text* texto_puntos;
	Text* texto_Ppuntos;
	Text* Game_Over;

public:
	Juego(int resolucion_x, int resolucion_y, std::string titulo);
	void Gameloop();
	void CargarGraficos();
	void Procesar_Eventos();
	void chequear_enemigos();
};

