// Interfaz_a.h 
#include "c_interfaz.h"
#ifndef C_INTERFAZ_A_H
#define C_INTERFAZ_A_H
class InterfazAdmin : public Interfaz {
public:
    InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
};

#endif