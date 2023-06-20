#include <iostream>
#include <map>
#include <string.h>
#include <list>
using namespace std;

#ifndef TABLASIMBOLOS_H
# define TABLASIMBOLOS_H
const int BLANCO    = 0;
const int NEGRO     = 1;
const int GRIS		= 2;
const int ROJO      = 3;
const int AZUL      = 4;
const int AMARILLO  = 5;
const int VERDE     = 6;

enum TipoDato {
    Real,
    Entero,
    Bool,
    Recuadro,
    Linea,
    NoIdentificado
};
struct ValoresLinea {
    int grosor;
    bool esHorizontal; //True es horizontal, False es vertical
    int color;
};
struct ValoresRecuadro {
    int alto;
    int ancho;
    int color;

};
struct InformacionSimbolo{
    TipoDato d;
    union 
    {
        ValoresLinea valores_linea;
        ValoresRecuadro valores_recuadro;
    };
    float valor_float;
    bool valor_bool;
    int valor_int;
};

// Inserta un nuevo símbolo en la tabla de símbolos
    void insertarSimbolo(map<string, InformacionSimbolo> &TablaSimbolos, string nombre, InformacionSimbolo info);

    // Busca un símbolo en la tabla de símbolos y devuelve su información
    bool buscarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo &info);

    list<string> buscarSimbolosNoIdentificados(map<string, InformacionSimbolo> TablaSimbolos);

    // Actualiza la información de un símbolo existente en la tabla de símbolos
    void actualizarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo info);

    // Elimina un símbolo de la tabla de símbolos
    void eliminarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre);

  // Recorre la tabla de símbolos y muestra su contenido por pantalla
    void mostrarTabla(map<string, InformacionSimbolo> TablaSimbolos,FILE *fp);

#endif