// InterfazAdmin.cpp
#include "c_interfaz_a.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "header1.h"
#include "c_interfaz.h"
#include "c_catalogo.h"
#include "c_canales_v.h"
InterfazAdmin::InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario)
    : Interfaz(catalogo1, pedido, canales1, listaHas, listaViv, usuario) {
}

void InterfazAdmin::menu() {
    cout << "\x1B[1;97m" << "\n\t\t\t\t\t\tADMIN MODE" << "\x1B[m \n";
    Interfaz::menu();
}
