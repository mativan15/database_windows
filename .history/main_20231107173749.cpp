#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;



int main(){
    Producto array_libros_has [100];
    Producto array_libros_viv [100];
    Pedido Pedido1;
    Listas lista1(5);
    instanciar_muestras(array_libros_has, array_libros_viv);
    pantalla_start(array_libros_has, array_libros_viv, Pedido1, lista1);
	return 0;
} 
