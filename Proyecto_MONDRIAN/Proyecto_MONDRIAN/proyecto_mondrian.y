%{
using namespace std;
#include <iostream>
#include "tablaSimbolos.h"
#include <cstring>
#include <typeinfo>



// Jesus Castaño Tato, Asier Serrano Martín			
map<string, InformacionSimbolo> tablaSimbolos;
map<string, InformacionSimbolo> tablaSimbolosLineas;
map<string, InformacionSimbolo> tablaSimbolosRecuadros;
extern int n_lineas;
extern int yylex();

extern FILE* yyin ;
extern FILE* yyout ;

bool errorS = false;
bool condicionalVerdadero = true;
char Tipo_Secuencia[25];
void yyerror(const char* s){      
      // errorS = true;
      // if(strcmp(s,"syntax errorS") == 0){
      //       cout << "errorS sintáctico en la instrucción " << n_lineas +1 <<endl;
            
      // }else{
      //       cout << "En la instrucción "<< n_lineas + 1<< " se ha dado un " << s <<endl;
      // }
      cout << "errorS sintactico en la instruccion " << n_lineas+1 << endl;

} 
int color (char *color)
{
      
      if(strcmp(color,"blanco") ==0)
            return 0;
      if(strcmp(color,"negro")==0)
            return 1;
      if(strcmp(color,"gris")==0)
            return 2;
      if(strcmp(color,"rojo")==0)
            return 3;
      if(strcmp(color,"azul")==0)
            return 4;
      if(strcmp(color,"amarillo")==0)
            return 5;
      if(strcmp(color,"verde")==0)
            return 6;
      return -1;
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
  char text[250];
  float c_real;
  bool c_bool;
  struct {
      float valor;
      bool esReal;
      bool esLogica;
      } c_expresion;
}

%token PINTAR MENSAJE PAUSA ASIGNACION IGUAL VARIABLES RECUADROS  LINEAS   DIV MENOS SALTOLINEA PUNTOYCOMA  COMA CUADRO FINCUADRO SI SINO 

%token <var> IDENTIFICADORMINUSCULA IDENTIFICADORMAYUSCULA  TIPO COLOR ORIENTACION
%token <text> CADENA
%token <c_entero> ENTERO
%token <c_real> REAL
%token <c_bool> BOOL

%type <c_expresion> expr
%type <c_bool> logica

%start all

%left OR
%left AND
%left IGUAL DISTINTO
%left  MENORIGUAL MAYORIGUAL 
%left '+' '-'   /* asociativo por la izquierda, misma prioridad */
%left '*' '/' '%' DIV /* asociativo por la izquierda, prioridad alta */
%left menos  
%left NOT

%nonassoc si_simple
%nonassoc SINO
%%


//-------------------------------------------BLOQUE VARIABLES------------------------------------
all : saltoOpcional zona_variables  zona_recuadros  zona_lineas  inic_creacion_cuadros_nombre    {;}
    ;

zona_variables : 
               | VARIABLES salto inic_definicion{ /*cout << "VARIABLES"<<endl;*/}
               ;

inic_definicion :
              | inic_definicion definicion
              ;

definicion :  TIPO  IDENTIFICADORMINUSCULA ASIGNACION expr PUNTOYCOMA { 
                                                                        InformacionSimbolo info, auxComprobacion;
                                                                         if((strcmp($1,"Real") == 0) &&(!$4.esReal)){
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< $2 <<" no es tipo real y no se le puede asignar un valor entero"<<endl;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                              }else if((strcmp($1,"Entero") == 0) &&($4.esReal))
                                                                              {
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< $2 <<" es de tipo entero y no se le puede asignar un valor real"<<endl;
                                                                                    //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                              }else if((strcmp($1,"Logico") == 0))
                                                                              {
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< $2 <<" es de tipo logico y no se le puede asignar un valor entero o real"<<endl;
                                                                              }

                                                                        if(buscarSimbolo(tablaSimbolos, $2, auxComprobacion))
                                                                        {
                                                                           
                                                                              if((strcmp($1,"Entero") == 0) && auxComprobacion.d==Real){
                                                                                    errorS = true;
                                                                                   cout<<"La variable "<< $2 <<" ha sido definida anteriormente como Real  y no se puede volver a declarar como Entero"<<endl;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                              }else if((strcmp($1,"Real") == 0) && auxComprobacion.d==Entero)
                                                                              {
                                                                                    errorS = true;
                                                                                    cout<<"La variable "<< $2<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Real "<<endl;
                                                                                    //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                              }else if(auxComprobacion.d==Bool)
                                                                              {
                                                                                    cout<<"La variable "<< $2<<" ha sido definida anteriormente como Logica y no se puede volver a declarar como Real o Entero "<<endl;
                                                                              }
                                                                        }


                                                                         if (!errorS){
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
                                                                        //cout<<"Tipo Identificador";
                                                                        errorS = false;
                                                                  } saltoOpcional

           |  TIPO  IDENTIFICADORMINUSCULA ASIGNACION logica PUNTOYCOMA { 
                                                                        InformacionSimbolo info, auxComprobacion;
                                                                        
                                                                      
                                                                              if((strcmp($1,"Real") == 0)){
                                                                                    errorS = true;
                                                                                    cout<<"A una variable de tipo real no se le puede asignar un valor logico"<<endl;
                                                                                    
                                                                              }else if((strcmp($1,"Entero") == 0) )
                                                                              {
                                                                                    errorS = true;
                                                                                   cout<<"A una variable de tipo entero no se le puede asignar un valor logico"<<endl;
                                                                                   
                                                                              }
                                                                        if(buscarSimbolo(tablaSimbolos, $2, auxComprobacion))
                                                                        {
                                                                              if((auxComprobacion.d == Real)){
                                                                                    errorS = true;
                                                                                   cout<<"La variable "<< $2<<" ha sido definida anteriormente como Real y no se puede volver a declarar como Logico "<<endl;
                                                                                    
                                                                              }else if(auxComprobacion.d==Entero) 
                                                                              {
                                                                                    errorS = true;
                                                                                  cout<<"La variable "<< $2<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Logico "<<endl;
                                                                                   
                                                                              }          
                                                                        }
                                                                         if (!errorS){
                                                                              //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                              InformacionSimbolo info, aux;
                                                                                    info.d = Bool;
                                                                                    info.valor_bool = $4;
                                                                              insertarSimbolo(tablaSimbolos, $2, info);
                                                                        }    
                                                                        //cout<<"Tipo Identificador";
                                                                        errorS = false;
                                                                  } saltoOpcional                                                      

           |  TIPO secuencia_de_Identificadores  PUNTOYCOMA  {
                                                                  
                                                                  InformacionSimbolo info, tipoSec;
                                                                   if((strcmp($1,"Real") == 0)){
                                                                              info.d = Real;
                                                                              info.valor_float = 0;
                                                                        }else if((strcmp($1,"Entero") == 0))
                                                                        {
                                                                              info.d = Entero;
                                                                              info.valor_int = 0;
                                                                        }else 
                                                                        {
                                                                              info.d = Bool;
                                                                              info.valor_bool = false; //Todos por defecto estan a falso
                                                                              
                                                                        }
                                                                  list<string> l = buscarSimbolosNoIdentificados(tablaSimbolos); 
                                                                  while (!l.empty()) {
                                                                        string aux = l.front();
                                                                        tablaSimbolos[aux] = info;
                                                                        l.pop_front();
                                                                  }     
                                                                 // cout<<"Tipo secuencia_Identificadores ";
                                                            }saltoOpcional
           |  IDENTIFICADORMINUSCULA ASIGNACION expr PUNTOYCOMA {

                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, $1, auxComprobacion))
                                                                  {
                                                                          
                                                                        if((auxComprobacion.d == Real) &&(!$3.esReal)){
                                                                              errorS = true;
                                                                               cout<<"La variable "<< $1 << " no es tipo real y no se le puede asignar un valor real"<<endl;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&($3.esReal))
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< $1 <<" es de tipo real y no se le puede asignar un valor entero"<<endl;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }else if (auxComprobacion.d == Bool)
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< $1 <<" es de tipo logico y no se le puede asignar un valor entero o real"<<endl;
                                                                        }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                         cout<<"La variable "<< $1<<" no ha sido definida con anterioridad"<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
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
                                                                        //cout<<"Tipo Identificador";
                                                                         errorS = false;
                                                                  } saltoOpcional
<<<<<<< HEAD
            |  IDENTIFICADORMINUSCULA ASIGNACION logica PUNTOYCOMA {

                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, $1, auxComprobacion))
                                                                        {
                                                                              if((auxComprobacion.d == Real)){
                                                                                   errorS = true;
                                                                                   cout<<"La variable "<< $1<<" ha sido definida anteriormente como Real y no se puede volver a declarar como Logico "<<endl;
                                                                                    
                                                                              }else if(auxComprobacion.d==Entero) 
                                                                              {
                                                                                  errorS = true;
                                                                                  cout<<"La variable "<< $1<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Logico "<<endl;
                                                                                   
                                                                              }          
                                                                        }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<"La variable "<< $1<<" no ha sido definida con anterioridad"<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                        InformacionSimbolo info, aux;
                                                                        info.d=Bool;
                                                                        info.valor_bool = $3;
                                                                        insertarSimbolo(tablaSimbolos, $1, info);
                                                                        }    
                                                                        //cout<<"Tipo Identificador";
                                                                         errorS = false;
                                                                  } saltoOpcional           
            | error {}
=======
            | error '\n' {}
>>>>>>> cae1d6656cf1e5e6a572550f2fe86da689b88e6a
           ;
 
secuencia_de_Identificadores :  IDENTIFICADORMINUSCULA {
                                                                  
                                                                  InformacionSimbolo info;

                                                                  if(!buscarSimbolo(tablaSimbolos, $1, info))
                                                                  {
                                                                        info.d=NoIdentificado;
                                                                        insertarSimbolo(tablaSimbolos, $1, info);
                                                                  }else
                                                                  {
                                                                        cout<<"La variable "<< $1 << " ha sido definida anteriormente y no puede volver a ser definida"<<endl;
                                                                  }
                                                                  //cout<<"Identificador PuntYComa ";
                                                      }
                             |  IDENTIFICADORMINUSCULA COMA secuencia_de_Identificadores {
                                                                                          InformacionSimbolo info;
                                                                                         if(!buscarSimbolo(tablaSimbolos, $1, info))
                                                                                          {
                                                                                                info.d=NoIdentificado;
                                                                                                insertarSimbolo(tablaSimbolos, $1, info);
                                                                                          }else
                                                                                          {
                                                                                                  cout<<"La variable "<< $1 << " ha sido definida anteriormente y no puede volver a ser definida"<<endl;
                                                                                          }
                                                                                          //cout<<"Identificador  ";
                                                                                          }
                             ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE RECUADROS-------------------------------------

zona_recuadros : RECUADROS {}  salto  inic_definicion_recuadro {/*cout<<"RECUADROS"<<endl;*/}  
               ;
inic_definicion_recuadro :
                        | inic_definicion_recuadro definicion_recuadro
                        ;
definicion_recuadro : IDENTIFICADORMAYUSCULA IGUAL '<' expr  COMA  expr  COMA COLOR '>'   { 
                                                                                          errorS = false;
                                                                                          InformacionSimbolo info, auxComprobacion; 
                                                                                          if($4.esReal | $6.esReal){  
                                                                                                errorS = true;
                                                                                                //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                                                cout<<"La creaciøn de un recuadro necesita dos operandos enteros"<<endl;
                                                                                          }
                                                                                          if (!errorS){ 
                                                                                                //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 

                                                                                                InformacionSimbolo info;
                                                                                                info.d = Recuadro;
                                                                                                info.valores_recuadro.alto = $4.valor;
                                                                                                info.valores_recuadro.ancho = $6.valor;
                                                                                                info.valores_recuadro.color = color($8);
                                                                                                insertarSimbolo(tablaSimbolosRecuadros, $1, info);
                                                                                          }    
                                                                                          errorS = false;
                                                                                    
                                                                                          //fprintf(yyout,"\t %s = <%d, %d, %s>",$1,(int)$4.valor,(int)$6.valor,$8);  
                                                                                          //cout << "Identificador_mayuscula = < Entero, Entero, Color>"<<endl;
                                                                                          } salto
                  | error '\n' {}
                  ;

//------------------------------------------------------------------------------------------------
//-------------------------------------------BLOQUE LINEAS----------------------------------------

zona_lineas : LINEAS  salto inic_definicion_linea {/*cout << "LINEAS"<<endl;*/}
            ;

inic_definicion_linea :
                      | inic_definicion_linea  definicion_linea {}
                      ;



definicion_linea : IDENTIFICADORMAYUSCULA IGUAL  '<' expr  COMA  ORIENTACION  COMA COLOR '>' salto {
                                                                                                                                                                                                                       errorS = false;
                                                                                                InformacionSimbolo info, auxComprobacion; 
                                                                                                if($4.esReal){  
                                                                                                      errorS = true;
                                                                                                      //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                                                }
                                                                                                if (!errorS){ 
                                                                                                      //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl;          
                                                                                                      InformacionSimbolo info;
                                                                                                      info.d = Linea;
                                                                                                      info.valores_linea.grosor = $4.valor;
                                                                                                      info.valores_linea.esHorizontal = (strcmp($6,"horizontal")==0)? true : false  ;
                                                                                                      info.valores_linea.color =  color($8);
                                                                                                      insertarSimbolo(tablaSimbolosLineas, $1, info);
                                                                                                }    
                                                                                                errorS = false; 
                                                                                                //fprintf(yyout,"\t %s = <%d, %s, %s>",$1,(int)$4.valor,$6,$8);   
                                                                                                //cout << "\t Identificador_mayuscula = < Entero, Orientacion, Color>"<<endl;
                                                                                                                              
                                                                                                } //preferimos que haya salto
            | error '\n' {}
            ; 
//------------------------------------------------------------------------------------------------
//----------------------------------BLOQUE CUADROS CREADOS----------------------------------------
//------------------------------------------------------------------------------------------------
inic_creacion_cuadros_nombre:
                        |  inic_creacion_cuadros_nombre creacion_cuadros_nombre {}
                        ;
creacion_cuadros_nombre : CUADRO  CADENA {fprintf(yyout,"\t nuevoCuadroM(%s); \n ",$2);} ':' salto  inic_acciones_cuadros FINCUADRO saltoOpcional  { /* cout<<"Cuadro NombreCuadro :"<<endl; */ } 
                        ;
inic_acciones_cuadros :
                      |   acciones_cuadros  inic_acciones_cuadros {}
                      ;

acciones_cuadros: PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr COMA expr ')'  {
                                                                         if(condicionalVerdadero){
                                                                              if(!$5.esReal && !$7.esReal){  
                                                                                    InformacionSimbolo info;
                                                                                    int filaRecuadro =$5.valor ,columnaRecuadro=$7.valor,altoRecuadro=0,anchoRecuadro=0, color=0;
                                                                                    if(buscarSimbolo(tablaSimbolosRecuadros,$3,info))
                                                                                    {     
                                                                                          altoRecuadro = info.valores_recuadro.alto;
                                                                                          anchoRecuadro = info.valores_recuadro.ancho;
                                                                                          color = info.valores_recuadro.color; 
                                                                                    }else
                                                                                    {
                                                                                          errorS = true;
                                                                                          cout<<"El recuadro indicado no ha sido creado con anterioridad"<<endl;
                                                                                    }
                                                                                    if(!errorS)
                                                                                          fprintf(yyout,"\t rectanguloM(%d, %d, %d, %d, %d); \n",filaRecuadro,columnaRecuadro,altoRecuadro,anchoRecuadro,color); 
                                                                              }else
                                                                              {
                                                                                    cout<<"El valor introducido es real y la funcion pintar precisa de dos valores enteros"<<endl;
                                                                              }                                                                         
                                                                              
                                                                              //cout<<"Pintar (Identificador_mayuscula, Expr,Expr)"<<endl;
                                                                        
                                                                        
                                                                        }
                                                                        }salto
                | PINTAR '(' IDENTIFICADORMAYUSCULA COMA expr ')'   {
                                                                  if(condicionalVerdadero){
                                                                        if(!$5.esReal){  
                                                                              InformacionSimbolo info;
                                                                              int origen=$5.valor,grosor=0, color;
                                                                              bool esHorizontal;
                                                                             
                                                                              if(buscarSimbolo(tablaSimbolosLineas,$3,info))
                                                                              {     
                                                                                    grosor = info.valores_linea.grosor;
                                                                                    esHorizontal = info.valores_linea.esHorizontal;
                                                                                    color = info.valores_linea.color; 
                                                                                    fprintf(yyout,"\t lineaM(%d, %d, %s, %d); \n",origen,info.valores_linea.grosor,(esHorizontal)? "true" : "false",color); 
                                                                              }else{
                                                                                                errorS = true;
                                                                                                cout<<"El recuadro indicado no ha sido creado con anterioridad"<<endl;
                                                                              }
                                                                                    
                                                                             
                                                                        }else
                                                                        {
                                                                              cout<<"El valor introducido es real y la funcion pintar precisa de un valor entero"<<endl;
                                                                        }                                                                             
                                                                              
                                                                  }     
                                                                        //cout<<"Pintar (Identificador_mayuscula, Expr)"<<endl;
                                                                  }salto

                | PAUSA  '('expr ')'  {
                                    if(condicionalVerdadero && !errorS){
                                         
                                                fprintf(yyout,"\t pausaM(%.2f); \n",$3.valor); 
                                         // cout<<"Pausa (expr)"<<endl;
                                    }
                                    errorS = false;
                                    }salto
                | IDENTIFICADORMINUSCULA ASIGNACION expr  { 

                                                            if(condicionalVerdadero){
                                                                  errorS = false;
                                                                  
                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, $1, auxComprobacion))
<<<<<<< HEAD
                                                                  {
                                                                          
                                                                        if((auxComprobacion.d == Real) &&(!$3.esReal)){
                                                                              errorS = true;
                                                                               cout<<"La variable "<< $1 << " no es tipo real y no se le puede asignar un valor real"<<endl;
                                                                              //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&($3.esReal))
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< $1 <<" es de tipo real y no se le puede asignar un valor entero"<<endl;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }else if (auxComprobacion.d == Bool)
                                                                        {
                                                                              errorS = true;
                                                                              cout<<"La variable "<< $1 <<" es de tipo logico y no se le puede asignar un valor entero o real"<<endl;
                                                                        }
                                                                  }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<"La variable "<< $1<<" no ha sido definida con anterioridad"<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
=======
                                                                  {    
                                                                              
                                                                  if((auxComprobacion.d == Real) &&(!$3.esReal)){
                                                                        
                                                                                    errorS = true;
                                                                                    //yyerrok("la variable no es tipo real y no se le puede asignar un valor real");
                                                                        }else if((auxComprobacion.d == Entero) &&($3.esReal))
                                                                        {
                                                                              
                                                                              errorS = true;
                                                                              //yyerrok("la variable  es de tipo real y no se le puede asignar un valor entero");
                                                                        }
                                                                        }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                        {
                                                                              errorS = true;
>>>>>>> cae1d6656cf1e5e6a572550f2fe86da689b88e6a
                                                                  }

                                                                  if (!errorS){ 
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
                                                                  errorS = false;
                                                            }
                                                          } salto
<<<<<<< HEAD

                 |  IDENTIFICADORMINUSCULA ASIGNACION logica  {
                                                             if(condicionalVerdadero){
                                                                  errorS = false;
                                                                  
                                                                  InformacionSimbolo info, auxComprobacion;
                                                                  if(buscarSimbolo(tablaSimbolos, $1, auxComprobacion))
                                                                        {
                                                                              if((auxComprobacion.d == Real)){
                                                                                   errorS = true;
                                                                                   cout<<"La variable "<< $1<<" ha sido definida anteriormente como Real y no se puede volver a declarar como Logico "<<endl;
                                                                                    
                                                                              }else if(auxComprobacion.d==Entero) 
                                                                              {
                                                                                  errorS = true;
                                                                                  cout<<"La variable "<< $1<<" ha sido definida anteriormente como Entero y no se puede volver a declarar como Logico "<<endl;
                                                                                   
                                                                              }          
                                                                        }else // EL simbolo no se encuentra en la tabla de simbolos
                                                                  {
                                                                        cout<<"La variable "<< $1<<" no ha sido definida con anterioridad"<<endl;
                                                                        //cout<<endl<<"ENTRA "<< $1 <<endl;
                                                                        errorS = true;
                                                                  }

                                                                  if (!errorS){ 
                                                                  //    cout << "Instrucción " << n_lineas << ": "  << "La variable " << $1 << ", de tipo " << enteroOreal($3.esReal) << ", toma el valor de " << $3.valor << endl; 
                                                                        InformacionSimbolo info, aux;
                                                                        info.d=Bool;
                                                                        info.valor_bool = $3;
                                                                        insertarSimbolo(tablaSimbolos, $1, info);
                                                                        }    
                                                                        //cout<<"Tipo Identificador";
                                                                         errorS = false;
                                                             }
                                                                  } saltoOpcional       
=======
>>>>>>> cae1d6656cf1e5e6a572550f2fe86da689b88e6a
                | MENSAJE  '('CADENA ')' { 
                                           if(condicionalVerdadero && !errorS){
                                                fprintf(yyout,"\t // %s \n",$3); 
                                           }
                                          errorS = false;
                                          } salto
                | condicional 
<<<<<<< HEAD
                | error {}
=======
                | error '\n' {}
>>>>>>> cae1d6656cf1e5e6a572550f2fe86da689b88e6a
                ;
condicional: parteSi  parteSiNo 
      ;

parteSi: SI '(' logica ')'  {condicionalVerdadero=$3 ; cout <<endl<< condicionalVerdadero<<endl;} '{' saltoOpcional inic_acciones_cuadros saltoOpcional '}'  saltoOpcional
      ;

parteSiNo: %prec si_simple
      | SINO saltoOpcional {condicionalVerdadero = !condicionalVerdadero; }'{' saltoOpcional inic_acciones_cuadros saltoOpcional'}' saltoOpcional{condicionalVerdadero=true;} 
      ;
salto : SALTOLINEA {}
<<<<<<< HEAD
      | SALTOLINEA salto   {}
=======
      | SALTOLINEA salto  {}
>>>>>>> cae1d6656cf1e5e6a572550f2fe86da689b88e6a
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
                                    } else if (info.d = NoIdentificado){
                                          errorS = true;
                                          cout << "Error semantico en la instruccion "<< n_lineas+1 << ", no se pueden utilizar variables sin valor asignado"<<endl;
                                    }  else{
                                          errorS = true;
                                          cout << "Error semantico en la instruccion "<< n_lineas+1 << ", no se pueden usar variables de tipo logico a la derecha de una asignacion"<<endl;
                                    }      
                              }else{
                                    errorS = true;
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
                                    errorS = true;
                                    cout << "Error semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
                              
                        }
     | expr DIV expr        { 
                              $$.esReal = $1.esReal || $3.esReal;
                              if($3.valor != 0){
                                    if($$.esReal) {
                                          errorS = true;
                                          cout << "errorS semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros"<< endl;
                                     } else
                                          $$.valor =  (int) $1.valor / (int) $3.valor;
                              }else{
                                    errorS = true;
                                    cout << "errorS semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
                              }
                              
                        } 

    | expr '%' expr     {
                        $$.esReal = $1.esReal || $3.esReal;
                              if($3.valor != 0){
                                    if($$.esReal){
                                          errorS = true;
                                          cout << "errorS semantico en la instruccion " << n_lineas+1 << ", ambos operandos deben ser enteros"<< endl;
                                    }else
                                          $$.valor =  (int) $1.valor % (int) $3.valor;
                              }else{ 
                                    errorS = true;
                                    cout << "errorS semantico en la instruccion " << n_lineas+1 << ", division por cero"<< endl;
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
      | expr '>' expr {$$ =  ($1.valor > $3.valor);}
      | expr MAYORIGUAL expr {$$ =  ($1.valor >= $3.valor);}
      | expr '<' expr {$$ =  ($1.valor < $3.valor);}
      | '(' logica ')'  {$$ =  $2;}
      ;

%%

int main(int argc, char **argv){
      
      n_lineas = 0;
      yyin = fopen(argv[1],"rt");

      char ficheroSalida[100];
      strcpy(ficheroSalida,argv[1]);
      strcpy(ficheroSalida + strlen(ficheroSalida) -4,".cpp");
      yyout = fopen(ficheroSalida ,"wt");
      fprintf(yyout,"#include \"mondrian.h\" \n");
      fprintf(yyout,"#include <allegro5/allegro5.h> \n");
      fprintf(yyout,"using namespace std; \n");
      fprintf(yyout,"int main(int argc, char **argv){ \n \n");
      
      fprintf(yyout,"\t// Se inicia el entorno gráfico\n");
      fprintf(yyout,"\tiniciarM();\n");
      using namespace std;
      yyparse();
     
      fprintf(yyout,"\t// Se liberan los recursos del entorno gráfico\n");
      fprintf(yyout,"\tterminarM();\n");
      fprintf(yyout,"\n}\n");

      //Descomentar para mostrar los maps de Variables, 
     fprintf(yyout,"\n // Tabla de Simbolos\n");
     mostrarTabla(tablaSimbolos, yyout);
     fprintf(yyout,"\n // Tabla de Simbolos Recuadros \n");
     mostrarTabla(tablaSimbolosRecuadros, yyout);
     fprintf(yyout,"\n // Tabla de Simbolo de Lineas \n");
     mostrarTabla(tablaSimbolosLineas, yyout);
      
      
      fclose(yyout);
      fclose(yyin);
     return 0;
}