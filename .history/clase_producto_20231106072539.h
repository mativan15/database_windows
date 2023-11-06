//clase_producto.h
#include <iostream>
#include <iomanip>
#include <string>
#ifndef CLASE_PRODUCTO_H
#define CLASE_PRODUCTO_H
using namespace std;
class Producto {
public:
    char nombreLibro[128];
	char descripcionLib[128];
	char nivel[128];
	char area[128];
	int grado;
    long long codigoISBN;
    float precio;
    int stock;
	Producto();
    Producto(long long cod_l, const char nom_l, const char desc_l, const char niv_l, int grad_l, const char area_l, float pre_l, int sto_l);
    Producto(const Producto& copy);
};
#endif