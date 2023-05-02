/**

 Teoría de lenguajes
 Curso 2022/2023

 Nombre: mondrian.h
 Descripción: Implementación de la librería gráfica para el lenguaje MONDRIAN
 Autor:	Profesorado de la asignatura
 Fecha:	07/04/2023

 */


#ifndef MONDRIAN_H_
#define MONDRIAN_H_

#include <iostream>
#include <string>

using namespace std;


/*
 * DESCRIPCIÓN: Colores usados
*/
const int BLANCO    = 0;
const int NEGRO     = 1;
const int GRIS		= 2;
const int ROJO      = 3;
const int AZUL      = 4;
const int AMARILLO  = 5;
const int VERDE     = 6;

/*
 *	DESCRIPCIÓN: Inicia el entorno gráfico. Abre una ventana con nombre "Mondrian" en la parte superior
 */
void iniciarM ();


/*
 *	DESCRIPCIÓN: Cierra la ventana. Libera los recursos usados por el entorno gráfico
 */
void terminarM ();


/*
 * PRE: {s >= 0}
 * DESCRIPCIÓN: Detiene la ejecución durante s segundos
 */
void pausaM(float s);


/*
 * DESCRIPCIÓN: Limpia la ventana y la deja en blanco. Usa título como nombre de la ventana en la parte superior
 */
void nuevoCuadroM (string titulo);


/*
 * PRE = {0<=fila, columna, ancho <100; 0 <= color <= 6}
 * DESCRIPCIÓN: dibuja un rectángulo del color indicado cuya esquina superior izquierda está en (fila, columna) y
 *              el alto y ancho indicados.
 */
void rectanguloM(int fila, int columna, int alto, int ancho, int color);


/*
 * PRE = {0<= origen <100; 0 <= grosor <= 100, 0 <= color <= 6}
 * DESCRIPCIÓN: dibuja una línea del color indicado, del grosor indicado, en horizontal o vertical (según
 * 				esHorizontal sea true o false), a partir de la posición de origen (fila o columna).
 */
void lineaM(int origen, int grosor, bool esHorizontal, int color);


#endif
