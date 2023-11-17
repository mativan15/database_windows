//clase_producto.h
#include <iostream>
#ifndef CLASE_PRODUCTO_H
#define CLASE_PRODUCTO_H

class Producto {
//private:
public:
    char* codigoISBN;
    char* nombreLibro;
	char* descripcionLib;
	char* nivel;
	char* area;
	int grado;
    float precio;
    int stock;
public:
	Producto();
    Producto(const char *cod_l, const char *nom_l, const char *desc_l, const char *niv_l, int grad_l, const char *area_l, float pre_l, int sto_l);
    Producto(const Producto& copy);
	~Producto();
    void set_char(char*& atributo, const char *char_parametro);
};
#endif