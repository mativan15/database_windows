#include <iostream>
#include <iomanip>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_boleta.h"
using namespace std;


void canales_de_venta(Pedido Pedido1, Listas lista_has, Listas lista_viv){
	bool retro =true;
	int op;
	//Pedido* ptr_pedido = &Pedido1;
	Boleta boleta1(Pedido1, 12345, 11111);
	system("cls");
	cout<<"\tCANALES DE VENTA\n"
			<< "\x1B[33;5;88m" << "\n\tIngrese canal de venta" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t1. Libreria" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t2. E-commerce" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t3. Feria" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t4. Distribuidor" << "\x1B[m"<< "\n"
		 	<< "\x1B[33;5;88m" << "\n\t5. Regresar al Pedidos" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t6. Regresar al Menu" << "\x1B[m"<< "\n"
			<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
	cin >> op;
	if (std::cin.fail() || !(op >= 1 && op <=6)){
		error_valor();
		canales_de_venta(Pedido1, lista_has, lista_viv);
	}else{
		switch (op){
			case 1:
				system("cls");
				cout << "\x1B[34m" << "\nLIBRERIA" << "\x1B[m"<< "\n\n";
				do{
					cout << "\x1B[34m" << "\n\t1. Generar boleta" << "\x1B[m"<< "\n"
						<< "\x1B[34m" << "\n\t2. Regresar al Menu" << "\x1B[m"<< "\n"
						<< "\x1B[34m" << "\n\t3. Regresar a Canales de venta" << "\x1B[m"<< "\n"
						<< "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					if (std::cin.fail() || ((op != 1) && (op != 2))){
						error_valor();
					} else {
						switch (op){
							case 1:
								boleta1.mostrarBoleta();
								retro= false;
								break;
							case 2:
								retro= false;
								break;
							case 3:
								retro = false;
								canales_de_venta(Pedido1, lista_has, lista_viv);
								break;
						}
					}
				}while(retro);
				break;
			case 2:
				system("cls");
				cout << "\x1B[34m" << "\nE-COMMERCE" << "\x1B[m"<< "\n\n";
				do{
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Canales de venta" << "\x1B[m"<< "\n";
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					if (std::cin.fail() || ((op != 1) && (op != 2))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								break;
							case 2:
								retro = false;
								canales_de_venta(Pedido1, lista_has, lista_viv);
								break;
						}
					}
				}while(retro);
				break;
			case 3:
				system("cls");
				cout << "\x1B[34m" << "\nFERIA" << "\x1B[m"<< "\n\n";
				do{
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Canales de venta" << "\x1B[m"<< "\n";
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					if (std::cin.fail() || ((op != 1) && (op != 2))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								break;
							case 2:
								retro = false;
								canales_de_venta(Pedido1, lista_has, lista_viv);
								break;
						}
					}
				}while(retro);
				break;
			case 4:
				system("cls");
				cout << "\x1B[34m" << "\nDISTRIBUIDOR" << "\x1B[m"<< "\n\n";
				do{
					cout << "\x1B[34m" << "\n\t1. Regresar al Menu" << "\x1B[m"<< "\n";
					cout << "\x1B[34m" << "\n\t2. Regresar a Canales de venta" << "\x1B[m"<< "\n";
					cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
					cin >> op;
					if (std::cin.fail() || ((op != 1) && (op != 2))){
						error_valor();
					} else {
						switch (op){
							case 1:
								retro= false;
								break;
							case 2:
								retro = false;
								canales_de_venta(Pedido1, lista_has, lista_viv);
								break;
						}
					}
				}while(retro);
				break;
			case 5:
				system("cls");
					retro= false;
					pedidos(Pedido1, lista_has, lista_viv);
				    break;
			case 6: 
				retro=false;
		}

	}
}
