#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;

void error_valor(){
    cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n\n"; 
	cin.clear();           
    cin.ignore(100, '\n');
}



void pantalla_start(Pedido Pedido1, Listas lista_has, Listas lista_viv){
	bool r = true;
	//system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		cout<< "\x1B[1;97m" << "\n\tBienvenido" << "\x1B[m \n\n";
		cout<< "\x1B[1;97m" << "\n\tPara comenzar, cree un usuario" << "\x1B[m \n";
		char usuario[64]="";
		char contraseña[64]="";
		cout<< "\tIngrese el nombre de usuario:  ";
		cin>>usuario;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<< "\tIngrese la contrasena:  ";
		cin>>contraseña;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}

		if ((usuario!="") && (contraseña!="") ){
			menu(usuario, Pedido1, lista_has, lista_viv);
		}
}

void menu(char usuario[64], Pedido Pedido1, Listas lista_has, Listas lista_viv){
	bool repite = true;
	int opcion;
	bool repertirinicio = true;	
	
	do {	
		//system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\t\tBIENVENIDO, " << usuario << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\tMENU" << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t4. SALIR" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
		
		if (std::cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)) { //comprabacion de erroes
			error_valor();
		} else {
			switch (opcion){
				case 1:
					//system("cls");
					catalogo(Pedido1, lista_has, lista_viv);
					repite = false;
					break;
				   
				case 2:
					system("cls");
					pedidos(Pedido1, lista_has, lista_viv);
					repite = false;
					break;
				case 3:
					system("cls");
					canales_de_venta(Pedido1, lista_has, lista_viv);
					repite = false;
					break;

				case 4:
				   repite = false;
				   
				   break;			
			}
		}
	} while (repite);
}
	
void caratula(){
	char universidad[8] = "UCSP"; 
	char escuela[64] = "Escuela Profesional de Ciencia de la Computacion I"; 
	char curso[32] ="Ciencia de la Computacion I"; 
	char alumnos[64] = "Alumnos: \nIvan Matthias Sardon Medina \nAnthony Huicho Perez";
	char ciudad_año[32] = "Arequipa 2023 - II";
    cout << "\x1B[31;5;88m" << universidad<< "\x1B[m"<< "\n";
	cout << "\x1B[1;97m" << escuela << "\x1B[m"<< "\n";
	cout << curso << "\n";
	cout << "\x1B[1;97m" << alumnos<< "\x1B[m"<< "\n";
	cout << ciudad_año << "\n"; 
}

void catalogo(Pedido Pedido1, Listas lista_has, Listas lista_viv){
	bool retro =true;
	int op;
	//system("cls");
	cout<<"\n\tCatalogo\n";
	cout << "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m"<< "\n";
	cout << "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m"<< "\n";
	cout << "\x1B[34m" << "\n\t3. Regresar" << "\x1B[m"<< "\n";
	cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
	cin >> op;
	if (std::cin.fail() || !(op >= 1 && op <=3)){
		error_valor();
		catalogo(Pedido1, lista_has, lista_viv);
	}else{
		switch (op){
			case 1:
				//system("cls");
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
								menu("usuario", Pedido1, lista_has, lista_viv);
								break;
							case 2:
								retro = false;
								catalogo(Pedido1, lista_has, lista_viv);
									
								break;
							case 3:
								retro= false;
								pedidos(Pedido1, lista_has, lista_viv);
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
								menu("usuario", Pedido1, lista_has, lista_viv);
								break;
							case 2:
								retro = false;
								catalogo(Pedido1, lista_has, lista_viv);
									
								break;
							case 3:
								retro= false;
								pedidos(Pedido1, lista_has, lista_viv);
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
		