#include <iostream>
#include "clase_factura.h"
using namespace std;
    
	
Factura::Factura(Pedido ped, int cant, char* num_f, char* fec) : Venta(ped, cant) {
        numero_factura = new char[strlen(num_f) + 1];
        strcpy(numero_factura, num_f);

        fecha = new char[strlen(fec) + 1];
        strcpy(fecha, fec);
    }

Factura::~Factura(){
	
}

 void Factura::mostrarFactura() {
        mostrarVenta();
        cout << "Número de factura: " << numero_factura << std::endl;
        cout << "Fecha: " << fecha << std::endl;
}

