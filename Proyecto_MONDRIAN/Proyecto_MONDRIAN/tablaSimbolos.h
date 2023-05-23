#include <iostream>
#include <map>
#include <string.h>
using namespace std;

#ifndef TABLASIMBOLOS_H
# define TABLASIMBOLOS_H

enum TipoDato {
    Real,
    Entero,
    Bool,
    Recuadro,
    Linea
};

enum Color {
    blanco,
    negro,
    gris,
    rojo,
    azul,
    amarillo,
    verde
};

struct ValoresLinea {
    int grosor;
    bool esHorizontal; //True es horizontal, False es vertical
    Color color;
};
struct ValoresRecuadro {
    int alto;
    int ancho;
    Color color;

};
struct InformacionSimbolo{
    TipoDato d;
    ValoresLinea valores_linea;
    ValoresRecuadro valores_recuadro;
    float valor_float;
    bool valor_bool;
    int valor_int;
};

// Inserta un nuevo símbolo en la tabla de símbolos
    void insertarSimbolo(map<string, InformacionSimbolo> &TablaSimbolos, string nombre, InformacionSimbolo info);

    // Busca un símbolo en la tabla de símbolos y devuelve su información
    bool buscarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo &info);

    // Actualiza la información de un símbolo existente en la tabla de símbolos
    void actualizarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo info);

    // Elimina un símbolo de la tabla de símbolos
    void eliminarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre);

  // Recorre la tabla de símbolos y muestra su contenido por pantalla
    void mostrarTabla(map<string, InformacionSimbolo> TablaSimbolos,FILE *fp);

#endif