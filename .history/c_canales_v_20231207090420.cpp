#include <iostream>
#include "c_pedidos.h"
#include "c_venta.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "header1.h"
#include "c_catalogo.h"
#include "c_canales_v.h"
#include "c_boleta.h"
#include "c_factura.h"
using namespace std;
CanalesV::CanalesV() {
	cerr << "\nconstructor nulo invocado en canalesV\n";
	PedidoPtr = nullptr;
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();
	catalogoPtr = nullptr;
	ventaPtr = nullptr;
	bof = false;
	cant_total = 100;
}

CanalesV::CanalesV(Listas& lista_has, Listas& lista_viv, Usuario& usuario1) {
    cerr << "\nconstructor lleno invocado en canalesV\n";
	PedidoPtr = nullptr;
	this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
	catalogoPtr = nullptr;
	ventaPtr = nullptr;
	bof = false;
	cant_total = 100;
	cant_lib = 0;
	max_lib = 500;
	cant_eco = 0;
	max_eco = 2000;
	cant_fer = 0;
	max_fer = 400;
	cant_dis = 0;
	max_dis = 1000;
}
void CanalesV::set_catalogoPtr(Catalogo* catalogoPtr) {
	this->catalogoPtr = catalogoPtr;
}
void CanalesV::set_pedidoPtr(Pedido* PedidoPtr) {
	this->PedidoPtr = PedidoPtr;
}
void CanalesV::set_cant_total(int cant_total) {
	this->cant_total = cant_total;
}
void CanalesV::set_cant_lib(int cant_lib) {
	this->cant_lib = cant_lib;
}
void CanalesV::set_cant_eco(int cant_eco) {
	this->cant_eco = cant_eco;
}
void CanalesV::set_cant_fer(int cant_fer) {
	this->cant_fer = cant_fer;
}
void CanalesV::set_cant_dis(int cant_dis) {
	this->cant_dis = cant_dis;
}
int CanalesV::get_cant_total() {
	return cant_total;
}
void CanalesV::tab_canales() {
    bool retro{true};
	int op;
	set_cant_total(PedidoPtr->get_cantidad_tot());
	system("cls");
	do{
		cout << "\x1B[31m"<< "\n\tCANALES DE VENTA\n"<< "\x1B[m"
		<< "\x1B[92m" << "\nLa cantidad total por vender es: " << cant_total << "\n"
		<< "\n\tIngrese canal de venta" << "\x1B[m"<< "\n"
		<< "\x1B[96m" << "\n\t1. Libreria: " << cant_lib <<"\x1B[m"<< "\n"
		<< "\x1B[96m" << "\n\t2. E-commerce: " << cant_eco << "\x1B[m"<< "\n"
		<< "\x1B[96m" << "\n\t3. Feria: " << cant_fer << "\x1B[m"<< "\n"
		<< "\x1B[96m" << "\n\t4. Distribuidor: " << cant_dis << "\x1B[m"<< "\n"
		<< "\x1B[33;5;88m" << "\n\tO escoja una opcion:" << "\x1B[m"<< "\n"
		<< "\x1B[33;5;88m" << "\n\t5. Generar comprobante" << "\x1B[m"<< "\n"
		<< "\x1B[33;5;88m" << "\n\t6. Regresar a Pedidos" << "\x1B[m"<< "\n"
		<< "\x1B[33;5;88m" << "\n\t7. Regresar al Menu" << "\x1B[m"<< "\n"
		<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (std::cin.fail() || !(op >= 1 && op <=7)){
			error_valor();
		}else{
			switch (op){
			case 1:
				retro=false;
				system("cls");
				cout << "\x1B[34m" << "\nLIBRERIA" << "\x1B[m"<< "\n\n"
					 << "\x1B[33;5;88m" << "\nLa cantidad pendiente por asignar es: " << cant_total << "\n\x1B[m"
					 << "\x1B[34m" << "\nActualmente en Libreria: " << cant_lib << "\x1B[m"<< "\n\n"
					 << "\x1B[34m" << "\nCapacidad maxima en Libreria: " << max_lib << "\x1B[m"<< "\n\n";
				ingresar_cant_canal(cant_lib, max_lib);
				break;
			case 2:
				retro=false;
				system("cls");
				cout << "\x1B[34m" << "\nE-COMMERCE" << "\x1B[m"<< "\n\n"
					 << "\x1B[33;5;88m" << "\nLa cantidad pendiente por asignar por vender es: " << cant_total << "\n\x1B[m"
					 << "\x1B[34m" << "\nActualmente en E-commerce: " << cant_eco << "\x1B[m"<< "\n\n"
					 << "\x1B[34m" << "\nCapacidad maxima en Libreria: " << max_eco << "\x1B[m"<< "\n\n";
				ingresar_cant_canal(cant_eco, max_eco);
				break;
			case 3:
				retro=false;
				system("cls");
				cout << "\x1B[34m" << "\nFERIA" << "\x1B[m"<< "\n\n"
					 << "\x1B[33;5;88m" << "\nLa cantidad pendiente por asignar es: " << cant_total << "\n\x1B[m"
					 << "\x1B[34m" << "\nActualmente en Feria: " << cant_fer << "\x1B[m"<< "\n\n"
					 << "\x1B[34m" << "\nCapacidad maxima en Libreria: " << max_fer << "\x1B[m"<< "\n\n";
				ingresar_cant_canal(cant_fer, max_fer);
				break;
			case 4:
				retro=false;
				system("cls");
				cout << "\x1B[34m" << "\nDISTRIBUIDOR" << "\x1B[m"<< "\n\n"
				 	 << "\x1B[33;5;88m" << "\nLa cantidad pendiente por asignar es: " << cant_total << "\n\x1B[m"
				 	 << "\x1B[34m" << "\nActualmente en Distribuidor: " << cant_dis << "\x1B[m"<< "\n\n"
					 << "\x1B[34m" << "\nCapacidad maxima en Libreria: " << max_dis << "\x1B[m"<< "\n\n";
				ingresar_cant_canal(cant_dis, max_dis);
				break;
			case 5: 
				f_bof();
				retro=false;
				ventaPtr->print_comprobante();
				cout << "\x1B[34m" << "\nPedido Finalizado con exito\nPresione 1 para salir al menu:" << "\x1B[m"<< "\n\n";
				do {
					int o;
					cin >> o;
					if (cin.fail()) {
						error_valor();
					} else {
						break;
					}
				} while (true);
				pantalla_start(true, lista_has, lista_viv, usuario1);
				break;
			
			case 6: 
				PedidoPtr->tab_pedido();
				retro=false;
				break;
			case 7: 
				retro=false;
				pantalla_start(true, lista_has, lista_viv, usuario1);
				break;
			}
		}
	} while (retro);
} 
void CanalesV::f_bof(){
	do {
		int op_bof;
		system("cls");
		cout<<"\x1B[32m"<<"\n\t\t\t\tCANALES DE VENTA\n"<<"\x1B[0m"<<"\x1B[96m"
			<< "\n\tDESEA: \n\t1.BOLETA  \n\t2:FACTURA \n\n\tESCOGER: "<<"\x1B[0m";
		cin>> op_bof;
		if (std::cin.fail() || !(op_bof >= 1 && op_bof <=2)){
			error_valor();
		}else{
			if (op_bof==1){
				Boleta* boleta1 = new Boleta();
				system("cls");
				cout<<"\x1B[91m"<<" \n\t\t\t\tBOLETA\n"<<"\x1B[0m";
				do {
					int num_bs;
					cout <<"\x1B[96m"<< "\n\t- INGRESE EL NUMERO DE BOLETA:\n\t"<<"\x1B[0m";
					cin >> num_bs;
					boleta1->setNumero_boleta(num_bs);
					if (cin.fail()) {
						error_valor();
					} else {
						break;
					}
				} while (true);
				do {
					int dni;
					cout <<"\x1B[96m"<< "\n\t- INGRESE EL NUMERO DE DNI:\n\t"<<"\x1B[0m";
					cin >> dni;
					boleta1->setdni(dni);
					if (cin.fail()) {
						error_valor();
					} else {
						break;
					}
				} while (true);
				ventaPtr = boleta1;
			}else{
				Factura* factura1 = new Factura();
				system("cls");
				cout<<"\x1B[91m"<<" \n\t\t\t\tFACTURA\n"<<"\x1B[0m";
				do {
					int num_bs;
					cout <<"\x1B[96m"<< "\n\t- INGRESE EL NUMERO DE FACTURA:\n\t"<<"\x1B[0m";
					cin >> num_bs;
					factura1->setNumero_factura(num_bs);
					if (cin.fail()) {
						error_valor();
					} else {
						break;
					}
				} while (true);
				do {
					char razon_s[50];
					cout <<"\x1B[96m"<< "\n\t- INGRESE LA RAZON SOCIAL:\n\t"<<"\x1B[0m";
					cin >> razon_s;
					factura1->setRazon_social(razon_s);
					if (cin.fail()) {
						error_valor();
					} else {
						break;
					}
				} while (true);
				ventaPtr = factura1;
			}
			break;
		}
		//
	}while (true);
}
void CanalesV::ingresar_cant_canal(int &cant_atributo, int &cant_max) {
	int cant_v;
	bool retro1{true};
	do{
		cout << "\x1B[34m" << "\nIngrese cantidad:" << "\x1B[m"<< "\n";
		cin >> cant_v;
		if (std::cin.fail() || (cant_v < 0) || ((cant_total-cant_v) < 0) || (cant_atributo+cant_v)>cant_max){
			error_valor();
		} else {
			cant_atributo += cant_v;
			cant_total -= cant_v;

			break;
		}
	}while(retro1);
	system("cls");
	tab_canales();
}
