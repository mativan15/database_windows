//wa.h
#include <iostream>
#include <iomanip>
#include <string>
#ifndef WA_H
#define WA_H
using namespace std;
class Producto {
public:
    string nombreLibro;
	string descripcionLib;
	string nivel;
	string area;
	int grado;
    int codigoISBN;
    int precio;
    int stock;
	Producto() {
        nombreLibro = "";
        descripcionLib = "";
        nivel = "";
        area = "";
		grado = 0;
        codigoISBN = 0;
        precio = 0;
        stock = 0;
    }
    Producto (string nom_l, string desc_l, string niv_l, string area_l, int grad_l, int cod_l, int pre_l, int sto_l){
        nombreLibro = nom_l;
		descripcionLib = desc_l;
		nivel = niv_l;
		area = area_l;
		grado = grad_l;
		codigoISBN = cod_l;
		precio = pre_l;
		stock = sto_l;
    }
};
void instanciar_muestras(Producto array_libros[]);
void print_tabla_libros(Producto array_libros[]);
void pantalla_start(Producto array_libros[]);
void menu(Producto array_libros[]);
void caratula();
void catalogo(Producto array_libros[]);
void pedidos();
void canales_de_venta();

#endif