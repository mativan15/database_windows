#include <iostream>
#include <iomanip>
#include "header1.h"
#include "clase_usuario.h"
#include "clase_listas.h"
int main(){
	Usuario usuario1;
	Listas lista_has(1);
	Listas lista_viv(2);
	bool skip{false};
	limpiar_archivo(1);
	limpiar_archivo(2);
    pantalla_start(skip, lista_has, lista_viv, usuario1);
	return 0;
} 
