#include "clase_producto.h"
#include "wa.h"
#include <iostream>
#include <stdexcept>
using namespace std;
Producto::Producto() {
    codigoISBN = nullptr;
    nombreLibro = nullptr;
    descripcionLib = nullptr;
    nivel = nullptr;
	grado = 0;
    area = nullptr;
    precio = 0;
    stock = 0;
}
Producto::Producto(const char *cod_l, const char *nom_l , const char *desc_l, const char *niv_l, int grad_l, const char *area_l, float pre_l, int sto_l) {
    set_char(codigoISBN, cod_l);
    set_char(nombreLibro, nom_l);
    set_char(descripcionLib, desc_l);
    set_char(nivel, niv_l);
    grado = grad_l;
    set_char(area, area_l);
    precio = pre_l;
    stock = sto_l;
}
Producto::Producto(const Producto& copy) {
    //codigoISBN = copy.codigoISBN;

    grado = copy.grado;

    precio = copy.precio;
    stock = copy.stock;
}
Producto::~Producto(){
	/*delete []codigoISBN;
    cerr << "codigo eliminado xd" << endl;
    delete []nombreLibro;
    cerr << "nimbre eliminado xd" << endl;*/
}

void Producto::set_char(char*& atributo, const char *char_parametro) {
	//cerr << "no se pudo asignar char xd" << endl;
    int largo{0};
    while (char_parametro[largo] != '\0'){
        largo++;
    }
    cerr << largo << endl;
    atributo = new char[largo + 1];
    if (!atributo) {
        cerr << "no se pudo asignar memoria xd" << endl;
    }
    for (int i = 0; i < largo; i++) {
        atributo[i] = char_parametro[i];
    }

    atributo[largo] = '\0'; 
}
