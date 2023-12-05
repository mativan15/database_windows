//clase_interfaz_v.h
#include <iostream>
#include "_interfaz.h"
#ifndef C_INTERFAZ_V_H
#define C_INTERFAZ_V_H

class InterfazVendedor : public Interfaz {
public:
    InterfazVendedor(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
};

#endif