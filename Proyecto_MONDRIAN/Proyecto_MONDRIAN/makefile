#Jesús Castaño Tato, Asier Serrano Martín
OBJ = proyecto_mondrian.o lexico.o tablaSimbolos.o
FUENTE = entrada.cpp

all : run fin

fin: prueba
	./prueba 

run : proyecto_mondrian 
	./proyecto_mondrian entrada.mon
proyecto_mondrian : $(OBJ)      				#segunda fase de la traducción. Generación del código ejecutable 
	g++ -o proyecto_mondrian $(OBJ) 

proyecto_mondrian.o : proyecto_mondrian.c        	#primera fase de la traducción del analizador sintáctico
	g++ -c -o proyecto_mondrian.o  proyecto_mondrian.c
	
lexico.o : lex.yy.c					#primera fase de la traducción del analizador léxico
	g++ -c -olexico.o  lex.yy.c 	

proyecto_mondrian.c : proyecto_mondrian.y   	#obtenemos el analizador sintáctico en C
	bison -d -v -o proyecto_mondrian.c proyecto_mondrian.y 
	
tablaSimbolos.o : tablaSimbolos.cpp
	g++ -c -o tablaSimbolos.o tablaSimbolos.cpp

lex.yy.c: lexico.l						#obtenemos el analizador léxico en C
	flex lexico.l

prueba : prueba.o mondrian.o 
	g++ -oprueba mondrian.o prueba.o -lallegro -lallegro_primitives -lallegro_main    

mondrian.o : mondrian.cpp
	g++ -c mondrian.cpp

prueba.o : $(FUENTE)
	g++ -c -oprueba.o $(FUENTE) 

clean : 
	rm  -f  *.c *.o proyecto_mondrian proyecto_mondrian.output proyecto_mondrian.h prueba entrada.cpp