//clase_producto.h
#include <iostream>
#include <iomanip>
#include <string>
#ifndef CLASE_PRODUCTO_H
#define CLASE_PRODUCTO_H
using namespace std;
class Producto {
public:
    char nombreLibro[50];
	char descripcionLib[100];
	char nivel[20];
	char area[20];
	int grado;
    long long codigoISBN;
    float precio;
    int stock;
	Producto();
    Producto(long long cod_l, const char nom_l, const char desc_l, const char niv_l, int grad_l, const char area_l, float pre_l, int sto_l);
    Producto(const Producto& copy);
    void Producto::setnombreLibro(char *nom_l);
    void Producto::setdescripcionLib(char *desc_l);
    void Producto::setnivel(char *niv_l);
    void Producto::setarea(char *area_l);
};
#endif