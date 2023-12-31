#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "c_pedidos.h"
#include "c_venta.h"
using namespace std;
Venta::Venta() {
	tiempoactual = time(nullptr);
	Pedido();
   nombre_cliente = nullptr;
   total_venta = 0;
   cantidad_total = 0;
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
   ifstream archivo("../src/Project_0014/data_ped.txt", ios::in);
   int contador;
   array_productos = new VentaProducto[tamaño_array];
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
      if (l_valores.size() == 3) {
         int cantidad = stoi(l_valores[0]);
         const char* nom = l_valores[1].c_str();
         float precio = stof(l_valores[2]);
         
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
         array_productos[tamaño_array - 1] = VentaProducto(cantidad, nom, precio);
         delete [] temp_array;
         
      } else if (l_valores.size() == 1) {
         cantidad_total = stoi(l_valores[0]);
      } else if (l_valores.size() == 7){
         cerr << "ultima linea xd" << line << endl;
         nombre_cliente = l_valores[4].c_str();
         direccion = l_valores[2].c_str();
         telefono = stod(l_valores[5]);
         ruc = stod(l_valores[6]);
      } else {
         cerr << "linea no valida xd" << line << endl;
      }
      contador++;
   }
   archivo.close();
}