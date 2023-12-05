//clase_factura.h
#include <iostream>
#include <iomanip>
#include "c_pedidos.h"
#include "c_venta.h"
#ifndef C_FACTURA_H
#define C_FACTURA_H
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