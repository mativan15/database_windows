//clase_factura.h
#include <iostream>
#include <iomanip>
#include "clase_pedidos.h"
#include "clase_venta.h"
#ifndef CLASE_FACTURA_H
#define CLASE_FACTURA_H
using namespace std;
class Factura : public Venta {
private:
    int numero_factura;
    char* razon_social;
public:
    Factura();
    void setNumero_factura(int num_f);
    int getNumero_factura() const;
    void setRazon_social(char* razon_soc);
    char* getRazon_social() const;
    void print_comprobante() override;
};
#endif