#include <iostream>
#include <iomanip>
#include "clase_producto.h"
#ifndef CLASE_LISTAS_H
#define CLASE_LISTAS_H
using namespace std;
class Listas {
public:
    Producto *array_libros_lista;
    int tamano_lista;
    int tipo;
    //int posicion_lista;
    Listas();
    Listas(int tipo);
    //Listas(int tamano_l, char *nombre_archivo);
	/*
    
    void insertar_lista(Producto libro){
        Producto *temp_array = new Producto[tamano_lista];
        for (int i = 0; i < tamano_lista; i++) {
            temp_array[i] = array_libros_lista[i];
        }
        delete [] array_libros_lista;
        array_libros_lista = new Producto[tamano_lista];
        array_libros_lista[tamano_lista - 1] = libro;
        delete [] temp_array;
    }*/
    void print_lista();
    ~Listas();
} ;

#endif