#include <iostream>
#include "clase_listas.h"
#include "clase_producto.h"

Listas::Listas() {
}
Listas::Listas(int tamano_l) {
    tamano_lista = tamano_l;
    array_libros_lista = new Producto [10];
    array_libros_lista[0] = Producto(1234567890123, "Matematica - Crecemos J.", "Lib. Act.", "Primaria", 1, "Matematica", 69.9, 2349);
	array_libros_lista[1] = Producto(2345678901234, "Ciencias Naturales - Aprendemos", "Lib. Tex.", "Primaria", 2, "Ciencias Naturales", 150.0, 1357);
	array_libros_lista[2] = Producto(3456789012345, "Lenguaje - Saber C.", "Lib. Tex.", "Secundaria", 3, "Lenguaje", 129.5, 1132);
	array_libros_lista[3] = Producto(4567890123456, "Geografia - Aprendemos", "Pack", "Primaria", 4, "Geografia", 60.0, 1598);
	array_libros_lista[4] = Producto(5678901234567, "Ciencias Naturales - Crecemos J.", "Pack", "Secundaria", 5, "Ciencias Naturales", 99.9, 1783);
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