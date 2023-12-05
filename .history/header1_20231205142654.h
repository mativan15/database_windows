//funciones globales definidas en extra

#include "c_usuario.h"
#include "c_pedidos.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_catalogo.h"
#include "c_canales_v.h"
#ifndef HEADER1_H
#define HEADER1_H
void pantalla_start(bool skip, Listas& lista_has, Listas& lista_viv, Usuario& usuario1);
void error_valor();
void caratula();
void limpiar_archivo(int tipo_archivo);
void add_listas_pedidos(Listas& lista_has, Listas& lista_viv, Listas& productos_anadidos_has, Listas& productos_anadidos_viv);
#endif