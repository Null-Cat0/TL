#include "mondrian.h" 
#include <allegro5/allegro5.h> 
using namespace std; 
int main(int argc, char **argv){ 
 
	// Se inicia el entorno gráfico
	iniciarM();
	 nuevoCuadroM("Homenaje a Mondrian"); 
 	 pausaM(1.50); 
	 // "Se pintan las líneas horizontales y verticales" 
	 lineaM(0, 4, true, 1); 
	 lineaM(50, 4, true, 1); 
	 lineaM(81, 4, true, 1); 
	 lineaM(46, 4, false, 1); 
	 lineaM(80, 4, false, 1); 
	 pausaM(1.00); 
	 // "Se pintan los recuadros de color" 
	 rectanguloM(4, 0, 46, 46, 4); 
	 rectanguloM(54, 0, 46, 46, 4); 
	 rectanguloM(4, 84, 46, 16, 3); 
	 rectanguloM(54, 50, 27, 50, 2); 
	 rectanguloM(85, 50, 15, 30, 5); 
	 pausaM(1.50); 
	 nuevoCuadroM("Bandera"); 
 	 rectanguloM(0, 0, 32, 100, 6); 
	 lineaM(32, 1, true, 2); 
	 lineaM(67, 1, true, 2); 
	 rectanguloM(68, 0, 32, 100, 1); 
	// Se liberan los recursos del entorno gráfico
	terminarM();

}
