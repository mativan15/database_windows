#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
using namespace std;



int main(){
    Producto array_libros_has [500];
    Producto array_libros_viv [500];
    Pedido Pedido1(' ',' ',' ',' ',0,0,0);
    instanciar_muestras(array_libros_has, array_libros_viv);
    pantalla_start(array_libros_has, array_libros_viv, Pedido1);
	return 0;
} 
