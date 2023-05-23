%{
using namespace std;
#include <iostream>
#include "tablaSimbolos.h"
#include <cstring>
#include <typeinfo>



// Jesus Castaño Tato, Asier Serrano Martín			
extern int n_lineas;
extern   map<string, InformacionSimbolo> tablaSimbolos;
extern   map<string, InformacionSimbolo> tablaSimbolosLineas;
extern   map<string, InformacionSimbolo> tablaSimbolosRecuadros;
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

%token PINTAR MENSAJE PAUSA ASIGNACION IGUAL VARIABLES RECUADROS  LINEAS   DIV MENOS SALTOLINEA PUNTOYCOMA  COMA CUADRO FINCUADRO SI SINO

%token <var> IDENTIFICADORMINUSCULA IDENTIFICADORMAYUSCULA CADENA TIPO COLOR ORIENTACION
%token <c_entero> ENTERO
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
all : zona_variables zona_recuadros zona_lineas inic_creacion_cuadros_nombre  {;}
    ;

zona_variables : 
               | VARIABLES{fprintf(yyout,"VARIABLES");} salto inic_definicion{ cout << "VARIABLES"<<endl;}
               ;

inic_definicion :
              | inic_definicion definicion
              ;

definicion :  TIPO  IDENTIFICADORMINUSCULA ASIGNACION expr PUNTOYCOMA { 
                                                                        InformacionSimbolo info, auxComprobacion;
                                                                        if(buscarSimbolo(tablaSimbolos, $2, auxComprobacion))
                                                                        {
                                                                              if((strcmp($1,"Real") == 0) &&(!$4.esReal)){
                                                                                    error = true;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                              }else if((strcmp($1,"Entero") == 0) &&($4.esReal))
                                                                              {
                                                                                    error = true;
                                                                                    //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                              }
                                                                        }


                                                                         if (!error){ 
                                                                        
                                                                              //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                              InformacionSimbolo info, aux;
                                                                              if($4.esReal){
                                                                                    info.d = Real;
                                                                                    info.valor_float = $4.valor;
                                                                              }else{
                                                                                    info.d = Entero;
                                                                                    info.valor_int = $4.valor;
                                                                              }
                                                                              insertarSimbolo(tablaSimbolos, $2, info);
                                                                        }    
                                                                        cout<<"Tipo Identificador";
                                                                        error = false;
                                                                  } saltoOpcional
           |  TIPO secuencia_de_Identificadores  PUNTOYCOMA  {
                                                                  fprintf(yyout,";"); 
                                                                  cout<<"Tipo secuencia_Identificadores ";
                                                            }saltoOpcional
           |  IDENTIFICADORMINUSCULA ASIGNACION expr PUNTOYCOMA {

                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, $1, auxComprobacion))
                                                                  {
                                                                          
                                                                        if((auxComprobacion.d == Real) &&(!$3.esReal)){
                                                                              error = true;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&($3.esReal))
                                                                        {
                                                                              error = true;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                          cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        error = true;
                                                                  }

                                                                  if (!error){ 
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
                                                                        cout<<"Tipo Identificador";
                                                                         error = false;
                                                                  } saltoOpcional
           ;

secuencia_de_Identificadores :  IDENTIFICADORMINUSCULA {
                                                      fprintf(yyout,"%s;",$1); cout<<"Identificador ";cout<<"PuntoYCOma ";
                                                      }
                             |  IDENTIFICADORMINUSCULA COMA secuencia_de_Identificadores {
                                                                                          fprintf(yyout,"%s, ",$1); cout<<"Identificador "; cout<<"Coma ";
                                                                                          }
                             ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE RECUADROS-------------------------------------

zona_recuadros : RECUADROS {fprintf(yyout,"RECUADROS");}  salto  inic_definicion_recuadro {cout<<"RECUADROS"<<endl;}  
               ;
inic_definicion_recuadro :
                        | inic_definicion_recuadro definicion_recuadro
                        ;
definicion_recuadro : IDENTIFICADORMAYUSCULA IGUAL '<' expr  COMA  expr  COMA COLOR '>'   { 
                                                                                          error = false;
                                                                                          InformacionSimbolo info, auxComprobacion; 
                                                                                          if($4.esReal | $6.esReal){  
                                                                                                error = true;
                                                                                                //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                                          }
                                                                                          if (!error){ 
                                                                                                //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                                                
                                                                                                InformacionSimbolo info;
                                                                                                info.d = Recuadro;
                                                                                                info.valores_recuadro.alto = $4.valor;
                                                                                                info.valores_recuadro.ancho = $6.valor;
                                                                                                //info.valores_recuadro.Color = $8;
                                                                                                insertarSimbolo(tablaSimbolosRecuadros, $1, info);
                                                                                          }    
                                                                                          error = false;
                                                                                    
                                                                                          fprintf(yyout,"%s = <%d, %d, %s>",$1,(int)$4.valor,(int)$6.valor,$8);  
                                                                                          cout << "Identificador_mayuscula = < Entero, Entero, Color>"<<endl;
                                                                                          } salto
                  ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE LINEAS----------------------------------------

zona_lineas : LINEAS  {fprintf(yyout,"RECUADROS");}  salto inic_definicion_linea {cout << "LINEAS"<<endl;}
            ;

inic_definicion_linea :
                      | inic_definicion_linea  definicion_linea {}
                      ;



definicion_linea :
                  | IDENTIFICADORMAYUSCULA IGUAL  '<' expr  COMA  ORIENTACION  COMA COLOR '>' salto {
                                                                                                                                                                                                                       error = false;
                                                                                                InformacionSimbolo info, auxComprobacion; 
                                                                                                if($4.esReal){  
                                                                                                      error = true;
                                                                                                      //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                                                }
                                                                                                if (!error){ 
                                                                                                      //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl;          
                                                                                                      InformacionSimbolo info;
                                                                                                      info.d = Linea;
                                                                                                      info.valores_linea.grosor = $4.valor;
                                                                                                      info.valores_linea.esHorizontal = (strcmp($6,"horizontal")==0)? true : false  ;
                                                                                                      //info.valores_recuadro.Color = $8;
                                                                                                      insertarSimbolo(tablaSimbolosLineas, $1, info);
                                                                                                }    
                                                                                                error = false; 
                                                                                                fprintf(yyout,"%s = <%d, %s, %s>",$1,(int)$4.valor,$6,$8);   
                                                                                                cout << "Identificador_mayuscula = < Entero, Orientacion, Color>"<<endl;
                                                                                                                              
                                                                                                } //preferimos que haya salto
            ; 
//------------------------------------------------------------------------------------------------
//----------------------------------BLOQUE CUADROS CREADOS----------------------------------------
//------------------------------------------------------------------------------------------------
inic_creacion_cuadros_nombre:
                        |  inic_creacion_cuadros_nombre creacion_cuadros_nombre {}
                        ;
creacion_cuadros_nombre :
                        | CUADRO  CADENA {fprintf(yyout,"nuevoCuadroM(%s);  ",$2);} ':' salto  inic_acciones_cuadros FINCUADRO salto  { cout<<"Cuadro NombreCuadro :"<<endl;} 
                        ;
inic_acciones_cuadros :
                      |   acciones_cuadros  inic_acciones_cuadros {}
                      ;

acciones_cuadros: PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr COMA expr ')'  {fprintf(yyout,"PINTAR (%s, %d, %d)",$3,(int)$5.valor,(int)$7.valor); cout<<"Pintar (Identificador_mayuscula, Expr,Expr)"<<endl;}salto
                | PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr ')'   {fprintf(yyout,"PINTAR (%s, %d)",$3,(int)$5.valor); cout<<"Pintar (Identificador_mayuscula, Expr)"<<endl;}salto
                | PAUSA  '('expr ')'  {fprintf(yyout,"PAUSA (%d)",(int)$3.valor); cout<<"Pausa (expr)"<<endl;}salto
                | IDENTIFICADORMINUSCULA ASIGNACION expr  { 
                                                            error = false;
                                                            cout<<endl<<"ENTRA"<<endl;
                                                            InformacionSimbolo info, auxComprobacion;
                                                            if(buscarSimbolo(tablaSimbolos, $1, auxComprobacion))
                                                            {    
                                                                  cout<<endl<<"ENTRA simbolo encontrado"<<endl;          
                                                                 if((auxComprobacion.d == Real) &&(!$3.esReal)){
                                                                  cout<<endl<<"ENTRA ERROR 1"<<endl;    
                                                                               error = true;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                  }else if((auxComprobacion.d == Entero) &&($3.esReal))
                                                                  {
                                                                        cout<<endl<<"ENTRA ERROR 2"<<endl;    
                                                                        error = true;
                                                                        //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                  }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        error = true;
                                                            }

                                                            if (!error){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                  cout<<endl<<"ENTRA ACTUALIZAR"<< $1 <<endl;
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
                                                            cout<<"Tipo Identificador";
                                                            error = false;
                                                          
                                                          fprintf(yyout,"%s := %d",$1,(int)$3.valor);  
                                                          cout<<"Identificador_Minuscula Asignacion Expr"<<endl;
                                                          
                                                          } salto
                | MENSAJE  '('CADENA ')' {fprintf(yyout," // %s",$3); cout<<"Mensaje (CADENA)"<<endl;} salto
                | condicional saltoOpcional
                ;

condicional : SI '(' logica ')' '{' acciones_cuadros '}' %prec IF {}
            | SI '(' logica ')' '{' acciones_cuadros '}' SINO '{' acciones_cuadros '}'{}
            ;

salto : SALTOLINEA {fprintf(yyout,"\n");}
      | salto SALTOLINEA {fprintf(yyout,"\n");}
      ;

saltoOpcional : 
       | salto  
       ; 
       
expr: ENTERO               {$$.valor= $1; $$.esReal = false;}
    | REAL 		         {$$.esReal = true ; $$.valor = $1;}  
    | IDENTIFICADORMINUSCULA {
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
      fprintf(yyout, "#include mondrian.h \n" );
      fprintf(yyout,"#include <allegro5/allegro5.h> \n");
      fprintf(yyout,"using namespace std; \n");
      fprintf(yyout,"int main(int argc, char **argv){ \n");
      using namespace std;
      yyparse();
      fprintf(yyout,"}\n");
      mostrarTabla(tablaSimbolos, yyout);
      
      fprintf(yyout,"\n Holiwi");
      mostrarTabla(tablaSimbolosRecuadros, yyout);
      fprintf(yyout,"\n Holiwi");
      mostrarTabla(tablaSimbolosLineas, yyout);
      fclose(yyout);
      fclose(yyin);
     return 0;
}
