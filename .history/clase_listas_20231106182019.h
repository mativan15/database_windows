#include <iostream>
#ifndef CLASE_LISTAS_H
#define CLASE_LISTAS_H

class Listas {
public:
    Producto *array_libros_lista;
    int tamano_lista;
    int posicion_lista;
    Listas();
    Listas(int tamano_l);
    void insertar_lista(Producto libro);
    ~Listas();
} ;

#endif