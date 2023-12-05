#include "clase_v_producto.h"

VentaProducto::VentaProducto() : Producto() {
    cantidad = 0;
    subtotal = 0;
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