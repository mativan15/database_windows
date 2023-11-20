//wa.h
#include <iostream>
#include <iomanip>
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#ifndef WA_H
#define WA_H

void pantalla_start(Pedido Pedido, Listas lista_has, Listas lista_viv);
void menu(char usuario[64], Pedido Pedido,Listas lista_has, Listas lista_viv);
void caratula();
void catalogo(Pedido Pedido1,Listas lista_has, Listas lista_viv);
void pedidos(Pedido Pedido,Listas lista_has, Listas lista_viv);
void canales_de_venta(Pedido Pedido1,Listas lista_has, Listas lista_viv);
void error_valor();
#endif