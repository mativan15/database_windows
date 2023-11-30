#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_catalogo.h"
#include "clase_interfaz_v.h"

using namespace std;

Catalogo::Catalogo(Pedido& Pedido1,Listas& lista_has,Listas& lista_viv,Usuario& usuario1) {
    this->Pedido1 = Pedido1;
    this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
}
void Catalogo::mostrar_catalogo() {
    bool retro = true;
    int op;
    do {
        cout << "\n\tCatalogo\n"
             << "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Regresar" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 3)) {
            error_valor();
        } else {
            switch (op) {
                case 1:
                    system("cls");
                    cout << "\x1B[34m" << "\nCATALOGO HAS" << "\x1B[m" << "\n\n";
                    print_catalogo(lista_has);
                    break;
                case 2:
                    system("cls");
                    cout << "\x1B[34m" << "\nCATALOGO VIVO" << "\x1B[m" << "\n\n";
                    print_catalogo(lista_viv);
                    break;
                case 3:
                    retro = false;
                    break;
                default:
                    error_valor();
            }
        }
    } while (retro);
}

void Catalogo::print_catalogo(Listas& array_catalogo) {
    int op;
    bool retro = true;
    try {
        array_catalogo.print_lista();
    } catch (const invalid_argument& e) {
        cerr << "Exception while initializing print_lista: " << e.what() << endl;
    }
    do {
        cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Regresar a Catalogo" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 3)) {
            error_valor();
        } else {
            switch (op) {
                case 1:
                    retro = false;
                    menu();
                    break;
                case 2:
                    retro = false;
                    catalogo();
                    break;
                case 3:
                    retro = false;
                    // pedidos();
                    break;
                default:
                    error_valor();
            }
        }
    } while (retro);
}