#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
using namespace std;

Venta::Venta(Pedido* ped, int cant) {
   pedido = ped;
   cantidad = cant;
}
void Venta::mostrarVenta() {
    cerr << "funcion mostrar venta" << endl;
    cout << "Datos del pedido:" << endl
    << "Nombre de la Cole: " << (*pedido).nombreCole << endl
    << "Dirección de la Cole: " << (*pedido).direccionCole << endl
    << "Email de la Cole: " << (*pedido).emailCole << endl
    << "Nombre del Responsable: " << (*pedido).nombreResp << endl
    << "Número de Teléfono: " << (*pedido).numTele << endl
    << "Código de la Cole: " << (*pedido).codigoCole << endl
    << "Código RUC: " << (*pedido).codigoRUC << endl
    << "Cantidad: " << cantidad << endl;
    }