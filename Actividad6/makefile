#Jesús Castaño Tato, Asier Serrano Martín
OBJ = expresiones.o lexico.o tablaSimbolos.o

all : run
run : expresiones
	./expresiones entrada.txt salida.txt
expresiones : $(OBJ)      				#segunda fase de la traducción. Generación del código ejecutable 
	g++ -oexpresiones $(OBJ) 

expresiones.o : expresiones.c        	#primera fase de la traducción del analizador sintáctico
	g++ -c -oexpresiones.o  expresiones.c
	
lexico.o : lex.yy.c						#primera fase de la traducción del analizador léxico
	g++ -c -olexico.o  lex.yy.c 	

expresiones.c : expresiones.y   	#obtenemos el analizador sintáctico en C
	bison -d -v -oexpresiones.c expresiones.y 
	
tablaSimbolos.o : tablaSimbolos.cpp
	g++ -c -o tablaSimbolos.o tablaSimbolos.cpp

lex.yy.c: lexico.l						#obtenemos el analizador léxico en C
	flex lexico.l

clean : 
	rm  -f  *.c *.o 
