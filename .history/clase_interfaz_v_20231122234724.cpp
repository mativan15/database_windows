#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_interfaz_v.h"
#include "clase_catalogo.h"

using namespace std;

InterfazV::InterfazV() {
    cerr << "objeto interfazv creado" << endl;
    Pedido1 = Pedido();
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();
}

InterfazV::InterfazV(Pedido& Pedido1, Listas& lista_has, Listas& lista_viv, Usuario& usuario1) {
	this->Pedido1 = Pedido1;
	this->lista_has = lista_has;
	this->lista_viv = lista_viv;
	this->usuario1 = usuario1;
    cerr << "objeto interfazv creado" << endl;
}

InterfazV::~InterfazV() {
    cerr << "objeto interfazv destruido" << endl;
}

void InterfazV::menu()	{
	bool repite = true;
	int opcion;
	//bool repertirinicio = true;	
	do {	
		system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\t\tBIENVENIDO, " << usuario1.nombre << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\tMENU" << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t4. SALIR" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
			
		if (cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)) { //comprabacion de erroes
				error_valor();
		} else {
				switch (opcion){
					case 1:
						system("cls");
						//if
						exe_catalogo();
						repite = false;
						break;
					   
					case 2:
						system("cls");
						exe_pedidos();
						repite = false;
						break;
					case 3:
						system("cls");
						//canales_de_venta(Pedido1, lista_has, lista_viv,usuario1);
						repite = false;
						break;

					case 4:
					   repite = false;
					   
					   break;			
			}
		}
	} while (repite);
}

void InterfazV::exe_catalogo() {
    Catalogo catalogo(Pedido1, lista_has, lista_viv, usuario1);
    catalogo.tab_catalogo();
    int op;
    bool retro = true;
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
                    exe_catalogo();
                    break;
                case 3:
                    retro = false;
                    exe_pedidos();
                    break;
                default:
                    error_valor();
            }
        }
    } while (retro);
}

void InterfazV::exe_pedidos() {
	Pedido1.tab_pedido();
	int op;
    bool retro = true;
    do {
        cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Regresar a Pedidos" << "\x1B[m" << "\n"
			 << "\x1B[34m" << "\n\t3. Ir a Catalogo" << "\x1B[m" << "\n"
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
                    exe_pedidos();
                    break;
                case 3:
                    retro = false;
                    exe_catalogo();
                    break;
                default:
                    error_valor();
            }
        }
    } while (retro);
}