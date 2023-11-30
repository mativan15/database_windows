#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_catalogo.h"
#include "clase_interfaz_v.h"
#include "clase_canales_v.h"
using namespace std;
CanalesV::CanalesV(Pedido& Pedido1, Listas& lista_has, Listas& lista_viv, Usuario& usuario1) {
    this->Pedido1 = Pedido1;
    this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
}