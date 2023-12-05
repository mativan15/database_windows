//clase_interfaz.h
#include <iostream>
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "clase_boleta.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"
#ifndef CLASE_INTERFAZ_V_H
#define CLASE_INTERFAZ_V_H
using namespace std;

class InterfazV {
public:
	Catalogo catalogo1;
	Pedido Pedido1;	
	CanalesV canales1;
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	InterfazV(Catalogo& catalogo1, Pedido& Pedido1, CanalesV& canales1, Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	~InterfazV();
    virtual void menu();
};

#endif