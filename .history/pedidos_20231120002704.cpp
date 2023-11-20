#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "wa.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
using namespace std;


void pedidos(Pedido Pedido1, Listas lista_has, Listas lista_viv) {
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
			//Pedido Pedido2;
			switch (op){
				case 1:
					//Pedido* Pedido2 = new Pedido;
					system("cls");
					cout<<"\tPEDIDOS\n"
						<<"\t\nNuevo Pedido\n";
						//<< "\n\t- Ingrese codigo del colegio:\n";
					//cin >> Pedido1.codigoCole;
					long long codi;
					char nom[50];
					char dir[50];
					char email[50];
					char nom_resp[50];
					int num_tel;
					long long cod_ruc;

					do {
						cout << "\n\t- Ingrese codigo del colegio:\n";
						cin >> codi;
						Pedido1.setCodigoCole(codi);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese nombre del colegio: ";
						cin >> nom;
						Pedido1.setNombreCole(nom);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese direccion del colegio:\n";
						cin >> dir;
						Pedido1.setDireccionCole(dir);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese telefono del colegio:\n";
						cin >> num_tel;
						Pedido1.setNumTele(num_tel);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese email del colegio:\n";
						cin >> email;
						Pedido1.setEmailCole(email);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese RUC del colegio:\n";
						cin >> cod_ruc;
						Pedido1.setCodigoRUC(cod_ruc);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese nombre del responsable del colegio:\n";
						cin >> nom_resp;
						Pedido1.setNombreResp(nom_resp);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					Pedido1.print_pedido();
					//Pedido tempPedido(const_nom, const_dir, const_email, const_nom_resp, num_tel, codi, cod_ruc);
        			//Pedido2 = tempPedido;
					cout << "\n\t Ingrese 1 para regresar o 2 para ir a canales de venta:\n\t";
					cin >> ret;
			
					if (cin.fail() || !(op >= 1 && op <=2)){
						error_valor();
					} else {
					switch(ret){
						case 1:
								pedidos(Pedido1, lista_has, lista_viv);
						case 2:
								canales_de_venta(Pedido1, lista_has, lista_viv);
						}
					}
					break;
				case 2:
					retro= false;
					catalogo(Pedido1, lista_has, lista_viv);
				    break;
				case 3:
					retro= false;
					canales_de_venta(Pedido1, lista_has, lista_viv);
				    break;
				case 4:
					retro = false;
					break;
					
			}
			
		}

	}while(retro);

}
//	PENDIENTE: BUCLE PARA FORZAR VALOR CORRECTO, PEDIR CONFRMACION PEDIDO, GENERAR DATOS PEDIDO DE CATALOGO

