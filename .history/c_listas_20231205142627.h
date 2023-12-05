#include <iostream>
#include <iomanip>
#include "c_producto.h"
#ifndef C_LISTAS_H
#define C_LISTAS_H
using namespace std;
class Listas {
private:
    Producto *array_libros_lista;
    int tamano_lista;
    int tipo;
    int posicion_lista;
public:
    Listas();
    Listas(int tipo);
    void print_lista();
    int get_tamano_lista();
    int get_tipo();
    int get_posicion_lista();
    Producto get_elemento(int index);
    const Producto* get_array() const;
    ~Listas();
    void añadir_elemento(Producto& producto);
} ;

#endif