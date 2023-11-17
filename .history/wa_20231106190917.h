//wa.h
#include <iostream>
#include <iomanip>
#include <string>
#include "clase_pedidos.h"
#include "clase_producto.h"
#ifndef WA_H
#define WA_H
void instanciar_muestras(Producto array_libros_has[], Producto array_libros_viv[]);
void print_tabla_libros(Producto array_libros[]);
void pantalla_start(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido, Listas lista1);;
void menu(Producto array_libros_has[],Producto array_libros_viv[], char usuario[64], Pedido Pedido,Listas lista1);
void caratula();
void catalogo(Producto array_libros_has[], Producto array_libros_viv[],Pedido Pedido1,Listas lista1);
void pedidos(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido,Listas lista1);
void canales_de_venta(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido1,Listas lista1);
void error_valor();
#endif