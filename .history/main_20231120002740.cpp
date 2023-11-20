#include <iostream>
#include <iomanip>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;
//char usuario[64];
int main(){
	Pedido Pedido1;
	cerr << "error1\n";
	Listas lista_has(1);
	Listas lista_viv(2);
	cerr << "error2\n";
    pantalla_start(Pedido1, lista_has, lista_viv);
	cerr << "error3\n";
	return 0;
} 
