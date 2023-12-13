//clase_venta.h
#include <iostream>
#include <ctime> 
#include "c_pedidos.h"
#include "c_v_producto.h"
#ifndef C_VENTA_H
#define C_VENTA_H
using namespace std;
class Venta {
protected:
	time_t tiempoactual;
    const char* nombre_cliente;
    const char* direccion;
    double telefono;
    double ruc;
    float total_venta;
    const Pedido* pedidoPtr;
    int cantidad_total;//?
    VentaProducto* array_productos;
    int tamaño_array;
public:
    Venta();
    void setTiempoactual(time_t tiempact);
	time_t getTiempoactual() const;
    void setPedido(Pedido& ped);
    void setNombre_cliente();
    const char* getNombre_cliente() const;
    void setCantidad(int cant);
    int getCantidad() const;
    void setTotal_venta(float total_v);
    float getTotal_venta() const;
    void setArray_productos();
    VentaProducto* getArray_productos() const;
    virtual void print_comprobante() = 0;
    void insertar_producto(VentaProducto& nuevo_producto);
};

#endif