// Interfaz_a.h 
#include "clase_interfaz_v.h"
#ifndef INTERFAZ_A_H
#define INTERFAZ_A_H



class InterfazAdmin : public InterfazV {
public:
    InterfazAdmin();
    InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
};

#endif
