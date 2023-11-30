#include <iostream>
#include <iomanip>
#include "wa.h"
#include "clase_persona.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_menu.h"
using namespace std;
//char usuario[64];
int main(){
	Pedido Pedido1;
	Persona persona1;
	cerr << "error1\n";
	Listas lista_has(1);
	Listas lista_viv(2);
	cerr << "error2\n";
	Menu menu1;
    pantalla_start(menu1, Pedido1, lista_has, lista_viv,persona1);
	cerr << "error3\n";
	return 0;
} 