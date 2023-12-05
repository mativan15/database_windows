//funciones globales definidas en extra

#include "clase_usuario.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"
#ifndef HEADER1_H
#define HEADER1_H
void pantalla_start(bool skip, Listas& lista_has, Listas& lista_viv, Usuario& usuario1);
void error_valor();
void caratula();
void limpiar_archivo(int tipo_archivo);
void add_listas_pedidos(Listas& lista_has, Listas& lista_viv, Listas& productos_anadidos_has, Listas& productos_anadidos_viv);
#endif