#include <iostream>
#include <iomanip>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;

int main(){
    Producto array_libros_has [100];
    Producto array_libros_viv [100];
    Pedido Pedido1;
    Listas lista_has(50,"data_has.txt");
    Listas lista_viv(80,"data_viv.txt");
    instanciar_muestras(array_libros_has, array_libros_viv);
    pantalla_start(array_libros_has, array_libros_viv, Pedido1, lista_has, lista_viv);
	return 0;
} 
