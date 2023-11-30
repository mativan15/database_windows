//clase_catalogo.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"


#ifndef CLASE_INTERFAZ_V_H
#define CLASE_INTERFAZ_V_H
using namespace std;

class Catalogo {
public:
	Pedido Pedido1;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	Catalogo();
	Catalogo(Pedido& Pedido1,Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	~Catalogo();
	void catalogo();
	void print_catalogo(Listas& array_catalogo);
};

#endif