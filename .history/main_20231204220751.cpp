#include <iostream>
#include <iomanip>
#include "header1.h"
#include "clase_usuario.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"//?
#include "clase_interfaz_a.h"
#include "clase_interfaz_v.h"
int main(){
	Usuario usuario1;
	Listas lista_has(1);
	Listas lista_viv(2);
	bool skip{false};
    pantalla_start(skip, lista_has, lista_viv, usuario1);
	return 0;
} 
