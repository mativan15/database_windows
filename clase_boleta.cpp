#include "clase_boleta.h"
using namespace std;
 
Boleta::Boleta(Pedido* ped, int cant, int num_b) : Venta(ped, cant) {
    numero_boleta = num_b;
 }

Boleta::~Boleta() {
    }

void Boleta::mostrarBoleta() {
    mostrarVenta();
    cout << "Número de boleta: " << numero_boleta << endl;
}