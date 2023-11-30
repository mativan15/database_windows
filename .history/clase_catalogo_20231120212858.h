//clase_catalogo.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "clase_interfaz_v.h"

#ifndef CLASE_CATALOGO_H
#define CLASE_CATALOGO_H
using namespace std;

class Catalogo {
public:
	Pedido Pedido1;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	Catalogo(Pedido& Pedido1,Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	void mostrar_catalogo();
	void print_catalogo(Listas& array_catalogo);
};

#endif