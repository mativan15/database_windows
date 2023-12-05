#include <iostream>
#include "clase_factura.h"
using namespace std;
Factura::Factura() : Venta() {
    numero_factura=0;
}
void Factura::setNumero_factura(int num_f) {
    numero_factura=num_f;
}
int Factura::getNumero_factura() const {
    return numero_factura;
}
void Factura::setRazon_social(char* razon_soc) {
    if (razon_soc != nullptr) {
        if (razon_social != nullptr) {
            delete[] razon_social;
        }
        int largo{0};
        while (razon_soc[largo] != '\0'){
        largo++;
    }
        razon_social = new char[largo + 1];
        if (!razon_social) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            razon_social[i] = razon_soc[i];
        }
        razon_social[largo] = '\0';
    }
}
char* Factura::getRazon_social() const {
    return razon_social;
}
void Factura::print_comprobante() {
    cout << "Número de factura: " << numero_factura << endl;
}

