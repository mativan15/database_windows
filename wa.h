//wa.h
#include <iostream>
#include <iomanip>
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#ifndef WA_H
#define WA_H
void instanciar_muestras(Producto array_libros_has[], Producto array_libros_viv[]);
void print_tabla_libros(Producto array_libros[]);
void pantalla_start(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido, Listas lista_has, Listas lista_viv);
void menu(Producto array_libros_has[],Producto array_libros_viv[], char usuario[64], Pedido Pedido,Listas lista_has, Listas lista_viv);
void caratula();
void catalogo(Producto array_libros_has[], Producto array_libros_viv[],Pedido Pedido1,Listas lista_has, Listas lista_viv);
void pedidos(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido,Listas lista_has, Listas lista_viv);
void canales_de_venta(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido1,Listas lista_has, Listas lista_viv);
void error_valor();
#endif