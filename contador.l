%{
/*
 *      Este programa cuenta el número de caracteres, palabras y líneas
 *      que hay en un texto
 */

#include <iostream>
using namespace std;

int n_caracteres, n_palabras,  n_lineas;      /* variables globales: contadores */
%}

%option noyywrap

%%

\n               	 n_lineas++;    //la primera regla detecta el fin de una línea e incrementa el contador de las líneas

[A-Za-z0-9ñÑ]+      {n_palabras++;  //la segunda regla detecta una palabra e incrementa 
			  		 n_caracteres = n_caracteres + yyleng;}     //los contadores de palabras y caracteres



%%
int main(){
	n_caracteres = 0;   //inicialización de los contadores
	n_palabras = 0;
	n_lineas = 0;
  	
	yylex();    //llamada al analizador léxico
  	
	cout <<endl<<"Número de caracteres: "<< n_caracteres<<endl;    //se muestra el valor de los contadores tras el proceso
  	cout <<"Número de palabras: "<< n_palabras<<endl;
  	cout <<"Número de líneas: "<< n_lineas<<endl;
  	
  	return 0;  
}
