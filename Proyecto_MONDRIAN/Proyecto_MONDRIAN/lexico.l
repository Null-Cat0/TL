%{
#include "proyecto_mondrian.h"
#include "tablaSimbolos.h"
#include <math.h>

//Jesus Castaño Tato , Asier Serrano Martín
int n_lineas;
%}
cadena ["].*["]  
identificadorMinuscula [a-z][_a-zA-Z0-9]*
identificadorMayuscula [A-Z][_a-zA-Z0-9]*
digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?
variables VARIABLES
recuadros RECUADROS
cuadro CUADRO
lineas LINEAS
pausa  Pausa
pintar Pintar
mensaje Mensaje
colores blanco|negro|gris|rojo|azul|amarillo|verde
tipo Entero|Real|Logico 
orientacion vertical|horizontal
fincuadro FINCUADRO

%option noyywrap
%%



Si { return SI;}
Si_no { return SINO;}
#.*\n { n_lineas++;} 
{cadena} { strcpy(yylval.var, yytext); return CADENA;}
[\t ]			        ;	
true  {
 
    yylval.c_bool=true; 
    return BOOL;
}   
false {
    yylval.c_bool=false; 
    return BOOL;
} 
and           return AND;
or              return OR;
not           return NOT;
div  return DIV;


{colores}            {
                       strcpy(yylval.var, yytext);
                       return COLOR;
                    }
{tipo}               {
                       strcpy(yylval.var, yytext);
                       return TIPO;
                    }
{orientacion}               {
                       strcpy(yylval.var, yytext);
                       return ORIENTACION;
                    }
^{variables}  {
                return VARIABLES;
                }
^{recuadros}   {
                return RECUADROS;
                }
^{lineas}   {
                return LINEAS;
                }
^{cuadro}   {
                return CUADRO;
                }
       
{entero} { 
                        yylval.c_entero = atoi(yytext); 
                        return ENTERO;
                }
{real}  {
                        yylval.c_real = atof(yytext);
                       return REAL;
                    }
{pintar} {
        return PINTAR;
}
{pausa} {
        return PAUSA;
}
{mensaje} {
        return MENSAJE;
}
{fincuadro} {
        return FINCUADRO;
}
\n {
                    n_lineas++; 
                   return SALTOLINEA;
            }
,          {
            return COMA;
            }
;           { 
                return PUNTOYCOMA;
        }
:=           {
                return ASIGNACION;
        }
=            {
                return IGUAL;
        }
\>=                return MAYORIGUAL;
\<=                return MENORIGUAL;
\==                return IGUAL;
\!=                return DISTINTO;
{identificadorMayuscula}     {
                    strcpy(yylval.var, yytext); 
                    return IDENTIFICADORMAYUSCULA;
                    }
{identificadorMinuscula} {
                    strcpy(yylval.var, yytext); 
                    return IDENTIFICADORMINUSCULA;
                    }   
. 		     return (yytext[0]);

%%
