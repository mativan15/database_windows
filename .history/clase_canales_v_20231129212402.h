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
class Catalogo;
class CanalesV {
public:
	Pedido* PedidoPtr;
	Catalogo* catalogoPtr;
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	Boleta* boleta1;
	CanalesV();
	CanalesV(Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	void set_catalogoPtr(Catalogo* catalogoPtr);
	void set_pedidoPtr(Pedido* PedidoPtr);
	void set_boleta1(Boleta* boleta1);
	void tab_canales();
	void print_comprobante();
    void libreria(Boleta* boleta1);
};

#endif