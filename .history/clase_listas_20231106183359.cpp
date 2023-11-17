#include <iostream>
#include "clase_listas.h"
#include "clase_producto.h"

Listas::Listas() {
}
Listas::Listas(int tamano_lista) {
    tamano_lista = tamano_lista;
}
void Listas::insertar_lista(Producto libro) {
    Producto *temp_array = new Producto[tamano_lista];
    for (int i = 0; i < tamano_lista; i++) {
        temp_array[i] = array_libros_lista[i];
    }
    delete [] array_libros_lista;
    array_libros_lista = new Producto[tamano_lista];
    delete [] temp_array;
}
Listas::~Listas() {

}