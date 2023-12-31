#include <iostream>
#include "c_producto.h"
#include "c_listas.h"
#include "header1.h"
#include "c_interfaz.h"
#include "c_canales_v.h"
#include "c_catalogo.h"
using namespace std;

Interfaz::Interfaz(Catalogo& catalogo1, Pedido& Pedido1, CanalesV& canales1, Listas& lista_has, Listas& lista_viv, Usuario& usuario1) {
	this->catalogo1 = catalogo1;
    this->Pedido1 = Pedido1;
    this->canales1 = canales1;
	this->lista_has = lista_has;
	this->lista_viv = lista_viv;
	this->usuario1 = usuario1;
    cerr << "objeto interfazv creado" << endl;
}

Interfaz::~Interfaz() {
    cerr << "objeto interfazv destruido" << endl;
}

void Interfaz::menu()	{
	bool repite = true;
	int opcion;
	do {	
		
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[31m" << "\n\t\tBIENVENIDO, " << usuario1.nombre << "\x1B[m \n";
		cout << "\x1B[94m"  << "\n\tMENU" << "\x1B[m \n";
		cout << "\x1B[96m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n";
		cout << "\x1B[96m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n";
		cout << "\x1B[96m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n";
		cout << "\x1B[96m" << "\n\t4. SALIR" << "\x1B[m"<< "\n";
		cout << "\x1B[96m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
			
		if (cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)) { //comprabacion de erroes
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
				break;			
			}
		}
	} while (repite);
}
