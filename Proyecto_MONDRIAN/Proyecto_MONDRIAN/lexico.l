%{
#include "mondrian.h"
#include "tablaSimbolos.h"
#include <math.h>

//Jesus Castaño Tato , Asier Serrano Martín
int n_lineas;
std::map<std::string, InformacionSimbolo> tablaSimbolos;
%}

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
colores blanco|negro|gris|rojo|azul|amarillo|verde
tipo Entero|Real|Logico 
orientacion vertical|horizontal
fincuadro FINCUADRO

%option noyywrap
%x COM1
%%

[#] { BEGIN(COM1); }
<COM1>"\n" { 
    BEGIN(0); n_lineas++; 
}

\".*\" { strcpy(yylval.var, yytext); return CADENA;}

[\t ]			        ;	
true  {
  //  cout<<"TRue ";
    yylval.c_bool=true; 
    return BOOL;
}   
false {
    //cout<<"False ";
    yylval.c_bool=false; 
    return BOOL;
} 
and           return AND;
or              return OR;
not           return NOT;
div  return DIV;

{colores}               {
                       
             //           cout<<"COlor ";
                       strcpy(yylval.var, yytext);
                       return COLOR;
                    }
{tipo}               {
                       
                   //     cout<<"Tipo ";
                       strcpy(yylval.var, yytext);
                       return TIPO;
                    }
{orientacion}               {
                       
                      //  cout<<"Orientacion ";
                       strcpy(yylval.var, yytext);
                       return ORIENTACION;
                    }
Si              {
                       
                      //  cout<<"Orientacion ";
                       return SI;
                    }
Si_no              {
                       
                      //  cout<<"Orientacion ";
                       return SINO;
                    }
^{variables}  {
             //   cout<<"VAriable ";
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
       
{entero}		      { 
                        yylval.c_entero = atoi(yytext); 
                   //     cout<<"Entero ";
                        return ENTERO;
                        }
{real}               {
                        yylval.c_real = atof(yytext);
                    //    cout<<"Real ";
                       return REAL;
                    }
Pintar {
        return PINTAR;
}
{pausa} {
        return PAUSA;
}
Mensaje {
        return MENSAJE;
}
{fincuadro} {
        return FINCUADRO;
}
\n			  {
                    n_lineas++; 
                   //cout<<"Saltolinea"<<endl;
                   return SALTOLINEA;
            }
,          {// cout<<"COma ";
            return COMA;
            }
;           { //cout<<"PuntoyCOma ";
return PUNTOYCOMA;
}
:=           {//cout<<"Asignacion ";
 return ASIGNACION;
}
=            {//cout<<"Igual ";
return IGUAL;
}
{identificadorMayuscula}     {
                    strcpy(yylval.var, yytext); 
                  //  cout << "IDENTIFICADOR ";
                    return IDENTIFICADORMAYUSCULA;
                    }
{identificadorMinuscula} {
                    strcpy(yylval.var, yytext); 
                    //  cout << "IDENTIFICADOR ";
                    return IDENTIFICADORMINUSCULA;
                    }   
. 		     return (yytext[0]);

%%
// int main(int argc , char ** argv){
	 
// 	n_lineas = 0;
//   yylex();
//   	return 0;  
// }