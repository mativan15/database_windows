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
    bool repite = true;
	int opcion;
	system("cls");
    do {	
        cout << "\x1B[1;97m" << "\n\t\t\t\t\t\tADMIN MODE" << "\x1B[m \n"
		     << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\t\tBIENVENIDO, " << usuario1.nombre << "\x1B[m \n"
		     << "\x1B[1;97m" << "\n\tMENU" << "\x1B[m \n"
		     << "\x1B[1;97m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n"
             << "\x1B[1;97m" << "\n\t4. FUNCIONES ADMIN" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\t5. SALIR" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
			
		if (cin.fail() || !(opcion >= 1 && opcion <= 5)) { //comprabacion de erroes
				error_valor();
		} else {
		    switch (opcion){
			case 1:
				system("cls");
				catalogo1.tab_catalogo();
				repite = false;
				break;  
			case 2:
				system("cls");
				Pedido1.tab_pedido();
				repite = false;
				break;
			case 3:
				system("cls");
				canales1.tab_canales();
				repite = false;
				break;
            case 4:
				repite = false; 
                system("cls");
                cout << "catalogo xd";
                lista_has.print_lista();
				break;
			case 5:
				repite = false;   
				break;			
			}
		}
	} while (repite);
}
