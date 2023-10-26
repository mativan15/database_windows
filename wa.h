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

class Pedido {
public:
    string nombreCole;
	string direccionCole;
	string emailCole;
	string nombreResp;
	int numTele;
    long long codigoCole;
    long long codigoRUC;
	Pedido() {
        nombreCole = "";
        direccionCole = "";
        emailCole = "";
        nombreResp = "";
        numTele = 0;
        codigoCole = 0;
        codigoRUC = 0;
    }
    Pedido (string nom_col, string dir_col, string em_col, string nom_res, int num_tel, long long cod_col, long long cod_ruc){
        nombreCole = nom_col;
        direccionCole = dir_col;
        emailCole = em_col;
        nombreResp = nom_res;
        numTele = num_tel;
        codigoCole = cod_col;
        codigoRUC = cod_ruc;
    }
};

void instanciar_muestras(Producto array_libros_has[], Producto array_libros_viv[]);
void print_tabla_libros(Producto array_libros[]);
void pantalla_start(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido);
void menu(Producto array_libros_has[],Producto array_libros_viv[], string usuario, Pedido Pedido);
void caratula();
void catalogo(Producto array_libros_has[], Producto array_libros_viv[]);
void pedidos(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido);
void canales_de_venta();
void error_valor();
#endif