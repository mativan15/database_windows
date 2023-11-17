#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;


void pedidos(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido1, Listas lista_has, Listas lista_viv) {
	bool retro = true;
	int op;

	do{
		system("cls");
		cout<<"\tPEDIDOS\n"
			<< "\x1B[33;5;88m" << "\n\t1. Crear Nuevo Pedido" << "\x1B[m"<< "\n"
		 	<< "\x1B[33;5;88m" << "\n\t2. Regresar al Catalogo" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t3. Ir a Canales de venta" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t4. Regresar al Menu" << "\x1B[m"<< "\n"
			<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || !(op >= 1 && op <=4)){
			error_valor();
		}else{
			int ret;
			switch (op){
				case 1:
					
					system("cls");
					cout<<"\tPEDIDOS\n"
						<<"\t\nNuevo Pedido\n"
						<< "\n\t- Ingrese codigo del colegio:\n";
					cin >> Pedido1.codigoCole;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					cout<< "\n\t- Ingrese nombre del colegio:\n";
					cin >> Pedido1.nombreCole;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					cout<< "\n\t- Ingrese direccion del colegio:\n";
					cin >> Pedido1.direccionCole;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					cout<< "\n\t- Ingrese telefono del colegio:\n";
					cin >> Pedido1.numTele;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					cout<< "\n\t- Ingrese email del colegio:\n";
					cin >> Pedido1.emailCole;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					cout<< "\n\t- Ingrese RUC del colegio:\n";
					cin >> Pedido1.codigoRUC;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					cout<< "\n\t- Ingrese nombre del responsable del colegio:\n";
					cin >> Pedido1.nombreResp;
					if (cin.fail() || !(op >= 1 && op <=3)){
						error_valor();}
					//cout<<"\t\n" << Pedido1.codigoCole;
					Pedido1.print_pedido();
					break;
				case 2:
					retro= false;
					catalogo(array_libros_has, array_libros_viv,Pedido1, lista_has, lista_viv);
				    break;
				case 3:
					retro= false;
					canales_de_venta(array_libros_has, array_libros_viv,Pedido1, lista_has, lista_viv);
				    break;
				case 4:
					retro = false;
					break;
					
			}
			cout << "\n\t Ingrese 1 para regresar o 2 para ir a canales de venta:\n\t";
			cin >> ret;
			
			if (cin.fail() || !(op >= 1 && op <=2)){
						error_valor();
			} else {
				switch(ret){
					case 1:
						pedidos(array_libros_has, array_libros_viv, Pedido1, lista_has, lista_viv);
					case 2:
						canales_de_venta(array_libros_has, array_libros_viv,Pedido1, lista_has, lista_viv);
				}
			}
		}

	}while(retro);

}
//	PENDIENTE: BUCLE PARA FORZAR VALOR CORRECTO, PEDIR CONFRMACION PEDIDO, GENERAR DATOS PEDIDO DE CATALOGO

