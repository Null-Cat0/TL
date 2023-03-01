%{
/*
 *      Este programa cuenta el número de caracteres, palabras y líneas
 *      que hay en un texto
 */

#include <iostream>
using namespace std;

int n_caracteres, n_palabras,  n_lineas, n_palabras_reservadas, n_enteros, n_cadenas_caracteres, n_lineas_blanco, n_real, n_identificador, 
	n_lineas_informacion;      /* variables globales: contadores */
%}

%option noyywrap
digito [0-9]
entero {digito}+
real   {entero}+[.]{entero}*|{entero}*[.]{entero}+[e]*[+]*[-]*{entero}*
identificador [_a-zA-Z][_a-zA-Z0-9]*
cadenas_char ["][^"]*["]

%%x COM1, COM2
%%
int     {print("INT");}
float   {print("FLOAT");}
return  {print("RETURN");}
for     {print("FOR");}
if      {print("IF");}
else    {print("ELSE");}
{identificador}		{print("ID");}
{entero}			{print("ENTERO");}	
{real}    			{print("REAL");}								
{cadenas_char}		{print"TEXTO"}
^[\n]				{
					n_lineas_blanco++;
					n_palabras++;
					n_caracteres = n_caracteres + yyleng;}
^[\t\n]					n_lineas_informacion++;
.					;
[A-Za-z0-9ñÑ]+      {n_palabras++;  //la segunda regla detecta una palabra e incrementa 
			  		 n_caracteres = n_caracteres + yyleng;}     //los contadores de palabras y caracteres



%%
int main(){
	n_caracteres = 0;   //inicialización de los contadores
	n_palabras = 0;
	n_lineas = 0;
  	n_palabras_reservadas = 0;
	n_enteros = 0;
	n_real=0;
	n_cadenas_caracteres=0;
	n_lineas_informacion=0;
	yylex();    //llamada al analizador léxico
  	
	cout <<"Número de palabras reservadas: "<< n_palabras_reservadas<<endl;
	cout <<"Número de identificadores: "<< n_identificador<<endl;
	cout <<"Número de enteros: "<< n_enteros<<endl;
	cout <<"Número de reales: "<< n_real<<endl;
	cout <<"Número de cadenas de caracteres: "<< n_cadenas_caracteres<<endl;
  	cout <<"Número de lineas en blanco: "<< n_lineas_blanco<<endl;
  	cout <<"Número de lineas con informacion: "<< n_lineas_informacion<<endl;
  	return 0;  
}

