%{

#include <iostream>
using namespace std;

%}

%option noyywrap

digito [0-9]
entero {digito}+
real   {entero}+[.]{entero}*|{entero}*[.]{entero}+[e]*[+]*[-]*{entero}*
identificador [_a-zA-Z][_a-zA-Z0-9]*
cadenas_char ["][^"]*["]
%x COM1 COM2
%%
int     {cout<<"INT"; }
float   {cout<<"FLOAT";}
return  {cout<<"RETURN";}
for     {cout<<"FOR";}
if      {cout<<"IF";}
else    {cout<<"ELSE";}
{identificador}		{cout<<"ID";}
{entero}			{cout<<"ENTERO";}	
{real}    			{cout<<"REAL";}								
{cadenas_char}		{cout<<"TEXTO";}
^[\n]				;
[\n]				cout<<"\n";
"/*"				{BEGIN(COM1);}
<COM1>"*/"			{BEGIN(0);}
"//"       BEGIN(COM2);
<COM2>"\n" {BEGIN(0); cout<<"\n";}
<COM1,COM2>.		
.					printf (yytext);
[A-Za-z0-9ñÑ]+      {}

%%
int main(int argc , char ** argv){
	//  if(argc == 2){
	//     yyin = fopen(argv[1],"rt");
    //     yyout = fopen(argv[2],"rt");
	// 	yylex();
    
	// }
	yylex();
  	return 0;  
}

