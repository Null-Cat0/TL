// Traducción del lenguaje Mondrian
#include "mondrian.h"
#include <allegro5/allegro5.h>

using namespace std;

int main(int argc, char *argv[]) {
	// Se inicia el entorno gráfico
	iniciarM();

 	// Nuevo cuadro
	nuevoCuadroM("Un cuadro");
	pausaM(2.5);

 	// Nuevo cuadro
	nuevoCuadroM("Otro cuadro");
	pausaM(2.5);

	// Se liberan los recursos del entorno gráfico
	terminarM();
	return 0;
}
