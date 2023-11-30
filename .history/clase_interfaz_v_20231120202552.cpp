#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_interfaz_v.h"

using namespace std;

InterfazV::InterfazV() {
    cerr << "objeto interfazv creado" << endl;
    Pedido1 = Pedido();
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();
}

InterfazV::InterfazV(Pedido Pedido1, Listas lista_has, Listas lista_viv, Usuario usuario1) {
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
	bool repertirinicio = true;	
		
	do {	
		system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\t\tBIENVENIDO, " << usuario1.usuario << "\x1B[m \n";
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
						catalogo();
						repite = false;
						break;
					   
					case 2:
						system("cls");
						//pedidos(Pedido1, lista_has, lista_viv,usuario1);
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

void InterfazV::catalogo(){
	bool retro =true;
	int op;
		//system("cls");
	cout<<"\n\tCatalogo\n"
		<< "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m"<< "\n"
		<< "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m"<< "\n"
		<< "\x1B[34m" << "\n\t3. Regresar" << "\x1B[m"<< "\n"
		<< "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (std::cin.fail() || !(op >= 1 && op <=3)){
			error_valor();
			catalogo();
		}else{
			switch (op){
			case 1:
				system("cls");
				cout << "\x1B[34m" << "\nCATALOGO Hasta agotar stock" << "\x1B[m"<< "\n\n";
				//print_tabla_libros(array_libros_has);//catalogo HAS
				cerr << "creacion objetos\n";
				try {
					lista_has.print_lista();
				}
					catch (invalid_argument& e) {
					cerr << "Exception while initializing print_listaaa: " << e.what() << endl;
				}
				//lista_nos.print_lista();
				//delete lista_has;
				//cout << lista_has;
				cerr << "\nprint objetos\n";
				do{
					cerr << "print menu1\n";
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Catalogo" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m"<< "\n";
					cerr << "print menu2\n";
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					cerr << "print menu3\n";
					if (std::cin.fail() || ((op != 1) && (op != 2) && (op != 3))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								menu();
								break;
							case 2:
								retro = false;
								catalogo();
									
								break;
							case 3:
								retro= false;
								//pedidos(Pedido1, lista_has, lista_viv,usuario1);
								break;
						}
					}
				}while(retro);
				cerr << "fin de print menu\n";
				break;
			case 2:
				//system("cls");
				cout << "\x1B[34m" << "\nCATALOGO vivo" << "\x1B[m"<< "\n\n";
				//print_tabla_libros(array_libros_has);//catalogo HAS
				cerr << "creacion objetos\n";
				try {
					lista_viv.print_lista();
				}
					catch (invalid_argument& e) {
					cerr << "Exception while initializing print_listaaa: " << e.what() << endl;
				}

				cerr << "\nprint objetos\n";
				do{
					cerr << "print menu1\n";
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Catalogo" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m"<< "\n";
					cerr << "print menu2\n";
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					cerr << "print menu3\n";
					if (std::cin.fail() || ((op != 1) && (op != 2) && (op != 3))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								//menu( Pedido1, lista_has, lista_viv,usuario1);
								break;
							case 2:
								retro = false;
								catalogo();
									
								break;
							case 3:
								retro= false;
								//pedidos();
								break;
							}
						}
					}while(retro);
					cerr << "fin de print menu\n";
					break;
				case 3: 
					retro=false;
		}
	}
	cout<<"\n\n";
}
