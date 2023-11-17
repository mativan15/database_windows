#include <iostream>
#include <iomanip>
#ifndef CLASE_LISTAS_H
#define CLASE_LISTAS_H

class Listas {
public:
    Producto *array_libros_lista;
    int tamano_lista;
    int posicion_lista;
    Listas();
    Listas(int tamano_l);
    void insertar_lista(Producto libro){
        Producto *temp_array = new Producto[tamano_lista];
    for (int i = 0; i < tamano_lista; i++) {
        temp_array[i] = array_libros_lista[i];
    }
    delete [] array_libros_lista;
    array_libros_lista = new Producto[tamano_lista];
    array_libros_lista[tamano_lista - 1] = libro;
    delete [] temp_array;
    }
    void print_lista(){
        cout << "\nholaaaa\n" << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Price" << left << setw(8) << "Stock" << endl;

    for (int i = 0; i < 25; i++){
        cout << left << setw(18) << array_libros_lista[i].codigoISBN 
			<< left << setw(38) << array_libros_lista[i].nombreLibro
            << left << setw(20) << array_libros_lista[i].descripcionLib 
			<< left << setw(15) << array_libros_lista[i].nivel
			<< left << setw(12) << array_libros_lista[i].grado
			<< left << setw(22) << array_libros_lista[i].area
			<< left << setw(12) << array_libros_lista[i].precio
            << left << setw(8) << array_libros_lista[i].stock << endl;
    }
    }
    ~Listas();
} ;

#endif