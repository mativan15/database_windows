#include <iostream>
#include <iomanip>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;
//char usuario[64];
int main(){
    Producto array_libros_has [100];
    Producto array_libros_viv [100];
    //Pedido Pedido1("", "", "", "",0, 0,0);
	Pedido Pedido1;
	/*char *lista1;
	char *lista2;
	sprintf(lista1,"data_has.txt",'\0');
	sprintf(lista2,"data_viv.txt",'\0');
    Listas lista_has(50,lista1);
    Listas lista_viv(80,lista2);*/
	cerr << "error1\n";
	Listas lista_has(1);

	Listas lista_viv(2);
	cerr << "error2\n";
    //instanciar_muestras(array_libros_has, array_libros_viv);
	cerr << "error3\n";
    pantalla_start(array_libros_has, array_libros_viv, Pedido1, lista_has, lista_viv);
	//delete[] lista_has;
	cerr << "error4\n";
	return 0;
} 
