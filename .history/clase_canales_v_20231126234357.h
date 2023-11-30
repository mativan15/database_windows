//clase_canales_v.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "clase_boleta.h"

#ifndef CLASE_CANALES_V_H
#define CLASE_CANALES_V_H
using namespace std;

class CanalesV {
public:
	Pedido Pedido1;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	CanalesV(Pedido& Pedido1,Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	void tab_canales(InterfazV vendedor1);
	void print_comprobante();
    void libreria(Boleta boleta1);
};

#endif