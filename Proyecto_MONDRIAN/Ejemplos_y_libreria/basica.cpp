// Traducción del lenguaje Mondrian
#include "mondrian.h"
#include <allegro5/allegro5.h>

using namespace std;

int main(int argc, char *argv[]) {
	// Se inicia el entorno gráfico
	iniciarM();

 	// Nuevo cuadro
	nuevoCuadroM("Homenaje a Mondrian");
	pausaM(1.5);
	// Se pintan las líneas horizontales y verticales
	lineaM(0,  4, true, NEGRO);
	lineaM(50,  4, true, NEGRO);
	lineaM(81,  4, true, NEGRO);
	lineaM(46,  4, false, NEGRO);
	lineaM(80, 4, false, NEGRO);
	pausaM(1);
	// Se pintan los recuadros de color
	rectanguloM(4, 0, 46, 46, AZUL);
	rectanguloM(54, 0, 46, 46, AZUL);
	rectanguloM(4, 84, 46, 16, ROJO);
	rectanguloM(54, 50, 27, 50, GRIS);
	rectanguloM(85, 50, 15, 30, AMARILLO);
	pausaM(1.5);
	pausaM(2.5);

 	// Nuevo cuadro
	nuevoCuadroM("Bandera");
	rectanguloM(0, 0, 32, 100, VERDE);
	lineaM(32, 1, true, GRIS);
	lineaM(67, 1, true, GRIS);
	rectanguloM(68, 0, 32, 100, NEGRO);
	pausaM(2.5);

	// Se liberan los recursos del entorno gráfico
	terminarM();
	return 0;
}
