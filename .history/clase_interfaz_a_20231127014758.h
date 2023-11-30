// Interfaz_a.h
#ifndef INTERFAZ_A_H
#define INTERFAZ_A_H

#include "clase_interfaz_v.h"
#include "clase_pedidos.h" 
#include "clase_listas.h" 
#include "clase_usuario.h" 

class InterfazAdmin : public InterfazV {
public:
    InterfazAdmin();
    InterfazAdmin(Pedido& pedido, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    ~InterfazAdmin();
    void newFunction(); 
};

#endif
