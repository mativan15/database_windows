//clase_interfaz.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "clase_boleta.h"

#ifndef CLASE_INTERFAZ_V_H
#define CLASE_INTERFAZ_V_H
using namespace std;

class InterfazV {
public:
	Pedido Pedido1;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	InterfazV();
	InterfazV(Pedido& Pedido1,Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	~InterfazV();
    void menu(InterfazV vendedor1);
	void exe_catalogo(InterfazV vendedor1);
	void exe_pedidos(InterfazV vendedor1);
	void exe_canales(InterfazV vendedor1);

};

#endif