//c_boleta.h
#include <iostream>
#include "c_pedidos.h"
#include "c_venta.h"
#ifndef C_BOLETA_H
#define C_BOLETA_H
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