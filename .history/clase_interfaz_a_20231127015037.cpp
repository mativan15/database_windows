// InterfazVChild.cpp
#include "clase_interfaz_a.h"

InterfazAdmin::InterfazAdmin() : InterfazV() {
    
}

InterfazAdmin::InterfazAdmin(Pedido& pedido, Listas& listaHas, Listas& listaViv, Usuario& usuario)
    : InterfazV(pedido, listaHas, listaViv, usuario) {
    
}

InterfazAdmin::~InterfazAdmin() {
    
}

void InterfazAdmin::newFunction() {
    
}
