#include "c_producto.h"
#ifndef C_V_PRODUCTO_H
#define C_V_PRODUCTO_H

class VentaProducto: public Producto{
private:
    int cantidad;
    float subtotal;
public:
    VentaProducto();
    VentaProducto(int cant_l, const char* nom_l, float prec_l);
    VentaProducto(const VentaProducto& ventaProductocopia);
    void set_cantidad(int cantidad);
    int get_cantidad() const;
    void set_subtotal();
    float get_subtotal() const;
};
#endif