#include "c_catalogo.h"
#ifndef C_CATALOGO_A_H
#define C_CATALOGO_A_H
class CatalogoAdmin: public Catalogo{
public:
    CatalogoAdmin(Listas& lista_has,Listas& lista_viv,Usuario& usuario1);
    void tab_catalogo() override;
};
#endif