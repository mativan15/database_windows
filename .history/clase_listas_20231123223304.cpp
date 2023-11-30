#include <sstream>
#include <string>
#include <vector>
#include "clase_listas.h"
#include "clase_producto.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
Listas::Listas(){
    array_libros_lista = nullptr;
    tamano_lista = 0;
    cerr << "constructor nulo listas xd\n";
}
Listas::Listas(int tipo) {
    array_libros_lista = nullptr;
    int contador {0};
    ifstream archivo;
    if (tipo==1){
        tamano_lista = 45;
        archivo.open("../src/Project_0013/data_has.txt", ios::in);
    } else {
        tamano_lista = 80;
        archivo.open("../src/Project_0013/data_viv.txt", ios::in);
    }
    array_libros_lista = new Producto [tamano_lista];
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    string line;
    while (getline(archivo, line)) {
        vector<string> l_valores;
        istringstream iss(line);
        string dato;
        while (getline(iss, dato, ',')) {
            l_valores.push_back(dato);
        }
        if (l_valores.size() == 8) {
            const char* cod = l_valores[0].c_str();
            const char* nom = l_valores[1].c_str();
            const char* descr = l_valores[2].c_str();
            const char* nivel = l_valores[3].c_str();
            int grado = stoi(l_valores[4]);
            const char* area = l_valores[5].c_str();
            double precio = stod(l_valores[6]);
            int stock = stoi(l_valores[7]);
            array_libros_lista[contador] = Producto(cod, nom, descr, nivel, grado, area, precio, stock);
        } else {
            cerr << "error en el numero de valores xd" << line << endl;
        }
        contador++;
    }
    archivo.close();
}
    
Listas::~Listas() {
    cerr << "destructor de clase_listas" << endl;
    //delete [] array_libros_lista;
}
void Listas::print_lista(){
    cout << tamano_lista << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;

    for (int i = 0; i < tamano_lista; i++){
        cout << left << setw(18) << array_libros_lista[i].getCodigoISBN()
                << left << setw(38) << array_libros_lista[i].getNombreLibro()
                << left << setw(20) << array_libros_lista[i].getDescripcionLib() 
                << left << setw(15) << array_libros_lista[i].getNivel()
                << left << setw(12) << array_libros_lista[i].getGrado()
                << left << setw(22) << array_libros_lista[i].getArea()
                << left << setw(12) << array_libros_lista[i].getPrecio()
                << left << setw(8) << array_libros_lista[i].getStock() << endl;
    }
}