#include "tablaSimbolos.h"


// Inserta un nuevo símbolo en la tabla de símbolos
    void insertarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo info) {
        TablaSimbolos.insert(make_pair(nombre, info));
    }

    // Busca un símbolo en la tabla de símbolos y devuelve su información
    bool buscarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo &info) {
        if (TablaSimbolos.count(nombre) > 0) {
            info = TablaSimbolos[nombre];
            return true;
        } else {
            return false;
        }
    }

    // Actualiza la información de un símbolo existente en la tabla de símbolos
    void actualizarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre, InformacionSimbolo info) {
        if (TablaSimbolos.count(nombre) > 0) {
            TablaSimbolos[nombre] = info;
        } else {
            // Manejo de error si el símbolo no existe
        }
    }

    // Elimina un símbolo de la tabla de símbolos
    void eliminarSimbolo(map<string, InformacionSimbolo> TablaSimbolos, string nombre) {
        if (TablaSimbolos.count(nombre) > 0) {
            TablaSimbolos.erase(nombre);
        } else {
            // Manejo de error si el símbolo no existe
        }
    }

  // Recorre la tabla de símbolos y muestra su contenido por pantalla
    void mostrarTabla(map<string, InformacionSimbolo> TablaSimbolos) {
        for (auto const& [nombre, info] : TablaSimbolos) {
            cout << "Nombre: " << nombre << ", Tipo: " << info.d << ", Valor: " ;

            switch(info.d){
                case Real:
                cout<<info.valor_float<<endl;
                break;

                case Entero:
                cout<<info.valor_int<<endl;
                break;

                case Bool:
                cout<<info.valor_bool<<endl;
                break;
            }
        }
    }