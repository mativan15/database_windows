#include <iostream>
#include "clase_v_producto.h"
using namespace std;
VentaProducto::VentaProducto() : Producto() {
    cantidad = 0;
    subtotal = 0;
}
VentaProducto::VentaProducto(const char* nom_l, float prec_l, int cant_l) : Producto(nom_l, prec_l) {// este
    cerr << "VentaProducto constructor lleno" << endl;
    cantidad = cant_l;
    subtotal = prec_l*cant_l;
    cerr << cantidad << "\n " << subtotal << endl;
}
VentaProducto::VentaProducto(const VentaProducto& ventaProductocopia) : Producto(ventaProductocopia) {
    cerr << "VentaProducto constructor copiado" << endl;
    cantidad = ventaProductocopia.cantidad;
    subtotal = ventaProductocopia.subtotal;
}
void VentaProducto::set_cantidad(int cantidad) {
    this->cantidad = cantidad;
}
int VentaProducto::get_cantidad() const {
    return cantidad;
}
void VentaProducto::set_subtotal() {
    subtotal = cantidad*precio;
}
float VentaProducto::get_subtotal() const {
    return subtotal;
}