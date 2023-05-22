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

void prompt(){
  	cout << "LISTO> ";
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

%start entrada
%token SALIR DIV AND OR NOT MENOR MAYORIGUAL MAYOR MENORIGUAL IGUAL DISTINTO ASIGNACION COMENTARIO

%token <c_entero> NUMERO
%token <var> ID
%token <c_real> REAL
%token <c_bool> BOOL

%type <c_expresion> expr
%type <c_bool> logica


%left OR
%left AND
%left IGUAL DISTINTO
%left MENOR MENORIGUAL MAYORIGUAL MAYOR
%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%' DIV /* asociativo por la izquierda, prioridad alta */
%left menos  
%left NOT

%%

entrada:{ error = false;  }
      |entrada linea 
      ;
linea: ID ASIGNACION expr '\n' { 
                                    InformacionSimbolo info, auxComprobación;
                                    if(buscarSimbolo(tablaSimbolos, $1, auxComprobación))
                                    {
                                         if($3.esReal && (auxComprobación.d != Real )){
                                                error = true;
                                                //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                         }else if(!$3.esReal&& (auxComprobación.d == Real ))
                                          {
                                                error = true;
                                                //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                          }
                                    }
                                    if (!error  ){ 
                                        
                                     //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                         InformacionSimbolo info, aux;
                                         
                                         if($3.esReal){
                                          info.d = Real;
                                          info.valor_float = $3.valor;
                                         }else{
                                          info.d = Entero;
                                          info.valor_int = $3.valor;
                                         }
                                         insertarSimbolo(tablaSimbolos, $1, info);

                                    }    
                                      error = false;       
                                    //prompt();
                                    }
      |ID ASIGNACION expr COMENTARIO { 
                                    InformacionSimbolo info, auxComprobación;
                                    if(buscarSimbolo(tablaSimbolos, $1, auxComprobación))
                                    {
                                          
                                         if($3.esReal && (auxComprobación.d == Entero )){
                                                error = true;
                                                cout << "Error semantico en la instruccion "<< n_lineas<< ", la variable '" << $1 << "' es de tipo entero y no se le puede asignar un valor real"<< endl;
                                         }else if(!$3.esReal && (auxComprobación.d == Real ))
                                          {
                                                error = true;
                                                cout << "Error semantico en la instruccion "<< n_lineas<< ", la variable '" << $1 << "' es de tipo real y no se le puede asignar un valor entero"<< endl;
                  
                                          }
                                    }
                                    if (!error  ){ 
                                        
                                        // cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                         InformacionSimbolo info, aux;
                                         
                                         if($3.esReal){
                                          info.d = Real;
                                          info.valor_float = $3.valor;
                                         }else{
                                          info.d = Entero;
                                          info.valor_int = $3.valor;
                                         }
                                         insertarSimbolo(tablaSimbolos, $1, info);

                                    }    
                                             error = false;
                                    //prompt();
                                    }

      |ID ASIGNACION logica COMENTARIO{
                                     if (!error){ 
                                        
                                        // cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo logico," << " toma el valor " << impresionBool($3) << endl;
                                         InformacionSimbolo info, aux;
                                         info.d = Bool;
                                         info.valor_bool =$3;
                                         if(buscarSimbolo(tablaSimbolos, $1, aux)){
                                                tablaSimbolos[$1] = info;
                                         }else{
                                                tablaSimbolos[$1] = info;
                                         }
                                          
                                          }
                                          error = false;
                                          //prompt();
                                    }    

      |ID ASIGNACION logica '\n' {
                                     if (!error){ 
                                        
                                       //  cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo logico," << " toma el valor " << impresionBool($3) << endl;
                                         InformacionSimbolo info, aux;
                                         info.d = Bool;
                                         info.valor_bool =$3;
                                         if(buscarSimbolo(tablaSimbolos, $1, aux)){
                                                tablaSimbolos[$1] = info;
                                         }else{
                                                tablaSimbolos[$1] = info;
                                         }
                                          
                                          }
                                          error = false;
                                          //prompt();
                                    }    
      |error '\n' {yyerrok; }
      |error COMENTARIO {yyerrok; }
      ;

expr: NUMERO               {$$.valor= $1; $$.esReal = false;}
    | REAL 		         {$$.esReal = true ; $$.valor = $1;}  
    | ID                   {
      
                              InformacionSimbolo info;
                              if(buscarSimbolo(tablaSimbolos, $1, info)){
                                    if(info.d == 0){// si es real
                                          $$.valor = info.valor_float;
                                          $$.esReal = true;
                                    } else if(info.d == 1){ // es entero
                                          $$.valor = info.valor_int;
                                          $$.esReal = false;
                                    } else{
                                          error = true;
                                      cout << "Error semantico en la instruccion "<< n_lineas+1 << ", no se pueden usar variables de tipo logico a la derecha de una asignacion"<<endl;
                                    }      
                              }else{
                                    error = true;
                                    cout << "Error en la instruccion "<< n_lineas+1 << ", la variable utilizada '"<< $1 << "' no existe"<<endl;
                              }

                         }
    | expr '+' expr        {$$.valor = $1.valor + $3.valor;  $$.esReal = $1.esReal || $3.esReal ;}              
    | expr '-' expr        {$$.valor = $1.valor - $3.valor; $$.esReal = $1.esReal || $3.esReal ;}            
    | expr '*' expr        {$$.valor = (float) $1.valor * (float) $3.valor; $$.esReal = $1.esReal || $3.esReal ;} 
    | expr '/' expr        { 
                              $$.esReal = true;
                              if($3.valor != 0){
                                    $$.valor =  (float)$1.valor / (float)$3.valor;
                              }else{
                                    error = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
                              
                        }
     | expr DIV expr        { 
                              $$.esReal = $1.esReal || $3.esReal;
                              if($3.valor != 0){
                                    if($$.esReal) {
                                          error = true;
                                          cout << "Error semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros"<< endl;
                                     } else
                                          $$.valor =  (int) $1.valor / (int) $3.valor;
                              }else{
                                    error = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
                              
                        } 

    | expr '%' expr     {
                        $$.esReal = $1.esReal || $3.esReal;
                              if($3.valor != 0){
                                    if($$.esReal){
                                          error = true;
                                          cout << "Error semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros"<< endl;
                                    }else
                                          $$.valor =  (int) $1.valor % (int) $3.valor;
                              }else{ 
                                    error = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
    }
    |'-' expr %prec menos  {$$.valor = - ($2.valor);  $$.esReal = $2.esReal;}
    | '(' expr ')'         {$$.valor = $2.valor; $$.esReal = $2.esReal;}
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

     cout <<endl<<"******************************************************"<<endl;
     cout <<"*      Calculadora de expresiones aritméticas        *"<<endl;
     cout <<"*                                                    *"<<endl;
     cout <<"******************************************************"<<endl<<endl<<endl;
     yyparse();
     cout <<"****************************************************"<<endl;
     cout <<"*                                                  *"<<endl;
     cout <<"*                 ADIOS!!!!                        *"<<endl;
     cout <<"****************************************************"<<endl;
     mostrarTabla(tablaSimbolos, yyout);
     fclose(yyout);
     fclose(yyin);
     return 0;
}
