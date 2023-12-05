// InterfazVChild.cpp
#include "clase_interfaz_a.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_interfaz_v.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"


InterfazAdmin::InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario)
    : InterfazV(catalogo1, pedido, canales1, listaHas, listaViv, usuario) {
}

void InterfazAdmin::menu() {
    cout << "\x1B[1;97m" << "\n\t\t\t\t\t\tADMIN MODE" << "\x1B[m \n";
    InterfazV::menu();
}
