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

      if(s=="syntax error"){
            cout << "Error sintáctico en la instrucción " << n_lineas <<endl;
            error = true;
      }else{
            cout << "En la instrucción "<< n_lineas<< " se ha dado un " << s <<endl;
            error = true;
      }
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
      } c_expresion;
}

%start entrada
%token SALIR DIV AND OR NOT MENOR MAYORIGUAL MAYOR MENORIGUAL IGUAL DISTINTO ASIGNACION

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
entrada: 		{prompt();}
      |entrada linea
      ;
linea: SALIR '\n'	{return(0);	}         
      |ID ASIGNACION expr '\n' {cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; prompt();}
      |ID ASIGNACION logica '\n' {cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo logico," << " toma el valor " << impresionBool($3) << endl; prompt();}
      |error '\n' {yyerrok; prompt();}
      ;

expr: NUMERO               {$$.valor= $1; $$.esReal = false;}
    | REAL 		         {$$.esReal = true ; $$.valor = $1;}                      
    | expr '+' expr        {$$.valor = $1.valor + $3.valor;  $$.esReal = $1.esReal || $3.esReal ;}              
    | expr '-' expr        {$$.valor = $1.valor - $3.valor; $$.esReal = $1.esReal || $3.esReal ;}            
    | expr '*' expr        {$$.valor = (float) $1.valor * (float) $3.valor; $$.esReal = $1.esReal || $3.esReal ;} 
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
                                          yyerror("Error semantico, necesario dos operandos enteros");
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
    | expr '^' expr        {$$.valor = pow($1.valor, $3.valor); $$.esReal = $1.esReal || $3.esReal ;} 
    |'-' expr %prec menos  {$$.valor = - ($2.valor);  $$.esReal = $2.esReal;}
    | '(' expr ')'         {$$.valor = $2.valor; $$.esReal = $2.esReal;}
    ;
logica: BOOL {$$ = $1;}
      | logica AND logica {$$ = $1 && $3;}
      | logica OR logica {$$ = $1 || $3;}
      | NOT logica {$$ = ! ($2);}
      | expr DISTINTO expr {$$ = ($1.valor != $3.valor);}
      | expr IGUAL expr {$$ =  ($1.valor == $3.valor);}
      | expr MENORIGUAL expr {$$ =  ($1.valor <= $3.valor);}
      | expr MAYOR expr {$$ =  ($1.valor > $3.valor);}
      | expr MAYORIGUAL expr {$$ =  ($1.valor >= $3.valor);}
      | expr MENOR expr {$$ =  ($1.valor < $3.valor);}
      | '(' logica ')'  {$$ =  $2;}
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
