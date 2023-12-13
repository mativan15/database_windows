#include <sstream>
#include <string>
#include <vector>
#include "c_listas.h"
#include "c_producto.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
Listas::Listas(){
    array_libros_lista = nullptr;
    tamano_lista = 0;
    tipo = 0;
    cerr << "constructor nulo listas xd\n";
}
Listas::Listas(int tipo) {
    array_libros_lista = nullptr;
    int contador {0};
    tamano_lista = 0;
    this->tipo = tipo;
    ifstream archivo;
    if (tipo==1){
        archivo.open("../src/Project_0013/data_has.txt", ios::in);
    } else {
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
            
            Producto *temp_array = new Producto[tamano_lista];
            for (int i = 0; i < tamano_lista; i++) {
                temp_array[i] = array_libros_lista[i];
            }
            delete [] array_libros_lista;
            tamano_lista++;
            array_libros_lista = new Producto[tamano_lista];
            for (int i = 0; i < tamano_lista - 1; i++) {
                array_libros_lista[i] = temp_array[i];
            }
            array_libros_lista[tamano_lista - 1] = Producto(cod, nom,true, descr, nivel, grado, area, precio, stock);
            delete [] temp_array;
            
        } else {
            cerr << "error en el numero de valores xd" << line << endl;
        }
        contador++;
    }
    archivo.close();
}
    
Listas::~Listas() {
    cerr << "destructor de clase_listas" << endl;
    if (array_libros_lista!= nullptr){
        delete [] array_libros_lista;
        array_libros_lista = nullptr;
    }
}
void Listas::print_lista(){
    cout << "\t" << left << setw(8) << "Index" << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
    for (int i = 0; i < tamano_lista; i++){
        if(array_libros_lista[i].getPrintot()){
            cout << "\t" << left << setw(8) << i+1 << array_libros_lista[i];
		}else{
			continue;
		}
    }
}


int Listas::get_tamano_lista(){
    return tamano_lista;
}
int Listas::get_tipo() {
    return tipo;
}
const Producto* Listas::get_array() const {
    return array_libros_lista;
}
int Listas::get_posicion_lista() {
    return posicion_lista;
}
Producto Listas::get_elemento(int index){
    return array_libros_lista[index];
}
void Listas::añadir_elemento(Producto& nuevo_producto){
    Producto *temp_array = new Producto[tamano_lista];
    for (int i = 0; i < tamano_lista; i++) {
        temp_array[i] = array_libros_lista[i];
    }
    delete [] array_libros_lista;
    tamano_lista++;
    array_libros_lista = new Producto[tamano_lista];
    for (int i = 0; i < tamano_lista - 1; i++) {
        array_libros_lista[i] = temp_array[i];
    }
    array_libros_lista[tamano_lista - 1] = nuevo_producto;
    delete [] temp_array;
}