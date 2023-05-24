#include "mondrian.h" 
#include <allegro5/allegro5.h> 
using namespace std; 
int main(int argc, char **argv){ 
 
	iniciarM();
	 nuevoCuadroM("Homenaje a Mondrian"); 
 	 rectanguloM(0, 0, 32, 100, 6); 
	 rectanguloM(87, 8, 32, 100, 6); 
	 lineaM(80, 4, false, 1); 
	 pausaM(2.30); 
	 pausaM(1.89); 
	 // "Se pintan los recuadros de""Se pintan los recuadros de"tiempoPausa 
	 // "Hola que tal" 
	 nuevoCuadroM("Bandera"); 
 	 rectanguloM(0, 0, 32, 100, 6); 
	 rectanguloM(68, 0, 32, 100, 1); 
	 lineaM(90, 4, false, 1); 
	terminarM();

}

 // Tabla de Simbolos
/* 
	 Nombre: grosor , Tipo: Entero, Valor: 4 
	 Nombre: tiempoPausa , Tipo: Real, Valor: 1.890000 
*/

 // Tabla de Simbolos Recuadros 
/* 
	 Nombre: CuadroAzul , Tipo: Recuadro, Alto: 46 , Ancho: 46 , Color: 4 
	 Nombre: FranjaNegra , Tipo: Recuadro, Alto: 32 , Ancho: 100 , Color: 1 
	 Nombre: FranjaVerde , Tipo: Recuadro, Alto: 32 , Ancho: 100 , Color: 6 
	 Nombre: RectanguloGris , Tipo: Recuadro, Alto: 27 , Ancho: 50 , Color: 2 
	 Nombre: RectanguloRojo , Tipo: Recuadro, Alto: 46 , Ancho: 16 , Color: 3 
	 Nombre: ZonaAmarilla , Tipo: Recuadro, Alto: 15 , Ancho: 30 , Color: 5 
*/

 // Tabla de Simbolo de Lineas 
/* 
	 Nombre: LineaFina , Tipo: Linea, Grosor: 1  esHorizontal: True , Color: 2 
	 Nombre: LineaH , Tipo: Linea, Grosor: 4  esHorizontal: True , Color: 1 
	 Nombre: LineaV , Tipo: Linea, Grosor: 4  esHorizontal: False , Color: 1 
*/
