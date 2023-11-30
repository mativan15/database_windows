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
    void print_lista();
    int get_tamano_lista();
    const Producto* get_array() const;
    ~Listas();
} ;

#endif