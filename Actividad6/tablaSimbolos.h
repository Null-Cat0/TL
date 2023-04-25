#include <iostream>
#include <map>
#include <string.h>
using namespace std;

#ifndef TABLASIMBOLOS_H
# define TABLASIMBOLOS_H

enum TipoDato {
    Real,
    Entero,
    Bool
};

struct InformacionSimbolo{
    TipoDato d;
    float valor_float;
    bool valor_bool;
    int valor_int;
};

// Inserta un nuevo símbolo en la tabla de símbolos
    void insertarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo info);

    // Busca un símbolo en la tabla de símbolos y devuelve su información
    bool buscarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo &info);

    // Actualiza la información de un símbolo existente en la tabla de símbolos
    void actualizarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo info);

    // Elimina un símbolo de la tabla de símbolos
    void eliminarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre);

  // Recorre la tabla de símbolos y muestra su contenido por pantalla
    void mostrarTabla(map<string, InformacionSimbolo> TablaSimbolos);

#endif