// InterfazVChild.cpp
#include "clase_interfaz_a.h"

InterfazAdmin::InterfazAdmin() : InterfazV() {
    
}

InterfazAdmin::InterfazAdmin(Pedido& pedido, Listas& listaHas, Listas& listaViv, Usuario& usuario)
    : InterfazV(pedido, listaHas, listaViv, usuario) {
    
}

void InterfazAdmin::menu() {
    cout << "\x1B[1;97m" << "\n\t\t\t\t\tADMIN MODE" << "\x1B[m \n";
    InterfazV::menu();
}
