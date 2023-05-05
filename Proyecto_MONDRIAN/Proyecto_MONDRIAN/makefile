#Jesús Castaño Tato, Asier Serrano Martín
OBJ = mondrian.o lexico.o tablaSimbolos.o

all : run
run : mondrian
	./mondrian entrada.txt salida.txt
mondrian : $(OBJ)      				#segunda fase de la traducción. Generación del código ejecutable 
	g++ -o mondrian $(OBJ) 

mondrian.o : mondrian.c        	#primera fase de la traducción del analizador sintáctico
	g++ -c -omondrian.o  mondrian.c
	
lexico.o : lex.yy.c					#primera fase de la traducción del analizador léxico
	g++ -c -olexico.o  lex.yy.c 	

mondrian.c : mondrian.y   	#obtenemos el analizador sintáctico en C
	bison -d -v -omondrian.c mondrian.y 
	
tablaSimbolos.o : tablaSimbolos.cpp
	g++ -c -o tablaSimbolos.o tablaSimbolos.cpp

lex.yy.c: lexico.l						#obtenemos el analizador léxico en C
	flex lexico.l

clean : 
	rm  -f  *.c *.o mondrian mondrian.output mondrian.h