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

%token PINTAR MENSAJE PAUSA COMENTARIO ASIGNACION IGUAL VARIABLES RECUADROS COLOR LINEAS ORIENTACION  DIV MENOS SALTOLINEA PUNTOYCOMA TIPO COMA CUADRO FINCUADRO
%token <c_entero> ENTERO
%token <var> IDENTIFICADORMINUSCULA IDENTIFICADORMAYUSCULA CADENA
%token <c_real> REAL
%token <c_bool> BOOL

%type <c_expresion> expr

%start all

%left OR
%left AND
%left IGUAL DISTINTO ASIGNACION
%left MENOR MENORIGUAL MAYORIGUAL MAYOR
%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%' DIV /* asociativo por la izquierda, prioridad alta */
%left menos  
%left NOT
%%


//-------------------------------------------BLOQUE VARIABLES------------------------------------
all :
    | zona_variables zona_recuadros zona_lineas creacion_cuadros_nombre  {;}
    ;

zona_variables : VARIABLES salto inic_definicion{cout << "VARIABLES"<<endl;}
               ;

inic_definicion :
              | inic_definicion definicion
              ;

definicion :  TIPO  expr asignacion{cout<<"Tipo Identificador";}
           |  TIPO secuencia_de_Identificadores  saltoOpcional {cout<<"Tipo secuencia_Identificadores ";}
           |  expr asignacion{;}
           ;

asignacion : ASIGNACION expr PUNTOYCOMA salto{cout<<"Asignacion  Expr PuntoYComa ";cout<<endl;}
            ;

secuencia_de_Identificadores :  IDENTIFICADORMINUSCULA PUNTOYCOMA{cout<<"Identificador ";cout<<"PuntoYCOma ";}
                             |  IDENTIFICADORMINUSCULA COMA secuencia_de_Identificadores {cout<<"Identificador "; cout<<"Coma ";}
                             ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE RECUADROS-------------------------------------

zona_recuadros : 
               | RECUADROS salto  inic_definicion_recuadro {cout<<"RECUADROS"<<endl;}  
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
definicion_linea : comentario {cout << "Comentario"<<endl;} 
                 | IDENTIFICADORMAYUSCULA IGUAL  '<' expr  COMA  ORIENTACION  COMA COLOR '>' salto {cout << "Identificador_mayuscula = < Entero, Orientacion, Color>"<<endl;} //preferimos que haya salto
                 ;
comentario: COMENTARIO 
          | COMENTARIO salto  comentario
          ;
//------------------------------------------------------------------------------------------------
//----------------------------------BLOQUE CUADROS CREADOS----------------------------------------
//------------------------------------------------------------------------------------------------
creacion_cuadros_nombre :
                        |  creacion_cuadros_nombre CUADRO CADENA  ':' salto  inic_acciones_cuadros FINCUADRO salto  {cout<<"Cuadro NombreCuadro :"<<endl;} 
                        ;
inic_acciones_cuadros :
                      |  acciones_cuadros inic_acciones_cuadros
                      ;
acciones_cuadros: PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr COMA expr ')' saltoOpcional {cout<<"Pintar (Identificador_mayuscula, Expr,Expr)"<<endl;}
                | PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr ')'  saltoOpcional {cout<<"Pintar (Identificador_mayuscula, Expr)"<<endl;}
                | PAUSA  '('expr ')'  saltoOpcional{cout<<"Pausa (expr)"<<endl;}
                | expr ASIGNACION expr saltoOpcional{cout<<"Identificador_Minuscula Asignacion Expr"<<endl;}
                | MENSAJE  '('CADENA ')' saltoOpcional{cout<<"Mensaje (CADENA)"<<endl;}
                | COMENTARIO
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
