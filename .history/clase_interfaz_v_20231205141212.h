//clase_interfaz_v.h
#include <iostream>
#include "clase_interfaz.h"
#ifndef CLASE_INTERFAZ_V_H
#define CLASE_INTERFAZ_V_H

class InterfazVendedor : public Interfaz {
public:
    InterfazVendedor(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
};

#endif