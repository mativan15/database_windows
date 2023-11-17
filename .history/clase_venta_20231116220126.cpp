#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
using namespace std;

Venta::Venta(Pedido &, int) {
   Pedido ped;
   int cant{0};
   pedido = ped;
   cantidad = cant;
}
void Venta::mostrarVenta() {
   cerr << "funcion mostrar venta" << endl;
   cout << "Datos del pedido:" << endl
      << "Cantidad " << cantidad << endl;
   pedido.print_pedido();
}