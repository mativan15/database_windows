#include "c_interfaz_v.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "header1.h"
#include "c_interfaz.h"
#include "c_catalogo.h"
#include "c_canales_v.h"

InterfazVendedor::InterfazVendedor(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario)
    : Interfaz(catalogo1, pedido, canales1, listaHas, listaViv, usuario) {
}

void InterfazVendedor::menu() {
    cout << "\x1B[31m" << "\n\t\t\t\t\t\tVENDEDOR MODE" << "\x1B[m \n";
    Interfaz::menu();
}