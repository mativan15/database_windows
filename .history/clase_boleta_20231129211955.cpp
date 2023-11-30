#include "clase_boleta.h"
using namespace std;
 
Boleta::Boleta(Pedido& ped, int cant, int num_b) : Venta(ped, cant) {
    numero_boleta = num_b;
}

Boleta::~Boleta() {
    cerr << "Destructor de Boleta invocado" << endl;
}

void Boleta::mostrarBoleta() {
    cout << "Numero de boleta: " << numero_boleta << endl;
    Venta::mostrarVenta();
    
}