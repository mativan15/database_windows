#include "clase_producto.h"
#ifndef CLASE_V_PRODUCTO_H
#define CLASE_V_PRODUCTO_H

class VentaProducto: public Producto{
private:
    int cantidad;
    float subtotal;
public:
    VentaProducto();
    void set_cantidad(int cantidad);
    int get_cantidad() const;
    void set_subtotal();
    float get_subtotal() const;
};
#endif