//clase_interfaz.h
#include <iostream>
#include "c_venta.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "c_boleta.h"
#include "c_catalogo.h"
#include "c_canales_v.h"
#ifndef C_INTERFAZ_H
#define C_INTERFAZ_H
using namespace std;

class Interfaz {
protected:
	Catalogo catalogo1;
	Pedido Pedido1;	
	CanalesV canales1;
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
public:
	Interfaz(Catalogo& catalogo1, Pedido& Pedido1, CanalesV& canales1, Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
	~Interfaz();
    virtual void menu();
};
#endif