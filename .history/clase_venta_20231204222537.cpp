#include <iostream>
#include <fstream>
#include "clase_pedidos.h"
#include "clase_venta.h"
using namespace std;
Venta::Venta() {
	tiempoactual=0;
	Pedido();
   nombre_cliente = nullptr;
   total_venta = 0;
   cantidad = 0;
   tamaño_array = 0;
   array_productos = nullptr;
}   
void Venta::setTiempoactual(time_t tiempact) {
   tiempoactual = tiempact;
}
time_t Venta::getTiempoactual() const {
   return tiempoactual;
}
void Venta::setPedido(Pedido& ped) {
   pedidoPtr = &ped;
}
void Venta::setNombre_cliente() {
   nombre_cliente = pedidoPtr->getNombreCole();
}
VentaProducto* Venta::getArray_productos() const{
   return array_productos;
}
const char* Venta::getNombre_cliente() const{
   return nombre_cliente;
}

void Venta::print_comprobante() {
   cout << "Datos del pedido" << endl
	   << "Tiempo de venta: " << asctime(localtime(&tiempoactual))<< endl;
}
void Venta::insertar_producto(VentaProducto& nuevo_producto) {
   VentaProducto *temp_array = new VentaProducto[tamaño_array];
   for (int i = 0; i < tamaño_array; i++) {
        temp_array[i] = array_productos[i];
   }
   delete [] array_productos;
   tamaño_array++;
   array_productos = new VentaProducto[tamaño_array];
   for (int i = 0; i < tamaño_array - 1; i++) {
        array_productos[i] = temp_array[i];
   }
   array_productos[tamaño_array - 1] = nuevo_producto;
   delete [] temp_array;
}
void Venta::setArray_productos() {
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
            array_libros_lista[tamano_lista - 1] = Producto(cod, nom, descr, nivel, grado, area, precio, stock);
            delete [] temp_array;
            
        } else {
            cerr << "error en el numero de valores xd" << line << endl;
        }
        contador++;
    }
    archivo.close();
}