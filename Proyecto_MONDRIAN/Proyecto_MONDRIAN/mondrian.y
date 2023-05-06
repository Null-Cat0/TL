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
  char var[20];
  float c_real;
  bool c_bool;
  struct {
      float valor;
      bool esReal;
      bool esLogica;
      } c_expresion;
}

%token COMENTARIO ASIGNACION IGUAL VARIABLES RECUADROS COLOR LINEAS ORIENTACION  DIV MENOS SALTOLINEA PUNTOYCOMA TIPO COMA ID
%token <c_entero> ENTERO
%token <var> IDENTIFICADORMINUSCULA 
%token <c_real> REAL
%token <c_bool> BOOL

%type <c_expresion> expr

%start zona_variables

%left '+' '-'   /* asociativo por la izquierda, misma prioridad /
%left '' '/' '%' DIV /* asociativo por la izquierda, prioridad alta */
%left menos


%%


//-------------------------------------------BLOQUE VARIABLES------------------------------------

zona_variables : VARIABLES salto definicion{cout << "VARIABLES"<<endl;}
               ;

definicion :  
           | definicion TIPO {cout<<"Tipo ";}ID{cout<<"Identificador ";}asignacion{;}
           | definicion TIPO{cout<<"Tipo Secuencia ";} secuencia_de_Identificadores  saltoOpcional {;}
           | definicion ID{cout<<"Identificador ";}asignacion{;}
           ;
asignacion :
            |ASIGNACION {cout<<"Asignacion ";}REAL{cout<<"Real ";} PUNTOYCOMA {cout<<"PuntoYComa ";}salto{cout<<endl;}
            |ASIGNACION {cout<<"Asignacion ";}ENTERO{cout<<"Entero ";} PUNTOYCOMA {cout<<"PuntoYComa ";}salto{cout<<endl;}
            |ASIGNACION {cout<<"Asignacion ";}expr{cout<<"Entero ";} PUNTOYCOMA {cout<<"PuntoYComa ";}salto{cout<<endl;}
            ;
secuencia_de_Identificadores : ID PUNTOYCOMA{cout<<"Identificador ";cout<<"PuntoYCOma ";}
                             | secuencia_de_Identificadores ID COMA' '{cout<<"Identificador "; cout<<"Coma ";}
                             ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE RECUADROS-------------------------------------

// zona_recuadros : RECUADROS salto {cout << "Recuadro";}
//                |  definicion_cuadro {;}
//                ;

// definicion_cuadro : IDENTIFICADORMAYUSCULA IGUAL "<" expr"," expr"," COLOR ">" salto {;}//preferimos que haya salto
//                   ;

// //------------------------------------------------------------------------------------------------
// //-------------------------------------------BLOQUE LINEAS----------------------------------------

// zona_lineas : LINEAS salto {cout << "Lineas";}
//             |  definicion_linea {;}
//             ;

// definicion_linea : IDENTIFICADORMAYUSCULA IGUAL "<" expr"," ORIENTACION"," COLOR ">" salto {;}//preferimos que haya salto
//                  ;

//------------------------------------------------------------------------------------------------


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
