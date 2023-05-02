// Traducción del lenguaje Mondrian
#include "mondrian.h"
#include <allegro5/allegro5.h>

using namespace std;

int main(int argc, char *argv[]) {
	// Se inicia el entorno gráfico
	iniciarM();

 	// Nuevo cuadro
 	nuevoCuadroM("Composición en rojo, amarillo, azul y negro - Mondrian");
	// Se pintan las lineas horizontales y verticales
	lineaM(11,  4, true, NEGRO);
	lineaM(34,  4, true, NEGRO);
	lineaM(58,  4, true, NEGRO);
	lineaM(71,  4, true, NEGRO);
	lineaM(84,  4, true, NEGRO);
	lineaM(11,  4, false, NEGRO);
	lineaM(24,  4, false, NEGRO);
	lineaM(38,  4, false, NEGRO);
	lineaM(58,  4, false, NEGRO);
	lineaM(71,  4, false, NEGRO);
	lineaM(86,  4, false, NEGRO);
	pausaM(1.77);
	// Se pintan los recuadros de colo
	rectanguloM(15, 15, 43, 43, ROJO);
	rectanguloM(62, 15, 22, 23, NEGRO);
	rectanguloM(15, 62, 19, 24, AMARILLO);
	rectanguloM( 0, 62, 11, 24, AMARILLO);
	rectanguloM(75,  0, 25, 11, AMARILLO);
	rectanguloM(88, 42, 12, 16, NEGRO);
	rectanguloM(75, 62, 25, 24, AZUL);
	rectanguloM(75, 90, 25, 11, ROJO);
	pausaM(4.425);
	// Se pintan recuadros blancos para borrar partes de la rejilla
	rectanguloM( 0, 11, 11,  4, BLANCO);
	rectanguloM( 0, 38, 11,  4, BLANCO);
	rectanguloM(58,  0,  4, 11, BLANCO);
	rectanguloM(88, 24, 12,  4, BLANCO);
	rectanguloM(62, 71,  9,  4, BLANCO);
	rectanguloM( 0, 90, 71, 10, BLANCO);
	pausaM(8.85);
	pausaM(2.5);

 	// Nuevo cuadro
	nuevoCuadroM("Homenaje a Rothko");
	rectanguloM(0, 0, 100, 100, GRIS);
	// Campo de color interior azul
	rectanguloM(25, 25, 50, 50, AZUL);
	pausaM(2.5);
	pausaM(2.5);

	// Nuevo cuadro
	nuevoCuadroM("Homenaje a Antrios");
	// Antrios es un pintor ficticio de la obra de teatro Arte de Yasmina Reza
	lineaM(10, 1, true, BLANCO);
	lineaM(20, 1, true, BLANCO);
	lineaM(60, 1, true, BLANCO);
	pausaM(2.5);

	// Nuevo cuadro
	nuevoCuadroM("Damero");
	rectanguloM( 0,  0, 25, 25, NEGRO);
	rectanguloM(50,  0, 25, 25, NEGRO);
	rectanguloM( 0, 50, 25, 25, NEGRO);
	rectanguloM(50, 50, 25, 25, NEGRO);
	rectanguloM(25, 25, 25, 25, NEGRO);
	rectanguloM(75, 25, 25, 25, NEGRO);
	rectanguloM(25, 75, 25, 25, NEGRO);
	rectanguloM(75, 75, 25, 25, NEGRO);
	pausaM(2.5);

	// Se liberan los recursos del entorno gráfico
	terminarM();
	return 0;
}
