#include <iostream>
#include "clase_pedidos.h"
#include "clase_venta.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_interfaz_v.h"
#include "clase_usuario.h"

using namespace std;

void error_valor(){
    cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n\n"; 
	cin.clear();           
    cin.ignore(100, '\n');
}
void pantalla_start(Pedido Pedido1, Listas lista_has, Listas lista_viv, Usuario usuario1){
	bool r = true;
	system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		cout<< "\x1B[1;97m" << "\n\tBienvenido" << "\x1B[m \n\n";
		cout<< "\x1B[1;97m" << "\n\tPara comenzar, cree un usuario" << "\x1B[m \n";
		char usuario[64];
		char contrasena[64];
		char nombre[64];
		int edad;
		int DNI;
		cout<< "\tIngrese su nombre:  ";
		cin>>nombre;
		usuario1.nombre=nombre;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<< "\tIngrese su edad:  ";
		cin>>edad;
		usuario1.edad=edad;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<<"\tIngrese su DNI:  ";
		cin>>DNI;
		usuario1.DNI=DNI;
		if (cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<<"\tIgrese su nombre de usuario:  ";
		cin>>usuario;
		usuario1.usuario=usuario;
		if (cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<<"\tIngrese su contrasena:  ";
		cin>>contrasena;
		usuario1.contrasena=contrasena;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		//if -> admin o vendedor?{ 
		if ((usuario!="") && (contrasena!="") ){
			InterfazV vendedor1(Pedido1, lista_has, lista_viv, usuario1);
            vendedor1.menu();
		}
		
}