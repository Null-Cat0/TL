%{
using namespace std;
#include <iostream>
#include "tablaSimbolos.h"
#include <cstring>
#include <typeinfo>



// Jesus Castaño Tato, Asier Serrano Martín			
extern int n_lineas;
extern   map<string, InformacionSimbolo> tablaSimbolos;
extern int yylex();

extern FILE* yyin ;
extern FILE* yyout ;

bool error = false;
void yyerror(const char* s){      
      // error = true;
      // if(strcmp(s,"syntax error") == 0){
      //       cout << "Error sintáctico en la instrucción " << n_lineas +1 <<endl;
            
      // }else{
      //       cout << "En la instrucción "<< n_lineas + 1<< " se ha dado un " << s <<endl;
      // }
      cout << "Error sintactico en la instruccion " << n_lineas+1 << endl;

} 

string impresionBool(bool a)
{
    return  (a==true) ? "True" : "False";
}   

string enteroOreal(bool enteroOreal)
{
      return (enteroOreal==true) ? "real" : "entero";
}
%}

%union{
  int c_entero;
  char var[25];
  float c_real;
  bool c_bool;
  struct {
      float valor;
      bool esReal;
      bool esLogica;
      } c_expresion;
}

%token PINTAR MENSAJE PAUSA ASIGNACION IGUAL VARIABLES RECUADROS COLOR LINEAS ORIENTACION  DIV MENOS SALTOLINEA PUNTOYCOMA TIPO COMA CUADRO FINCUADRO SI SINO
%token <c_entero> ENTERO
%token <var> IDENTIFICADORMINUSCULA IDENTIFICADORMAYUSCULA CADENA
%token <c_real> REAL
%token <c_bool> BOOL

%type <c_expresion> expr
%type <c_bool> logica

%start all

%left OR
%left AND
%left IGUAL DISTINTO
%left MENOR MENORIGUAL MAYORIGUAL MAYOR
%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%' DIV /* asociativo por la izquierda, prioridad alta */
%left menos  
%left NOT
%nonassoc IF
%nonassoc SINO
%%


//-------------------------------------------BLOQUE VARIABLES------------------------------------
all : zona_variables zona_recuadros zona_lineas creacion_cuadros_nombre  {;}
    ;

zona_variables : 
               | VARIABLES salto inic_definicion{cout << "VARIABLES"<<endl;}
               ;

inic_definicion :
              | inic_definicion definicion
              ;

definicion :  TIPO  IDENTIFICADORMINUSCULA ASIGNACION expr PUNTOYCOMA saltoOpcional{cout<<"Tipo Identificador";}
           |  TIPO secuencia_de_Identificadores  PUNTOYCOMA saltoOpcional {cout<<"Tipo secuencia_Identificadores ";}
           |  IDENTIFICADORMINUSCULA ASIGNACION expr PUNTOYCOMA saltoOpcional{;}
           ;

secuencia_de_Identificadores :  IDENTIFICADORMINUSCULA {cout<<"Identificador ";cout<<"PuntoYCOma ";}
                             |  IDENTIFICADORMINUSCULA COMA secuencia_de_Identificadores {cout<<"Identificador "; cout<<"Coma ";}
                             ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE RECUADROS-------------------------------------

zona_recuadros : RECUADROS salto  inic_definicion_recuadro {cout<<"RECUADROS"<<endl;}  
               ;
inic_definicion_recuadro :
                        | inic_definicion_recuadro definicion_recuadro
                        ;
definicion_recuadro : IDENTIFICADORMAYUSCULA IGUAL '<' expr  COMA  expr  COMA COLOR '>'  salto {cout << "Identificador_mayuscula = < Entero, Entero, Color>"<<endl;}//preferimos que haya salto
                  ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE LINEAS----------------------------------------

zona_lineas : LINEAS  salto inic_definicion_linea {cout << "LINEAS"<<endl;}
            ;

inic_definicion_linea :
                      | inic_definicion_linea definicion_linea
                      ;  
definicion_linea :
                 | IDENTIFICADORMAYUSCULA IGUAL  '<' expr  COMA  ORIENTACION  COMA COLOR '>' salto {cout << "Identificador_mayuscula = < Entero, Orientacion, Color>"<<endl;} //preferimos que haya salto
                 ;
//------------------------------------------------------------------------------------------------
//----------------------------------BLOQUE CUADROS CREADOS----------------------------------------
//------------------------------------------------------------------------------------------------
inic_creacion_cuadros_nombre:
                        |  inic_creacion_cuadros_nombre creacion_cuadros_nombre
                        ;
creacion_cuadros_nombre :
                        | CUADRO CADENA  ':' salto  inic_acciones_cuadros FINCUADRO salto  {cout<<"Cuadro NombreCuadro :"<<endl;} 
                        ;
inic_acciones_cuadros :
                      |  acciones_cuadros inic_acciones_cuadros
                      ;
acciones_cuadros: PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr COMA expr ')' salto {cout<<"Pintar (Identificador_mayuscula, Expr,Expr)"<<endl;}
                | PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr ')'  salto {cout<<"Pintar (Identificador_mayuscula, Expr)"<<endl;}
                | PAUSA  '('expr ')'  salto{cout<<"Pausa (expr)"<<endl;}
                | IDENTIFICADORMINUSCULA ASIGNACION expr salto{cout<<"Identificador_Minuscula Asignacion Expr"<<endl;}
                | MENSAJE  '('CADENA ')' salto{cout<<"Mensaje (CADENA)"<<endl;}
                | condicional saltoOpcional
                ;
condicional : SI '(' logica ')' '{' acciones_cuadros '}' %prec IF {}
            | SI '(' logica ')' '{' acciones_cuadros '}' SINO '{' acciones_cuadros '}'{}
            ;




salto : SALTOLINEA
      | salto SALTOLINEA
      ;

saltoOpcional : 
       | salto 
       ; 

expr: ENTERO               {;}
    | REAL 		         {;}  
    | IDENTIFICADORMINUSCULA   {;}
    | expr '+' expr        {;}              
    | expr '-' expr        {;}            
    | expr '*' expr        {;} 
    | expr '/' expr        {;}
    | expr DIV expr        {;} 
    | expr '%' expr     {;}
    |'-' expr %prec menos  {;}
    | '(' expr ')'         {;}
    ;

logica: BOOL {$$ = $1;}
      | logica AND logica {$$ = $1 && $3;}
      | logica OR logica {$$ = $1 || $3;}
      | NOT logica {$$ = ! ($2);}
      | expr DISTINTO expr {$$ = ($1.valor != $3.valor);}
      | logica DISTINTO logica {$$ = ($1 != $3);}
      | expr IGUAL expr {$$ =  ($1.valor == $3.valor);}
      | logica IGUAL logica {$$ =  ($1 == $3);}
      | expr MENORIGUAL expr {$$ =  ($1.valor <= $3.valor);}
      | expr MAYOR expr {$$ =  ($1.valor > $3.valor);}
      | expr MAYORIGUAL expr {$$ =  ($1.valor >= $3.valor);}
      | expr MENOR expr {$$ =  ($1.valor < $3.valor);}
      | '(' logica ')'  {$$ =  $2;}
      ;
%%

int main(int argc, char **argv){
     
     n_lineas = 0;
     yyin = fopen(argv[1],"rt");
     yyout = fopen("salida.txt","wt");
     yyparse();
     fclose(yyout);
     fclose(yyin);
     return 0;
}
