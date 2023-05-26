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
     list<string> buscarSimbolosNoIdentificados(map<string, InformacionSimbolo> TablaSimbolos) {
        list<string> l ;
         string nombre;
        InformacionSimbolo info;
            for (auto const& [nombre, info] : TablaSimbolos) {
                
                if(info.d == NoIdentificado)
                    l.push_front(nombre);
            }
        return l;
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
        fprintf(fp,"/* \n") ;
        for (auto const& [nombre, info] : TablaSimbolos) {
           
    
            switch(info.d){
                case Real:
                fprintf(fp,"\t Nombre: %s , Tipo: Real, Valor: %f \n",nombre.c_str(),info.valor_float) ;
                break;

                case Entero:
               fprintf(fp,"\t Nombre: %s , Tipo: Entero, Valor: %d \n",nombre.c_str(),info.valor_int) ;
                break;
                case Bool:
                cout<<info.valor_bool;
               fprintf(fp,"\t Nombre: %s , Tipo: Logico, Valor: %s \n",nombre.c_str(),(info.valor_bool==true)?"True":"False") ;
                break;

                case Recuadro:
                fprintf(fp,"\t Nombre: %s , Tipo: Recuadro, Alto: %d , Ancho: %d , Color: %d \n",nombre.c_str(),info.valores_recuadro.alto,info.valores_recuadro.ancho,info.valores_recuadro.color) ;
                break;

                case Linea:
                fprintf(fp,"\t Nombre: %s , Tipo: Linea, Grosor: %d  esHorizontal: %s , Color: %d \n",nombre.c_str(),info.valores_linea.grosor,(info.valores_linea.esHorizontal)?"True":"False", info.valores_linea.color) ;
                break;

            }

        }
         fprintf(fp,"*/\n") ;
    }