//clase_interfaz.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"

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
    void menu();
	void exe_catalogo();

};

#endif