#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"

using namespace std;


void instanciar_muestras(Producto array_libros[]){
	array_libros[0] = Producto("Mat 'Crecemos Juntos'", "descripcion 1", "primaria",  "matematica",4, 20, 120, 20112);
    array_libros[1] = Producto("Com 'Crecemos Juntos'", "descripcion 2", "primaria", "comunicacion",2 , 21, 122, 20112);
    array_libros[2] = Producto("CS 'Aprende'", "descripcion 3", "secundaria", "ciencias s.", 4, 23, 128, 2017);
    array_libros[3] = Producto("Personal Social 'Crecemos J'", "descripcion 4", "primaria", "personal", 1, 112, 129, 2019);
}

void print_tabla_libros(Producto array_libros[]){
	system("cls");
	cout << left << setw(30) << "Nombre" << left << setw(20) << "Descripcion" << left << setw(12) << "Nivel" << left << setw(15) << "Area" << left << setw(12) << "Grado" << left << setw(12) << "ISBN" << left << setw(12) << "Price" << left << setw(8) << "Stock" << endl;

    for (int i = 0; i < 4; i++){
        cout << left << setw(30) << array_libros[i].nombreLibro
            << left << setw(20) << array_libros[i].descripcionLib 
			<< left << setw(12) << array_libros[i].nivel
			<< left << setw(15) << array_libros[i].area
			<< left << setw(12) << array_libros[i].grado
			<< left << setw(12) << array_libros[i].codigoISBN
			<< left << setw(12) << array_libros[i].precio
            << left << setw(8) << array_libros[i].stock << endl;
    }
}

void pantalla_start(Producto array_libros[]){
	bool r= true;
	system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		cout<< "\x1B[1;97m" << "\n\tBienvenido" << "\x1B[m \n\n";
		cout<< "\x1B[1;97m" << "\n\tPara comenzar, cree un usuario" << "\x1B[m \n";
		string usuario="";
		string contraseña="";
		cout<< "\tIngrese el nombre de usuario:  ";
		cin>>usuario;
		if (std::cin.fail()) { //comprabacion de erroes
			std::cout << "\nValor incorrecto!!! Ingrese de nuevo:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		}
		cout<< "\tIngrese la contrasena:  ";
		cin>>contraseña;
		if (std::cin.fail()) { //comprabacion de erroes
			std::cout << "\nValor incorrecto!!! Ingrese de nuevo:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		}

		if ((usuario!="") && (contraseña!="") ){
			menu(array_libros);
		}
}

void menu(Producto array_libros[]){
	bool repite = true;
	int opcion;
	bool repertirinicio = true;	
	
	do {	
		system("cls");
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\tMENU" << "\x1B[m \n";
		cout << "\x1B[1;97m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\t4. SALIR" << "\x1B[m"<< "\n";
		cout << "\x1B[1;97m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
		
		if (std::cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)) { //comprabacion de erroes
			std::cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		} else {
			switch (opcion){
				case 1:
					system("cls");
					catalogo(array_libros);
					break;
				   
				case 2:
					system("cls");
					pedidos();
					break;
				case 3:
					system("cls");
					canales_de_venta();
					break;

				case 4:
				   repite = false;
				   
				   break;			
			}
		}
	} while (repite);
}
	
void caratula(){
	string universidad = "UCSP "; 
	string escuela = "Escuela Profesional de Ciencia de la Computacion I"; 
	string curso ="Ciencia de la Computacion I"; 
	string alumnos = "Alumnos: \nIvan Matthias Sardon Medina \nAnthony Huicho Perez";
	string ciudad_año = "Arequipa 2023 - II";
    cout << "\x1B[31;5;88m" << universidad<< "\x1B[m"<< "\n";
	cout << "\x1B[1;97m" << escuela << "\x1B[m"<< "\n";
	cout << curso << "\n";
	cout << "\x1B[1;97m" << alumnos<< "\x1B[m"<< "\n";
	cout << ciudad_año << "\n"; 
}

void catalogo(Producto array_libros[]){
	bool retro =true;
	int op;
	cout<<"\n\tCatalogo\n";
    print_tabla_libros(array_libros);
	cout<<"\n\n";
	do{
		cout << "\x1B[34m" << "\n\t1. Regresar" << "\x1B[m"<< "\n";
		cout << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (std::cin.fail() || (op != 1) ){
			std::cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		}else{
			switch (op){
				case 1:
					retro = false;
				   break;
				case 2:
					retro= true;
				   break;
			}
		}
	}while(retro);
}