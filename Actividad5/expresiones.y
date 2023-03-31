%{
#include <iostream>
#include <math.h>

using namespace std;

//Elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
bool error = false;
//Procedimientos auxiliares
void yyerror(const char* s){         /*    llamada por cada error sintactico de yacc */
	cout << "Error en la línea "<< n_lineas<<endl;	
      error = true;
} 

void prompt(){
  	cout << "LISTO> ";
}

%}

%union{
  int c_entero;
  char var[20];
  float c_real;
  struct {
      float valor;
      bool esReal;
      } c_expresion;
}

%start entrada
%token SALIR
%token <c_entero> NUMERO
%token <var> ID
%token <var> DIV
%token <c_real> REAL
%type <c_expresion> expr

%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%' DIV /* asociativo por la izquierda, prioridad alta */

%left menos

%%
entrada: 		{prompt();}
      |entrada linea
      ;
linea: SALIR '\n'	{return(0);	}         
      |ID '=' expr '\n' {cout << "A la variable " << $1 << " se le asigna el valor " << $3.valor << endl; prompt();}
      |error '\n' {yyerrok; prompt();}
      ;

expr: NUMERO               {$$.valor= $1; $$.esReal = false;}
    | REAL 		         {$$.esReal = true ; $$.valor = $1;}                      
    | expr '+' expr        {$$.valor = $1.valor + $3.valor; if($1.esReal || $3.esReal ) $$.esReal = true;}              
    | expr '-' expr        {$$.valor = $1.valor - $3.valor; if($1.esReal || $3.esReal ) $$.esReal = true;}            
    | expr '*' expr        {$$.valor = (float) $1.valor * (float) $3.valor; if($1.esReal || $3.esReal ) $$.esReal = true;} 
    | expr '/' expr        { 
                              $$.esReal = $1.esReal || $3.esReal;
                              if($3.valor != 0){
                                    $$.valor =  $1.valor / $3.valor;
                              }else yyerror("Error semantico, división por 0");
                              
                        }
     | expr DIV expr        { 
                              $$.esReal = $1.esReal || $3.esReal;
                              if($3.valor != 0){
                                    if($$.esReal) 
                                          yyerror("Error semantico");
                                    else
                                          $$.valor =  (int) $1.valor / (int) $3.valor;
                              }else yyerror("Error semantico, división por 0");
                              
                        } 

    | expr '%' expr     {
                        if(!$1.esReal && !$3.esReal && $3.valor != 0)
                              $$.valor=(int)$1.valor % (int) $3.valor; 
                        else yyerror("Error semantico, necesario dos operandos enteros");
                        $$.esReal = false;
                        }
    | expr '^' expr        {$$.valor = pow($1.valor, $3.valor); if($1.esReal || $3.esReal ) $$.esReal = true;} 
    |'-' expr %prec menos  {$$.valor = - ($2.valor); if($2.esReal) $$.esReal = true;}
    | '(' expr ')'         {$$.valor = $2.valor; if($2.esReal) $$.esReal = true;}
    ;

%%

int main(){
     
     n_lineas = 0;
     
     cout <<endl<<"******************************************************"<<endl;
     cout <<"*      Calculadora de expresiones aritméticas        *"<<endl;
     cout <<"*                                                    *"<<endl;
     cout <<"*      1)con el prompt LISTO>                        *"<<endl;
     cout <<"*        teclea una expresión, por ej. 1+2<ENTER>    *"<<endl;
     cout <<"*        Este programa indicará                      *"<<endl;
     cout <<"*        si es gramaticalmente correcto              *"<<endl;
     cout <<"*      2)para terminar el programa                   *"<<endl;
     cout <<"*        teclear SALIR<ENTER>                        *"<<endl;
     cout <<"*      3)si se comete algun error en la expresión    *"<<endl;
     cout <<"*        se mostrará un mensaje y la ejecución       *"<<endl;
     cout <<"*        del programa finaliza                       *"<<endl;
     cout <<"******************************************************"<<endl<<endl<<endl;
     yyparse();
     cout <<"****************************************************"<<endl;
     cout <<"*                                                  *"<<endl;
     cout <<"*                 ADIOS!!!!                        *"<<endl;
     cout <<"****************************************************"<<endl;
     return 0;
}