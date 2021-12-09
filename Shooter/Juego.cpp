#include "SFML/Graphics.hpp"
#include "Juego.h"

using namespace sf;

Juego::Juego(int resolucion_x, int resolucion_y, std::string titulo)
{
	GameOver = false;

	vidas = 3;

	puntos = 0;

	fps = 60;

	ventana1 = new RenderWindow(VideoMode(resolucion_x, resolucion_y), titulo);

	ventana1->setFramerateLimit(fps);

	ventana1->setMouseCursorVisible(false);

	for (int i = 0; i < 4; i++)
	{
		slot_vaqueromalo[i] = false;
	}


	evento1 = new Event;


	CargarGraficos();

	txt_3 = new Texture;
	txt_3->loadFromFile("fondobajo.jpg");

	rectangulo = new RectangleShape({800,40});
	//rectangulo->setFillColor(Color::Blue);
	rectangulo->setPosition(0, 0);
	rectangulo->setTexture(txt_3);

	reloj1 = new Clock;
	tiempo1 = new Time;
	tiempo2 = 0;

	fuente1 = new Font();
	fuente1->loadFromFile("UbuntuMono-B.ttf");

	texto_vidas = new Text();
	texto_vidas->setFont(*fuente1);
	texto_vidas->setString("Vidas =");
	texto_vidas->setPosition(10, 0);
	texto_vidas->setFillColor(Color::White);
	texto_vidas->setOutlineColor(Color::Black);
	texto_vidas->setOutlineThickness(2);

	texto_Pvidas = new Text();
	texto_Pvidas->setFont(*fuente1);
	texto_Pvidas->setPosition(125, 0);
	texto_Pvidas->setFillColor(Color::White);
	texto_Pvidas->setOutlineColor(Color::Black);
	texto_Pvidas->setOutlineThickness(2);

	texto_puntos = new Text();
	texto_puntos->setFont(*fuente1);
	texto_puntos->setString("Puntos =");
	texto_puntos->setPosition(300,340);
	texto_puntos->setFillColor(Color::White);
	texto_puntos->setOutlineColor(Color::Black);
	texto_puntos->setOutlineThickness(2);

	texto_Ppuntos = new Text();
	texto_Ppuntos->setFont(*fuente1);
	texto_Ppuntos->setPosition(440,340);
	texto_Ppuntos->setFillColor(Color::White);
	texto_Ppuntos->setOutlineColor(Color::Black);
	texto_Ppuntos->setOutlineThickness(2);

	Game_Over = new Text();
	Game_Over->setFont(*fuente1);
	Game_Over->setString("GAME OVER");
	Game_Over->setPosition(300, 300);
	Game_Over->setFillColor(Color::White);
	Game_Over->setOutlineColor(Color::Black);
	Game_Over->setOutlineThickness(2);

	Gameloop();
}

void Juego::Gameloop()
{


	while (!GameOver)
	{	
		*tiempo1 = reloj1->getElapsedTime();

		if (tiempo1->asSeconds() > 3 + tiempo2)
		{
			tiempo2 = tiempo1->asSeconds();
			int resultado;
			resultado = rand() % 100 + 1;

			if (resultado < 30)
			{
				//No creamos monstruo
			}
			else
			{
				bool espacio_disponible = false;
				for (int i = 0; i < 4; i++)
				{
					if (!slot_vaqueromalo[i])
					{
						espacio_disponible = true;
						
					}

				}
				if (espacio_disponible)
				{
					while (1)
					{
						int resultado = rand() % 4 + 0;

						if (!slot_vaqueromalo[resultado])
							vaqueromalo[resultado] = new Enemigo({ (float)(200.0 * resultado),300.0 });
							break;
						
					}
					
				}

			}
		}

		chequear_enemigos();

		ventana1->clear();

		Procesar_Eventos();

		
		ventana1->draw(spr_fondo);

		ventana1->draw(*rectangulo);

		for (int i = 0; i < 4; i++)
		{
			if (vaqueromalo[i] != NULL)
			{
				ventana1->draw(vaqueromalo[i]->get_sprite());
			}
		}

		ventana1->draw(spr_mira);

		texto_Pvidas->setString(std::to_string(vidas));

		ventana1->draw(*texto_Pvidas);

		ventana1->draw(*texto_vidas);

		texto_Ppuntos->setString(std::to_string(puntos));


		if (vidas == 0)
		{
			ventana1->draw(*Game_Over);

			ventana1->draw(*texto_Ppuntos);

			ventana1->draw(*texto_puntos);
		}
		
		ventana1->display();

		if (vidas < 1) 
		{
			*tiempo1 = reloj1->getElapsedTime();
			if (tiempo1->asSeconds() > 3 + tiempo2)
			{
				tiempo2 = tiempo1->asSeconds();
				GameOver = true;
				
			}
			
			
		}
	}
}

void Juego::CargarGraficos()
{
	
	txt_fondo.loadFromFile("fondo1.jpg");
	spr_fondo.setTexture(txt_fondo);
	spr_fondo.setScale((float)(ventana1->getSize().x) / txt_fondo.getSize().x, (float)ventana1->getSize().y / txt_fondo.getSize().y);

	txt_mira.loadFromFile("crosshair.png");
	spr_mira.setTexture(txt_mira);
	
}

void Juego::Procesar_Eventos()
{
	while (ventana1->pollEvent(*evento1))
	{
		switch (evento1->type)
		{
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseMoved:
			spr_mira.setPosition((Vector2f)Mouse::getPosition(*ventana1));
			break;
		case Event::MouseButtonPressed:

			FloatRect recta(spr_mira.getPosition(), (Vector2f)spr_mira.getTexture()->getSize());
			for (int i = 0; i < 4; i++)
			{
				if (vaqueromalo[i])
				{
					if (vaqueromalo[i]->get_sprite().getGlobalBounds().intersects(recta))
					{
						vaqueromalo[i] = NULL;
						puntos += 2 * 10 ;
					}
				}
			}
			break;
		}
	}
}

void Juego::chequear_enemigos()
{
	for (int i = 0; i < 4; i++)
	{
		if (vaqueromalo[i])
		{
			if (vaqueromalo[i]->get_seconds() > 5)
			{
				vaqueromalo[i] = NULL;
				vidas--;
			}

		}


	}




	
}
