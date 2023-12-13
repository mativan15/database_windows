// InterfazAdmin.cpp
#include <fstream>
#include "c_interfaz_a.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "header1.h"
#include "c_interfaz.h"
#include "c_catalogo.h"
#include "c_canales_v.h"
InterfazAdmin::InterfazAdmin(Catalogo& catalogo1, Pedido& pedido, CanalesV& canales1, Listas& listaHas, Listas& listaViv, Usuario& usuario)
    : Interfaz(catalogo1, pedido, canales1, listaHas, listaViv, usuario) {
}

void InterfazAdmin::menu() {
    bool repite = true;
	int opcion;
	system("cls");
    do {	
        cout << "\x1B[1;97m" << "\n\t\t\t\t\t\tADMIN MODE" << "\x1B[m \n"
		     << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		cout << "\x1B[1;97m" << "\n\t\tBIENVENIDO, " << usuario1.nombre << "\x1B[m \n"
		     << "\x1B[1;97m" << "\n\tMENU" << "\x1B[m \n"
		     << "\x1B[1;97m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n"
             << "\x1B[1;97m" << "\n\t4. FUNCIONES ADMIN" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\t5. SALIR" << "\x1B[m"<< "\n"
		     << "\x1B[1;97m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
			
		if (cin.fail() || !(opcion >= 1 && opcion <= 5)) { //comprabacion de erroes
				error_valor();
		} else {
		    switch (opcion){
			case 1:
				system("cls");
				catalogo1.tab_catalogo();
				repite = false;
				break;  
			case 2:
				system("cls");
				Pedido1.tab_pedido();
				repite = false;
				break;
			case 3:
				system("cls");
				canales1.tab_canales();
				repite = false;
				break;
            case 4:
				repite = false; 
                system("cls");
                funciones_admin();
				break;
			case 5:
				repite = false;   
				break;			
			}
		}
	} while (repite);
}

void InterfazAdmin::funciones_admin(){
    bool retro = true;
    int op;
    do {
        system("cls");
        cout << "\n\tFUNCIONES ADMIN\n"
             << "\x1B[34m" << "\n\t1. Editar catalogo 'HAS'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Editar catalogo 'vivo'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Editar canales Venta" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                system("cls");
                cout << "\x1B[34m" << "\n\tCATALOGO HAS" << "\x1B[m" << "\n\n";
                retro = false;
                lista_has.print_lista();
                editar_catalogo(lista_has,op);
                break;
            case 2:
                system("cls");
                cout << "\x1B[34m" << "\n\tCATALOGO VIVO" << "\x1B[m" << "\n\n";
                retro = false;
                lista_viv.print_lista();
                editar_catalogo(lista_viv,op);
                break;
            case 3:
                retro = false;
                editar_canales();
                break;
            case 4:
                retro = false;
                menu();	
                break;
            default:
                error_valor();
            }
        }
    } while (retro);
}
void InterfazAdmin::editar_catalogo(Listas& lista, int op2){
    int op;
    int index;
    bool retro = true;
    bool retro1 = true;
    do {
        cout << "\x1B[34m" << "\n\t1. Editar elemento" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Eliminar elemento" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Regresar a Funciones Admin" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                retro = false;
                cout << "\n\nIngrese el indice del producto que desea editar: " << endl;
                do {
                    cout << "\x1B[34m" << "\n\t0. para volver" << "\x1B[m" << "\n";
                    cin >> index;
                    if (cin.fail() || !(index >= 0 && index <= lista.get_tamano_lista())) {
                        error_valor();
                    } else {
                        if (index == 0) {
                            retro1 = false;
                            system("cls");
                            funciones_admin();
                        } else {
                            editar_lista(index,op2 );                 
                        }
                    }
                }while (retro1);
                break;
            case 2:
                retro = false;
                cout << "\n\nIngrese el indice del producto que desea eliminar: " << endl;
                do {
                    cout << "\x1B[34m" << "\n\t0. para volver" << "\x1B[m" << "\n";
                    cin >> index;
                    if (cin.fail() || !(index >= 0 && index <= lista.get_tamano_lista())) {
                        error_valor();
                    } else {
                        if (index == 0) {
                            retro1 = false;
                            system("cls");
                            funciones_admin();
                        } else {
                            editar_eliminar( index,op2);               
                        }
                    }
                }while (retro1);
                break;
            case 3:
                retro = false;
                funciones_admin();
                break;
            case 4:
                retro = false;
                menu();
                break;
            }
        }
    } while (retro);
}
void InterfazAdmin::editar_canales(){
    int op;
    int limite;
    bool retro = true;
    bool retro1 = true;
    do {
        cout << "\n\nIngrese el indice del canal que desea editar: " << endl
             << "\x1B[33;5;88m" << "\n\t1. Libreria: " << "\x1B[m"<< "\n"
		     << "\x1B[33;5;88m" << "\n\t2. E-commerce: "  << "\x1B[m"<< "\n"
		     << "\x1B[33;5;88m" << "\n\t3. Feria: "  << "\x1B[m"<< "\n"
		     << "\x1B[33;5;88m" << "\n\t4. Distribuidor: " << "\x1B[m"<< "\n"
             << "\x1B[34m" << "\n\t5. Regresar a Funciones Admin" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t6. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (cin.fail() || !(op >= 1 && op <= 6)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                retro = false;
                cout << "\n\nIngrese el nuevo valor limite de Libreria: " << endl;
                do {
                    cin >> limite;
                    if (cin.fail() || !(limite > 0 && limite <= 5000)) {
                        error_valor();
                    } else {
                        cout << "\naqui se implementara la funcion xd\n"; 
                        editar_canales();               
                        break;
                    }
                }while (retro1);
                break;
            case 2:
                retro = false;
                cout << "\n\nIngrese el nuevo valor limite de E-commerce: " << endl;
                do {
                    cin >> limite;
                    if (cin.fail() || !(limite > 0 && limite <= 5000)) {
                        error_valor();
                    } else {
                        cout << "\naqui se implementara la funcion xd\n"; 
                        editar_canales();               
                        break;
                    }
                }while (retro1);
                break;
            case 3:
                retro = false;
                cout << "\n\nIngrese el nuevo valor limite de Feria: " << endl;
                do {
                    cin >> limite;
                    if (cin.fail() || !(limite > 0 && limite <= 5000)) {
                        error_valor();
                    } else {
                        cout << "\naqui se implementara la funcion xd\n"; 
                        editar_canales();               
                        break;
                    }
                }while (retro1);
                break;
            case 4:
                retro = false;
                cout << "\n\nIngrese el nuevo valor limite de Distribuidor: " << endl;
                do {
                    cin >> limite;
                    if (cin.fail() || !(limite > 0 && limite <= 5000)) {
                        error_valor();
                    } else {
                        cout << "\naqui se implementara la funcion xd\n"; 
                        editar_canales();               
                        break;
                    }
                }while (retro1);
                break;
            case 5:
                retro = false;
                funciones_admin();
                break;
            case 6:
                retro = false;
                menu();
                break;
            }
        }
    } while (retro);
}

void InterfazAdmin::editar_lista(int index, int op2){
			char codigoISBN[13];
			char nombreLibro[38];
			char descripcionLib[22];
			char nivel[10];
			int grado;
			char area[22];
			float precio;
			int stock;
	if (op2==1){
			cout<<"Ingresa los datos\n";
			cout << "Escriba ISBN\n-  ";
			cin>>codigoISBN;
			cout<< " Escriba TITULO\n-  ";
			cin>>nombreLibro;
			cout<< " Escriba DESCRIPCION\n-  ";
			cin>>descripcionLib;
			cout<< " Escriba NIVEL\n-  ";
			cin>>nivel;
			cout<< " Escriba GRADO\n-  ";
			cin >> grado;
			cout<< " Escriba AREA\n-  ";
			cin>>area;
			cout<< " Escriba PRECIO\n-  ";
			cin >> precio;
			cout<< " Escriba STOCK\n-  ";
			cin >> stock;
			lista_has.array_libros_lista[index-1].setCodigoISBN(codigoISBN);
			lista_has.array_libros_lista[index-1].setNombreLibro(nombreLibro);
			lista_has.array_libros_lista[index-1].setDescripcionLib(descripcionLib);
			lista_has.array_libros_lista[index-1].setNivel(nivel);
			lista_has.array_libros_lista[index-1].setGrado(grado);
			lista_has.array_libros_lista[index-1].setArea(area);
			lista_has.array_libros_lista[index-1].setPrecio(precio);
			lista_has.array_libros_lista[index-1].setStock(stock);
			
			int maximon= 45;
			ofstream archivocam("../src/Project_0014/data_has.txt");
			for (int i{0}; i<maximon; i++)
			{
				archivocam<<
					lista_has.array_libros_lista[i].getCodigoISBN()<<","<<
					lista_has.array_libros_lista[i].getNombreLibro()<<","<<
					lista_has.array_libros_lista[i].getDescripcionLib()<<","<<
					lista_has.array_libros_lista[i].getNivel()<<","<<
					lista_has.array_libros_lista[i].getGrado()<<","<<
					lista_has.array_libros_lista[i].getArea()<<","<<
					lista_has.array_libros_lista[i].getPrecio()<<","<<
					lista_has.array_libros_lista[i].getStock();
				if(i<(maximon-1))
				{
					archivocam<<"\n";
				}
			}
	}else if(op2==2){
			cout<<"Ingresa los datos\n";

			cout << "Escriba ISBN\n-  ";
			cin>>codigoISBN;
			cout<< " Escriba TITULO\n-  ";
			cin>>nombreLibro;
			cout<< " Escriba DESCRIPCION\n-  ";
			cin>>descripcionLib;
			cout<< " Escriba NIVEL\n-  ";
			cin>>nivel;
			cout<< " Escriba GRADO\n-  ";
			cin >> grado;
			cout<< " Escriba AREA\n-  ";
			cin>>area;
			cout<< " Escriba PRECIO\n-  ";
			cin >> precio;
			cout<< " Escriba STOCK\n-  ";
			cin >> stock;
			lista_viv.array_libros_lista[index-1].setCodigoISBN(codigoISBN);
			lista_viv.array_libros_lista[index-1].setNombreLibro(nombreLibro);
			lista_viv.array_libros_lista[index-1].setDescripcionLib(descripcionLib);
			lista_viv.array_libros_lista[index-1].setNivel(nivel);
			lista_viv.array_libros_lista[index-1].setGrado(grado);
			lista_viv.array_libros_lista[index-1].setArea(area);
			lista_viv.array_libros_lista[index-1].setPrecio(precio);
			lista_viv.array_libros_lista[index-1].setStock(stock);
			
			int maximov=80;
			ofstream archivocamv("../src/Project_0014/data_viv.txt");
			for (int i{0}; i<maximov; i++)
			{
				archivocamv<<
					lista_viv.array_libros_lista[i].getCodigoISBN()<<","<<
					lista_viv.array_libros_lista[i].getNombreLibro()<<","<<
					lista_viv.array_libros_lista[i].getDescripcionLib()<<","<<
					lista_viv.array_libros_lista[i].getNivel()<<","<<
					lista_viv.array_libros_lista[i].getGrado()<<","<<
					lista_viv.array_libros_lista[i].getArea()<<","<<
					lista_viv.array_libros_lista[i].getPrecio()<<","<<
					lista_viv.array_libros_lista[i].getStock();
				if(i<(maximov-1))
				{
					archivocamv<<"\n";
				}
			}
	}
	

}	
void InterfazAdmin::editar_eliminar(int index, int op2){
	if(op2==1){
			int s;
			cout<<"Desea eliminar este objeto?\n1.s\n2.n\n";
			cin>>s;
			if (std::cin.fail() || !(s >= 1 && s <= 2)) {
				error_valor();
			}else{
				if(s==1){
						lista_has.array_libros_lista[index-1].setPrintot(false);
				}
			}
			int maximon=45;
			ofstream archivocam("../src/Project_0014/data_has.txt");
			for (int i{0}; i<maximon; i++)
			{
				if (lista_has.array_libros_lista[i].getPrintot()){
				archivocam<<
					lista_has.array_libros_lista[i].getCodigoISBN()<<","<<
					lista_has.array_libros_lista[i].getNombreLibro()<<","<<
					lista_has.array_libros_lista[i].getDescripcionLib()<<","<<
					lista_has.array_libros_lista[i].getNivel()<<","<<
					lista_has.array_libros_lista[i].getGrado()<<","<<
					lista_has.array_libros_lista[i].getArea()<<","<<
					lista_has.array_libros_lista[i].getPrecio()<<","<<
					lista_has.array_libros_lista[i].getStock();
				
				}else{
				continue;}
			}
	}else if(op2==2){
			int s2;
			cout<<"Desea eliminar este objeto?\n1.s\n2.n\n";
			cin>>s2;
			if (std::cin.fail() || !(s2 >= 1 && s2 <= 2)) {
				error_valor();
			}else{
				if(s2==1){
						lista_viv.array_libros_lista[index-1].setPrintot(false);
				}
			}
			int maximov=45;
			ofstream archivocamv("../src/Project_0014/data_viv.txt");
			for (int i{0}; i<maximov; i++)
			{
				if (lista_viv.array_libros_lista[i].getPrintot()){
				archivocamv<<
					lista_viv.array_libros_lista[i].getCodigoISBN()<<","<<
					lista_viv.array_libros_lista[i].getNombreLibro()<<","<<
					lista_viv.array_libros_lista[i].getDescripcionLib()<<","<<
					lista_viv.array_libros_lista[i].getNivel()<<","<<
					lista_viv.array_libros_lista[i].getGrado()<<","<<
					lista_viv.array_libros_lista[i].getArea()<<","<<
					lista_viv.array_libros_lista[i].getPrecio()<<","<<
					lista_viv.array_libros_lista[i].getStock();
				 
				}else{
				continue;}
			}
	}
	
}
