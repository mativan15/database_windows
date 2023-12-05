//c_catalogo.h
#include <iostream>
#include "c_pedidos.h"
#include "c_venta.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_usuario.h"
#ifndef C_CATALOGO_H
#define C_CATALOGO_H
using namespace std;
class CanalesV;
class Catalogo {
public:
	Pedido* PedidoPtr;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	CanalesV* canalesPtr;
	Listas productos_anadidos;
	Catalogo();
	Catalogo(Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	void set_pedidoPtr(Pedido* PedidoPtr);
	void set_canalesPtr(CanalesV* canalesPtr);
	void tab_catalogo();
	void print_catalogo(Listas& array_catalogo);
	void filtrar_producto(int tipo);
};

#endif