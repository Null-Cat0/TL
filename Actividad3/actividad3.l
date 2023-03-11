%{

#include <iostream>
using namespace std;
#include <map>
#include <ctype.h>


std::map<std::string, int> mapa;
int nlineas;
%}
%option noyywrap

digito [0-9]
entero {digito}+
real   {entero}+[.]{entero}*|{entero}*[.]{entero}+[e]*[+]*[-]*{entero}*
identificador [_a-zA-Z][_a-zA-Z0-9]*
cadenas_char ["][^"]*["]
%x COM1 COM2
%%


\n nlineas++; REJECT;

"//"       {BEGIN(COM1);}
<COM1>"\n" {printf("\n"); BEGIN(0); }
"/*"       {BEGIN(COM2);}
<COM2>"*/" {BEGIN(0);}
"/*"       {BEGIN(COM2);}
<COM2>"*/\n" {BEGIN(0);}
<COM1,COM2>. ;

^[ \t]*[\n]* nlineas++;

int|float|return|for|if|else|cout|endl { for(int x=0; x<strlen(yytext);x++)putchar(toupper(yytext[x]));}

{identificador} {mapa.insert({ yytext, (nlineas+1) }); printf("ID"); }
{entero}			  {printf("ENTERO");}	
{real}    			{printf("REAL");}
{cadenas_char}	{printf("TEXTO");}

.					printf(yytext);


%%
int main(int argc , char ** argv){
	 
	nlineas = 0;
	
	 if(argc > 1){
	    yyin = fopen(argv[1],"rt");
      yyout = fopen(argv[2],"rt");
	 }
   else
      yyin = stdin;
	  
  yylex();
  // Get an iterator pointing to the first element in the map
   std::map<std::string, int>::iterator it = mapa.begin();
  // Iterate through the map and print the elements
  cout <<"Lista de identificadores"<< endl;
  while (it != mapa.end())
  {
    cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    ++it;
  }
  cout<<"Numero total de lineas " <<nlineas<<endl;
  	return 0;  
}

