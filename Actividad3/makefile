# Jesús Castaño Tato, Asier Serrano Martin
salida.txt : actividad3	entrada.txt
	./actividad3 entrada.txt > salida.txt
actividad3 : lex.yy.c
	g++ -o  actividad3 lex.yy.c
lex.yy.c : actividad3.l
	flex actividad3.l
clean:
	rm  -f lex.yy.c actividad3 salida.txt


