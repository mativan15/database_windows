//clase_canales_v.h
#include <iostream>
#include "c_pedidos.h"
#include "c_venta.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "c_boleta.h"
#include "c_factura.h"
#ifndef C_CANALES_V_H
#define C_CANALES_V_H
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
	int cant_lib;
	int max_lib;
	int cant_eco;
	int max_eco;
	int cant_fer;
	int max_fer;
	int cant_dis;
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
    void ingresar_cant_canal(int& cant_atributo, int &cant_max);
};

#endif