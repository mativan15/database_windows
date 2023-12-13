// Interfaz_a.h 
#include "c_interfaz.h"
#ifndef C_INTERFAZ_A_H
#define C_INTERFAZ_A_H
class InterfazAdmin : public Interfaz {
public:
    InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario);
    void menu() override;
    void funciones_admin();
    void editar_catalogo(Listas& lista, int op2);
    void editar_canales();
	void editar_lista(int index,int op2);
	void editar_eliminar(int index,int op2);
};

#endif
