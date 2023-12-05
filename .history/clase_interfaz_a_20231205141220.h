// Interfaz_a.h 
#include "clase_interfaz.h"
#ifndef INTERFAZ_A_H
#define INTERFAZ_A_H
class InterfazAdmin : public Interfaz {
public:
    InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
};

#endif
