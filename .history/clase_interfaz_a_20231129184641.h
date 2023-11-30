// Interfaz_a.h
#include "clase_interfaz_v.h"
#include "clase_pedidos.h" 
#include "clase_listas.h" 
#include "clase_usuario.h" 
#ifndef INTERFAZ_A_H
#define INTERFAZ_A_H

class InterfazAdmin : public InterfazV {
public:
    InterfazAdmin();
    InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
};

#endif
