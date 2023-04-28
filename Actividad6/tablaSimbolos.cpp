#include "tablaSimbolos.h"


// Inserta un nuevo símbolo en la tabla de símbolos
    void insertarSimbolo(map<string, InformacionSimbolo> &TablaSimbolos, string nombre, InformacionSimbolo info) {
        //TablaSimbolos.insert(make_pair(nombre, info));
        TablaSimbolos[nombre] = info;
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
    void mostrarTabla(map<string, InformacionSimbolo> TablaSimbolos, FILE *fp) {

        for (auto const& [nombre, info] : TablaSimbolos) {
           

            switch(info.d){
                case Real:
                fprintf(fp,"Nombre: %s , Tipo: Real, Valor: %f \n",nombre.c_str(),info.valor_float) ;
                break;

                case Entero:
               fprintf(fp,"Nombre: %s , Tipo: Entero, Valor: %d \n",nombre.c_str(),info.valor_int) ;
                break;
                case Bool:
                cout<<info.valor_bool;
               fprintf(fp,"Nombre: %s , Tipo: Logico, Valor: %s \n",nombre.c_str(),(info.valor_bool==true)?"True":"False") ;
                break;
            }
        }
    }