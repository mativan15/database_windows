#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"

using namespace std;


void pedidos(Producto array_libros_has[], Producto array_libros_viv[], Pedido Pedido1){
	bool retro = true;
	int op;

	do{
		cout<<"\tPEDIDOS\n"
			<< "\x1B[33;5;88m" << "\n\t1. Crear Nuevo Pedido" << "\x1B[m"<< "\n"
		 	<< "\x1B[33;5;88m" << "\n\t2. Regresar al Catalogo" << "\x1B[m"<< "\n"
			<< "\x1B[33;5;88m" << "\n\t3. Regresar al Menu" << "\x1B[m"<< "\n"
			<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || !(op >= 1 && op <=3)){
			error_valor();
		}else{
			switch (op){
				case 1:
					system("cls");
					cout<<"\tPEDIDOS\n"
						<<"\t\nNuevo Pedido\n"
						<< "\n\t- Ingrese codigo del colegio:\n";
					cin >> Pedido1.codigoCole;
					cout<< "\n\t- Ingrese nombre del colegio:\n";
					cin >> Pedido1.nombreCole;
					cout<< "\n\t- Ingrese direccion del colegio:\n";
					cin >> Pedido1.direccionCole;
					cout<< "\n\t- Ingrese telefono del colegio:\n";
					cin >> Pedido1.numTele;
					cout<< "\n\t- Ingrese email del colegio:\n";
					cin >> Pedido1.emailCole;
					cout<< "\n\t- Ingrese RUC del colegio:\n";
					cin >> Pedido1.codigoRUC;
					cout<< "\n\t- Ingrese nombre del responsable del colegio:\n";
					cin >> Pedido1.nombreResp;
					//cout<<"\t\n" << Pedido1.codigoCole;

					break;
				case 2:
					retro= false;
					catalogo(array_libros_has, array_libros_viv);
				    break;
				case 3:
					retro= false;
				    break;
			}
		}

	}while(retro);

}


