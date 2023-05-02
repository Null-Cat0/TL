/**

 Teoría de lenguajes
 Curso 2022/2023

 Nombre: mondrian.cpp
 Descripción: Implementación de la librería gráfica para el lenguaje MONDRIAN
 Autor:	Profesorado de la asignatura
 Fecha:	07/04/2023

 */

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro5.h>

#include <stdlib.h>
#include <iostream>

#include <cstring>
#include "mondrian.h"

using namespace std;

const int TAM_VENTANA = 1000;
const int TAM = TAM_VENTANA / 10;

ALLEGRO_DISPLAY     *display;

ALLEGRO_COLOR makecolor2(int color) ;



/*
 *	DESCRIPCIÓN: Inicia la interfaz gráfica
 */

void iniciarM () {
	if (al_init()){

	al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 1, ALLEGRO_REQUIRE);
	al_set_new_display_flags (ALLEGRO_WINDOWED);

	display = al_create_display(TAM_VENTANA,TAM_VENTANA);
	al_init_primitives_addon();

	// borra la ventana con el color blanco
    al_clear_to_color(makecolor2(BLANCO));
    al_set_window_title(display, "Mondrian");

    // se refresca la pantalla
    al_flip_display();

	}

}

void nuevoCuadroM (string titulo) {
	al_clear_to_color(makecolor2(BLANCO));
	al_set_window_title(display, titulo.c_str());
    al_flip_display();
}


/*
 * PRE: {s >= 0}
 * DESCRIPCIÓN: para la ejecución durante s segundos
 */

void pausaM(float s) {
	al_rest(s);
}


/*
 *	DESCRIPCIÓN: Libera los recursos usados por el entorno gráfico
 */
void terminarM () {
	al_destroy_display          (display);
}


void rectanguloM(int fila, int columna, int alto, int ancho, int color) {
	fila *= 10; columna *= 10; alto *= 10; ancho *= 10;
	al_draw_filled_rectangle(columna, fila, columna+ancho, fila+alto, makecolor2(color));
	al_flip_display();
}


void lineaM(int origen, int ancho, bool esHorizontal, int color) {
	if (esHorizontal) {
		rectanguloM(origen, 0, ancho, TAM, color);
	}
	else {
		rectanguloM(0, origen, TAM, ancho, color);
	}
}

// define el color en función de los valores makecol - allegro library
ALLEGRO_COLOR makecolor2(int color) {

	ALLEGRO_COLOR alColor;

	switch (color) {
	case BLANCO:
		alColor = al_map_rgb (255, 255, 255);
		break;
	case NEGRO:
		alColor = al_map_rgb (0,    0,   0);
		break;
	case GRIS:
		alColor = al_map_rgb ( 180, 180, 180);
		break;
	case ROJO:
		alColor = al_map_rgb (200,   30,  30);
		break;
	case AMARILLO:
		alColor = al_map_rgb ( 255, 228, 0);
		break;
	case AZUL:
		alColor = al_map_rgb (40, 40, 200);
		break;
	case VERDE:
		alColor = al_map_rgb ( 20,200,80);
		break;
	default:
		alColor = al_map_rgb (255, 255, 255);
		break; //color blanco
	}

	return alColor;
}


