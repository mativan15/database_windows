//clase_producto.h
#include <iostream>
#include <iomanip>
#include <string>
#ifndef CLASE_PRODUCTO_H
#define CLASE_PRODUCTO_H
using namespace std;
class Producto {
public:
    string nombreLibro;
	string descripcionLib;
	string nivel;
	string area;
	int grado;
    long long codigoISBN;
    float precio;
    int stock;
	Producto() {
        codigoISBN = 0;
        nombreLibro = "";
        descripcionLib = "";
        nivel = "";
		grado = 0;
        area = "";
        precio = 0;
        stock = 0;
    }
    Producto (long long cod_l, string nom_l, string desc_l, string niv_l, int grad_l, string area_l, float pre_l, int sto_l){
        codigoISBN = cod_l;
        nombreLibro = nom_l;
		descripcionLib = desc_l;
		nivel = niv_l;
        grado = grad_l;
		area = area_l;
		precio = pre_l;
		stock = sto_l;
    }
};
#endif