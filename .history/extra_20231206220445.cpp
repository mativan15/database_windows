#include <iostream>
#include <fstream>
#include "c_pedidos.h"
#include "c_venta.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_interfaz_v.h"
#include "c_usuario.h"
#include "c_interfaz_a.h"
#include "c_catalogo.h"
#include "c_canales_v.h"
#include "c_boleta.h"
#include "c_factura.h"
using namespace std;
void error_valor(){
    cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n\n"; 
	cin.clear();           
    cin.ignore(100, '\n');
}
void caratula(){
	char universidad[8] = "UCSP"; 
	char escuela[64] = "Escuela Profesional de Ciencia de la Computacion I"; 
	char curso[32] ="Ciencia de la Computacion I"; 
	char alumnos[64] = "Alumnos: \nIvan Matthias Sardon Medina \nAnthony Huicho Perez";
	char ciudad_año[32] = "Arequipa 2023 - II";
    cout << "\x1B[31;5;88m" << universidad<< "\x1B[m"<< "\n"
		<< "\x1B[1;97m" << escuela << "\x1B[m"<< "\n"
		<< curso << "\n"
		<< "\x1B[1;97m" << alumnos<< "\x1B[m"<< "\n"
		<< ciudad_año << "\n"; 
}
void pantalla_start(bool skip, Listas& lista_has, Listas& lista_viv, Usuario& usuario1){
	bool r = true;
	char usuario[64];
	char contrasena[64];
	char nombre[64];
	int edad;
	int DNI;

	if (skip == false){
		system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		cout<< "\x1B[1;97m" << "\n\tBienvenido" << "\x1B[m \n\n";
		cout<< "\x1B[1;97m" << "\n\tPara comenzar, cree un usuario" << "\x1B[m \n";
		cout<< "\tIngrese su nombre:  ";
		cin>>nombre;
		usuario1.nombre=nombre;
		if (std::cin.fail()) { //comprabacion de erroes
			error_valor();
		}
		cout<< "\tIngrese su edad:  ";
		cin>>edad;
		usuario1.edad=edad;
		if (cin.fail()) { //comprabacion de erroes
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
		if (cin.fail()) { //comprabacion de erroes
			error_valor();
		}

	}
		//if -> admin o vendedor?{ 
	if ((usuario!="") && (contrasena!="") ){
		Pedido Pedido1(lista_has, lista_viv, usuario1);
		Catalogo catalogo1(lista_has, lista_viv, usuario1);
		CanalesV canales1(lista_has, lista_viv, usuario1);
		Pedido1.setCatalogo(&catalogo1);
		Pedido1.setCanales(&canales1);
		catalogo1.set_canalesPtr(&canales1);
		catalogo1.set_pedidoPtr(&Pedido1);
		canales1.set_pedidoPtr(&Pedido1);
		canales1.set_catalogoPtr(&catalogo1);
		InterfazAdmin admin1(catalogo1, Pedido1, canales1, lista_has, lista_viv, usuario1);
		InterfazVendedor vendedor1(catalogo1, Pedido1, canales1, lista_has, lista_viv, usuario1);
		Interfaz* interfazPtr;
		if (usuario1.contrasena[0] == 'a') {
			system("cls");
			interfazPtr = &admin1;
		} else {		
			system("cls");
			interfazPtr = &vendedor1;
		}
		interfazPtr->menu();
	} else {
		cout << "\nUsuario y contraseña nulos no permitidos" << "\x1B[m \n";
	}
}
void limpiar_archivo(int tipo_archivo){
	ofstream archivo;
    if (tipo_archivo==1){
        archivo.open("../src/Project_0013/data_array.txt", ios::trunc);
    } else {
        archivo.open("../src/Project_0013/data_ped.txt", ios::trunc);//posible añadir otro caso para otro archivo
    }
	if (!archivo) {
		cerr << "Error al abrir el archivoo" << endl;
	}
    archivo.close();
}
void add_listas_pedidos(Listas& lista_has, Listas& lista_viv, Listas& productos_anadidos_has, Listas& productos_anadidos_viv){
	double data;
	int index;
	Producto producto_añadir;
	ifstream archivo_arrays("../src/Project_0013/data_array.txt");
	if (!archivo_arrays.is_open()) {
		cerr << "Errorrr" << endl;
	}
	while (archivo_arrays >> data) {
		if (data - static_cast<int>(data) == 0.0) {
			index = static_cast<int>(data);
			producto_añadir = lista_viv.get_elemento(index);
			productos_anadidos_viv.añadir_elemento(producto_añadir);
		} else {
			producto_añadir = lista_has.get_elemento(index);
			productos_anadidos_has.añadir_elemento(producto_añadir);
			index = data;
		}
	}
	archivo_arrays.close();//
}