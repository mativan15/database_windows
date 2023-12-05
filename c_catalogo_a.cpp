#include "header1.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "c_catalogo_a.h"
using namespace std;
CatalogoAdmin::CatalogoAdmin(Listas& lista_has,Listas& lista_viv,Usuario& usuario1)
    :Catalogo(lista_has,lista_viv,usuario1){
}
void CatalogoAdmin::tab_catalogo(){
    bool retro = true;
    int op;
    do {
        system("cls");
        cout << "\n\tCatalogo ADMIN\n"
             << "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t5. Editar catalogo" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 5)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                system("cls");
                cout << "\x1B[34m" << "\n\tCATALOGO HAS" << "\x1B[m" << "\n\n";
                retro = false;
                print_catalogo(lista_has);
                break;
            case 2:
                system("cls");
                cout << "\x1B[34m" << "\n\tCATALOGO VIVO" << "\x1B[m" << "\n\n";
                retro = false;
                print_catalogo(lista_viv);
                break;
            case 3:
                retro = false;
                PedidoPtr->tab_pedido();
                break;
            case 4:
                retro = false;
                pantalla_start(true, lista_has, lista_viv, usuario1);	
                break;
            case 5:
                retro = false;
                cout << "editar xd";	
                break;
            default:
                error_valor();
            }
        }
    } while (retro);
}