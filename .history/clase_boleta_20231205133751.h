//clase_boleta.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#ifndef CLASE_BOLETA_H
#define CLASE_BOLETA_H
using namespace std;

class Boleta : public Venta {
private:
	int dni;
	int numero_boleta;
public:
    Boleta();
    Boleta(Pedido& ped, int num_b, int dnI);
    void setNumero_boleta(int num_b);
	int getNumero_boleta() const;
    void setdni(int dnI);
    int getdnI() const;
    void print_comprobante() override;
};

#endif