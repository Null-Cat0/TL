#include "mondrian.h" 
#include <allegro5/allegro5.h> 
using namespace std; 
int main(int argc, char **argv){ 
 
	// Se inicia el entorno gráfico
	iniciarM();
	 nuevoCuadroM("Composición en rojo, amarillo, azul y negro - Mondrian"); 
 	 // "Se pintan las lineas horizontales y verticales" 
	 lineaM(11, 4, true, 1); 
	 lineaM(34, 4, true, 1); 
	 lineaM(58, 4, true, 1); 
	 lineaM(71, 4, true, 1); 
	 lineaM(84, 4, true, 1); 
	 lineaM(11, 4, false, 1); 
	 lineaM(24, 4, false, 1); 
	 lineaM(38, 4, false, 1); 
	 lineaM(58, 4, false, 1); 
	 lineaM(71, 4, false, 1); 
	 lineaM(86, 4, false, 1); 
	 pausaM(1.77); 
	 // "Se pintan los recuadros de color" 
	 rectanguloM(15, 15, 43, 43, 3); 
	 rectanguloM(62, 15, 22, 23, 1); 
	 rectanguloM(15, 62, 19, 24, 5); 
	 rectanguloM(0, 62, 11, 24, 5); 
	 rectanguloM(75, 0, 25, 11, 5); 
	 rectanguloM(88, 42, 12, 16, 1); 
	 rectanguloM(75, 62, 25, 24, 4); 
	 rectanguloM(75, 90, 25, 11, 3); 
	 pausaM(4.43); 
	 // "Se pintan recuadros blancos para borrar parte de la rejilla" 
	 rectanguloM(0, 11, 11, 4, 0); 
	 rectanguloM(0, 38, 11, 4, 0); 
	 rectanguloM(58, 0, 4, 11, 0); 
	 rectanguloM(88, 24, 12, 4, 0); 
	 rectanguloM(62, 71, 9, 4, 0); 
	 rectanguloM(0, 90, 71, 10, 0); 
	 pausaM(8.85); 
	 nuevoCuadroM("Homenaje a Rothko"); 
 	 rectanguloM(0, 0, 100, 100, 2); 
	 // "Campo de color interior azul" 
	 rectanguloM(25, 25, 50, 50, 4); 
	 pausaM(2.50); 
	 nuevoCuadroM("Homenaje a Antrios"); 
 	 // "Antrios es un pintor ficticio de la obra de teatro Arte de Yasmina Reza" 
	 lineaM(10, 1, true, 0); 
	 lineaM(20, 1, true, 0); 
	 lineaM(60, 1, true, 0); 
	 nuevoCuadroM("Damero"); 
 	// Se liberan los recursos del entorno gráfico
	terminarM();

}

 // Tabla de Simbolos
/* 
	 Nombre: aux , Tipo: Entero, Valor: -3 
	 Nombre: ax , Tipo: Logico, Valor: False 
	 Nombre: g , Tipo: Logico, Valor: False 
	 Nombre: grosor , Tipo: Entero, Valor: 4 
	 Nombre: h , Tipo: Logico, Valor: True 
	 Nombre: mitad , Tipo: Entero, Valor: 50 
	 Nombre: momo , Tipo: Logico, Valor: False 
	 Nombre: p , Tipo: Real, Valor: 1.770000 
	 Nombre: x , Tipo: Entero, Valor: 25 
*/

 // Tabla de Simbolos Recuadros 
/* 
	 Nombre: Amarillo1 , Tipo: Recuadro, Alto: 19 , Ancho: 24 , Color: 5 
	 Nombre: Amarillo2 , Tipo: Recuadro, Alto: 11 , Ancho: 24 , Color: 5 
	 Nombre: Amarillo3 , Tipo: Recuadro, Alto: 25 , Ancho: 11 , Color: 5 
	 Nombre: Azul1 , Tipo: Recuadro, Alto: 25 , Ancho: 24 , Color: 4 
	 Nombre: Blanco1 , Tipo: Recuadro, Alto: 11 , Ancho: 4 , Color: 0 
	 Nombre: Blanco2 , Tipo: Recuadro, Alto: 4 , Ancho: 11 , Color: 0 
	 Nombre: Blanco3 , Tipo: Recuadro, Alto: 12 , Ancho: 4 , Color: 0 
	 Nombre: Blanco4 , Tipo: Recuadro, Alto: 9 , Ancho: 4 , Color: 0 
	 Nombre: Blanco5 , Tipo: Recuadro, Alto: 71 , Ancho: 10 , Color: 0 
	 Nombre: CampoAzul , Tipo: Recuadro, Alto: 50 , Ancho: 50 , Color: 4 
	 Nombre: CampoGris , Tipo: Recuadro, Alto: 100 , Ancho: 100 , Color: 2 
	 Nombre: CampoVerde , Tipo: Recuadro, Alto: 50 , Ancho: 50 , Color: 6 
	 Nombre: CuadradoNegro , Tipo: Recuadro, Alto: 25 , Ancho: 25 , Color: 1 
	 Nombre: Negro1 , Tipo: Recuadro, Alto: 22 , Ancho: 23 , Color: 1 
	 Nombre: Negro2 , Tipo: Recuadro, Alto: 12 , Ancho: 16 , Color: 1 
	 Nombre: Rojo1 , Tipo: Recuadro, Alto: 43 , Ancho: 43 , Color: 3 
	 Nombre: Rojo2 , Tipo: Recuadro, Alto: 25 , Ancho: 11 , Color: 3 
*/

 // Tabla de Simbolo de Lineas 
/* 
	 Nombre: LineaFinaBlanca , Tipo: Linea, Grosor: 1  esHorizontal: True , Color: 0 
	 Nombre: LineaH , Tipo: Linea, Grosor: 4  esHorizontal: True , Color: 1 
	 Nombre: LineaV , Tipo: Linea, Grosor: 4  esHorizontal: False , Color: 1 
*/
