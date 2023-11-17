//clase_factura.h
#include <iostream>
#include <iomanip>
#include <cstring>
#include "clase_pedidos.h"
#include "clase_venta.h"
#ifndef CLASE_FACTURA_H
#define CLASE_FACTURA_H
using namespace std;
class Factura : public Venta {
public:
    char* numero_factura;
    char* fecha;

    Factura(Pedido ped, int cant, char* num_f, char* fec) ;

    ~Factura();

    void mostrarFactura();
};
#endif