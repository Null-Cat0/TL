%{
#include <iostream>
using namespace std;

//Jesus Castaño Tato , Asier Serrano Martín
int n_lineas;
map<string, InformacionSimbolo> tablaSimbolos

%}

identificador [_a-zA-Z][_a-zA-Z0-9]*

digito [0-9]
entero {digito}+
real ({entero}[.]{entero}?)|({entero}?[.]{entero})([eE][-+]?{entero})?

%option noyywrap
%x COM1
%%

[#] { BEGIN(COM1); }
<COM1>"\n" { BEGIN(0);return COMENTARIO; }
<COM1>. ;


{identificador}     strcpy(yylval.var, yytext); return IDENTIFICADOR;
{entero}		         yylval.c_entero = atoi(yytext); return ENTERO;
{real}               yylval.c_real = atof(yytext); return REAL;
true  yylval.c_bool=true; return BOOL;   
false yylval.c_bool=false; return BOOL;

[E][n][t][e][r][o]  return TIPOENTERO;
[R][e][a][l]        return TIPOREAL;
[L][o][g][i][c][o]  return TIPOLOGICO;


\n				           n_lineas++; return (yytext[0]);
:=            return ASIGNACION;

. 				           return (yytext[0]);

%%