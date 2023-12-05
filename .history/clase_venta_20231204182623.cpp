#include <iostream>

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
Venta::Venta(time_t tiempact){
   setTiempoactual(tiempact);
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