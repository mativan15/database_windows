//clase_boleta.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#ifndef CLASE_BOLETA_H
#define CLASE_BOLETA_H
using namespace std;

class Boleta : public Venta {
public:
    int numero_boleta;

    Boleta(Pedido ped, int cant, int num_b);

    ~Boleta();

    void mostrarBoleta() ;
};

#endif