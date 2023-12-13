// clase_producto.cpp
#include "c_producto.h"
#include <iostream>
#include <iomanip>
using namespace std;

Producto::Producto() {
    codigoISBN = nullptr;
    nombreLibro = nullptr;
    descripcionLib = nullptr;
    nivel = nullptr;
    grado = 0;
    area = nullptr;
    precio = 0;
	printot = true;
    stock = 0;
}

Producto::Producto(const char* cod_l, const char* nom_l,bool printot_1, const char* desc_l, const char* niv_l, int grad_l, const char* area_l, float pre_l, int sto_l) {
    setCodigoISBN(cod_l);
    setNombreLibro(nom_l);
	setPrintot( printot_1);
    setDescripcionLib(desc_l);
    setNivel(niv_l);
    setGrado(grad_l);
    setArea(area_l);
    setPrecio(pre_l);
    setStock(sto_l);
}

Producto::Producto(const Producto& copy) {
    setCodigoISBN(copy.codigoISBN);
    setNombreLibro(copy.nombreLibro);
	setPrintot(copy.printot);
    setDescripcionLib(copy.descripcionLib);
    setNivel(copy.nivel);
    setGrado(copy.grado);
    setArea(copy.area);
    setPrecio(copy.precio);
    setStock(copy.stock);
}
Producto::Producto(const char* nom_l, float pre_l) {
    cerr << "Constructor de Producto invocado version reducidaaa\n";
    setNombreLibro(nom_l);
    setPrecio(pre_l);
    cerr << nombreLibro << "\n" << precio << endl;
}
Producto::~Producto() {

}

void Producto::setCodigoISBN(const char* cod_l) {
    set_char(codigoISBN, cod_l);
}

const char* Producto::getCodigoISBN() const {
    return codigoISBN;
}

void Producto::setNombreLibro(const char* nom_l) {
    set_char(nombreLibro, nom_l);
}

const char* Producto::getNombreLibro() const {
    return nombreLibro;
}

void Producto::setDescripcionLib(const char* desc_l) {
    set_char(descripcionLib, desc_l);
}

const char* Producto::getDescripcionLib() const {
    return descripcionLib;
}

void Producto::setNivel(const char* niv_l) {
    set_char(nivel, niv_l);
}

const char* Producto::getNivel() const {
    return nivel;
}

void Producto::setGrado(int grad_l) {
    grado = grad_l;
}

int Producto::getGrado() const {
    return grado;
}

void Producto::setArea(const char* area_l) {
    set_char(area, area_l);
}

const char* Producto::getArea() const {
    return area;
}

void Producto::setPrecio(float pre_l) {
    precio = pre_l;
}

float Producto::getPrecio() const {
    return precio;
}

void Producto::setStock(int sto_l) {
    stock = sto_l;
}

int Producto::getStock() const {
    return stock;
}
void Producto::setPrintot(bool printot_1){
	printot =printot_1;
}
bool Producto::getPrintot() const{
	return printot;
}

void Producto::printProducto() const {
    cout << "\n\tResumen Producto: \n\n"
         << "Código ISBN: " << (codigoISBN ? codigoISBN : "N/A") << endl
         << "Nombre del Libro: " << (nombreLibro ? nombreLibro : "N/A") << endl
         << "Descripción del Libro: " << (descripcionLib ? descripcionLib : "N/A") << endl
         << "Nivel: " << (nivel ? nivel : "N/A") << endl
         << "Grado: " << grado << endl
         << "Área: " << (area ? area : "N/A") << endl
         << "Precio: " << precio << endl
         << "Stock: " << stock << endl;
}
void Producto::set_char(char*& atributo, const char *char_parametro) {
    int largo{0};
    while (char_parametro[largo] != '\0'){
        largo++;
    }
    atributo = new char[largo + 1];
    if (!atributo) {
        cerr << "no se pudo asignar memoria xd" << endl;
    }
    for (int i = 0; i < largo; i++) {
        atributo[i] = char_parametro[i];
    }
    atributo[largo] = '\0'; 
}
ostream& operator<<(std::ostream& os, const Producto& obj) {
    os << left << setw(18) << obj.codigoISBN
        << left << setw(38) << obj.nombreLibro
        << left << setw(20) << obj.descripcionLib
        << left << setw(15) << obj.nivel
        << left << setw(12) << obj.grado
        << left << setw(22) << obj.area
        << left << setw(12) << obj.precio
        << left << setw(8) << obj.stock << endl;
    return os;
}