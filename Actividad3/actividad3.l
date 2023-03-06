%{

#include <iostream>
using namespace std;
#include <map>



std::map<std::string, int> mapa;
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
{identificador}		{cout<<"ID"; mapa[yytext]=1;}
{entero}			{cout<<"ENTERO";}	
{real}    			{cout<<"REAL";}								
{cadenas_char}		{cout<<"TEXTO";}
^[\n]				;
[\n]				cout<<"\n";
"/*"				{BEGIN(COM1);}
<COM1>"*/"			{BEGIN(0);}
"//"      			 BEGIN(COM2);
<COM2>"\n" 			{BEGIN(0); 
					cout<<"\n";}
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
	  
 
  // Get an iterator pointing to the first element in the map
   std::map<std::string, int>::iterator it = mapa.begin();
  // Iterate through the map and print the elements
  while (it != mapa.end())
  {
    cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    ++it;
  }
  	return 0;  
}

