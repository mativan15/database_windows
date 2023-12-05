//clase_canales_v.h
#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "clase_boleta.h"
#include "clase_factura.h"
#ifndef CLASE_CANALES_V_H
#define CLASE_CANALES_V_H
using namespace std;
class Catalogo;
class CanalesV {
private:
	Pedido* PedidoPtr;
	Catalogo* catalogoPtr;
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
	int cant_total;
	int cant_lib;//llibreria
	int max_lib;
	int cant_eco;//ecomerce
	int max_eco;
	int cant_fer;//feria
	int max_fer;
	int cant_dis;//distribusor
	int max_dis;
	bool bof;
public:
	Venta* ventaPtr;
	CanalesV();
	CanalesV(Listas& lista_has,Listas& lista_viv, Usuario& usuario1);
	void set_catalogoPtr(Catalogo* catalogoPtr);
	void set_pedidoPtr(Pedido* PedidoPtr);
	void set_cant_total(int cant_total);
	void set_cant_lib(int cant_lib);
	void set_cant_eco(int cant_eco);
	void set_cant_fer(int cant_fer);
	void set_cant_dis(int cant_dis);
	int get_cant_total();
	void tab_canales();
	void f_bof();
    void ingresar_cant_canal(int& cant_atributo);
};

#endif