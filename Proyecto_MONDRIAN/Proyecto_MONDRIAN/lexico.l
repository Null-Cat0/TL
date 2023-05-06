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
variables [V][A][R][I][A][B][L][E][S]
recuadros RECUADROS
cuadro CUADRO
lineas LINEAS
pausa  [P][a][u][s][a]
color [b][l][a][n][c][o]|[n][e][g][r][o]|[g][r][i][s]|[r][o][j][o]|[a][z][u][l]|[a][m][a][r][i][l][l][o]|[v][e][r][d][e]
tipo Entero|Real|Logico 
orientacion [v][e][r][t][i][c][a][l]|[h][o][r][i][z][o][n][t][a][l]


%option noyywrap
%x COM1 COM2
%%

[#] { BEGIN(COM1); }
<COM1>"\n" { 
    BEGIN(0); n_lineas++; 
            return COMENTARIO; 
}

["]       {BEGIN(COM2);}
<COM2>["] {BEGIN(0); return CADENA;}
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
{color}               {
                       
             //           cout<<"COlor ";
                       return COLOR;
                    }
{tipo}               {
                       
                   //     cout<<"Tipo ";
                       return TIPO;
                    }
{orientacion}               {
                       
                      //  cout<<"Orientacion ";
                       return ORIENTACION;
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