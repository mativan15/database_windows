//clase_catalogo.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"


#ifndef CLASE_CATALOGO_H
#define CLASE_CATALOGO_H
using namespace std;
class CanalesV;

class Catalogo {
public:
	Pedido* PedidoPtr;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	CanalesV* canalesPtr;

	Catalogo();
	Catalogo(Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	void set_pedidoPtr(Pedido* PedidoPtr);
	void set_canalesPtr(CanalesV* canalesPtr);
	void tab_catalogo();
	void print_catalogo(Listas& array_catalogo);
	Listas* filtrar_producto(int tipo);
};

#endif