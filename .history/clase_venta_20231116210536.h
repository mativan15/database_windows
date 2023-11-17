//clase_venta.h
#include <iostream>
#include "clase_pedidos.h"
#ifndef CLASE_VENTA_H
#define CLASE_VENTA_H
using namespace std;
class Venta {
public:
    Pedido pedido;
    int cantidad;
    Venta(Pedido ped, int cant) ;
    void mostrarVenta();
};

#endif