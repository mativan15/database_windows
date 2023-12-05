//clase_venta.h
#include <iostream>
#include <ctime> 
#include "clase_pedidos.h"
#include "clase_v_producto.h"
#ifndef CLASE_VENTA_H
#define CLASE_VENTA_H
using namespace std;
class Venta {
private:
	time_t tiempoactual;
protected:
    const char* nombre_cliente;
    float total_venta;
    const Pedido* pedidoPtr;
    int cantidad;
    VentaProducto* array_productos;
    int tamaño_array;
public:
    Venta();
    Venta(time_t tiempact);
    void setTiempoactual(time_t tiempact);
	time_t getTiempoactual() const;
    void setPedido(Pedido& ped);
    void setNombre_cliente();
    const char* getNombre_cliente() const;
    void setCantidad(int cant);
    int getCantidad() const;
    void setTotal_venta(float total_v);
    float getTotal_venta() const;
    void setArray_productos(VentaProducto* array_prod);
    VentaProducto* getArray_productos() const;
    virtual void print_comprobante();
    void insertar_producto(VentaProducto nuevo_producto);
};

#endif