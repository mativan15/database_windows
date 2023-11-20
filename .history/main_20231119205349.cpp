#include <iostream>
#include <iomanip>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;
//char usuario[64];
int main(){
    //Pedido Pedido1("", "", "", "",0, 0,0);
	Pedido Pedido1;
	cerr << "error pedido?\n";
	Listas lista_has(1);
	Listas lista_viv(2);
	cerr << "error listas?\n";
    pantalla_start(Pedido1, lista_has, lista_viv);
	//delete[] lista_has;
	cerr << "error4\n";
	return 0;
} 
