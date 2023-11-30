#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "header1.h"
//
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_canales_v.h"
#include "clase_catalogo.h"
using namespace std;

Pedido::Pedido() {
    cerr << "constructor nulo pedidos invocado xd" << endl;
    nombreCole = nullptr;
    direccionCole = nullptr;
    emailCole = nullptr;
    nombreResp = nullptr;
    numTele = 0;
    codigoCole = 0;
    codigoRUC = 0;
}

Pedido::Pedido(const char* nom_c, const char* dir_c, const char* email_c, const char* nombre_r, int num_tel, long long cod_col, long long cod_ruc) {
    cerr << "constructor lleno invocado xd" << endl;
    codigoCole = cod_col;
    setNombreCole(nom_c);
    setDireccionCole(dir_c);
    setEmailCole(email_c);
    setNombreResp(nombre_r);
    setNumTele(num_tel);
    setCodigoRUC(cod_ruc);
}

/*Pedido::Pedido(const Pedido& copy) {
    cerr << "constructor de copia invocado xd" << endl;
    numTele = copy.numTele;
    codigoCole = copy.codigoCole;
    codigoRUC = copy.codigoRUC;
    // Copy constructor for dynamic memory
    setNombreCole(copy.nombreCole);
    setDireccionCole(copy.direccionCole);
    setEmailCole(copy.emailCole);
    setNombreResp(copy.nombreResp);
}*/

Pedido::~Pedido() {
    cerr << "\nDestructor de pedido invocado";
    delete[] nombreCole;
    delete[] direccionCole;
    delete[] emailCole;
    delete[] nombreResp;
}

void Pedido::tab_pedido() {
	bool retro = true;
	int op;
	do{
		system("cls");
		cout<<"\tPEDIDOS\n"
			<< "\x1B[33;5;88m" << "\n\t1. Crear Nuevo Pedido" << "\x1B[m"<< "\n"
		 	<< "\x1B[33;5;88m" << "\n\t2. Regresar al Menu" << "\x1B[m"<< "\n"
			<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || !(op >= 1 && op <=4)){
			error_valor();
		}else{
			ofstream archivo("../src/Project_0013/data_ped.txt", ios::out);
            if (!archivo) {
                cerr << "Error al abrir el archivoo" << endl;
            }
			switch (op){
				case 1:
					system("cls");
					cout<<"\tPEDIDOS\n"
						<<"\t\nNuevo Pedido\n";
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
						setCodigoCole(codi);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese nombre del colegio: ";
						cin >> nom;
						setNombreCole(nom);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese direccion del colegio:\n";
						cin >> dir;
						setDireccionCole(dir);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese telefono del colegio:\n";
						cin >> num_tel;
						setNumTele(num_tel);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese email del colegio:\n";
						cin >> email;
						setEmailCole(email);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese RUC del colegio:\n";
						cin >> cod_ruc;
						setCodigoRUC(cod_ruc);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);

					do {
						cout << "\n\t- Ingrese nombre del responsable del colegio:\n";
						cin >> nom_resp;
						setNombreResp(nom_resp);
						if (cin.fail()) {
							error_valor();
						} else {
							break;
						}
					} while (true);
					print_pedido();
                    
                    archivo<<nombreCole<<", "<<codigoCole<<", "<<direccionCole<<", "<<emailCole<<", "<<nombreResp<<", "<<numTele<<", "<<codigoRUC<<endl;
					retro= false;
                    int op;
                    bool retro1 = true;
                    do {
                        cout << "exe pedidos\x1B[88m" << "\n\t1. Regresar al Menu" << "\x1B[m" << "\n"
                            << "\x1B[88m" << "\n\t2. Regresar a Pedidos" << "\x1B[m" << "\n"
                            << "\x1B[88m" << "\n\t3. Ir a Catalogo" << "\x1B[m" << "\n"
                            << "\x1B[46m" << "\n\tEscoger Opcion: " << "\x1B[m";
                        cin >> op;
                        if (std::cin.fail() || !(op >= 1 && op <= 3)) {
                            error_valor();
                        } else {
                            switch (op) {
                                case 1:
                                    retro1 = false;
                                    //InterfazV::menu();
                                    break;
                                case 2:
                                    retro1 = false;
                                    tab_pedido();
                                    break;
                                case 3:
                                    retro1 = false;
                                    //catalo;
                                    break;
                                default:
                                    error_valor();
                            }
                        }
                    } while (retro1);
                    break;
				case 2:
                    
					retro= false;
				    break;
			}
            archivo.close();

		}
	} while(retro);
}

void Pedido::setNombreCole(const char* nom_c) {
    if (nom_c != nullptr) {
        if (nombreCole != nullptr) {
            delete[] nombreCole;
        }
        int largo{0};
        while (nom_c[largo] != '\0'){
        largo++;
    }
        nombreCole = new char[largo + 1];
        if (!nombreCole) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            nombreCole[i] = nom_c[i];
        }

        nombreCole[largo] = '\0';
    }
}

const char* Pedido::getNombreCole() const {
    return nombreCole;
}

void Pedido::setDireccionCole(const char* dir_c) {
    if (dir_c != nullptr) {
        if (direccionCole != nullptr) {
            delete[] direccionCole;
        }
        int largo{0};
        while (dir_c[largo] != '\0'){
        largo++;
    }
        direccionCole = new char[largo + 1];
        if (!direccionCole) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            direccionCole[i] = dir_c[i];
        }

        direccionCole[largo] = '\0';
    }
}

const char* Pedido::getDireccionCole() const {
    return direccionCole;
}

void Pedido::setEmailCole(const char* email_c) {
    if (email_c != nullptr) {
        if (emailCole != nullptr) {
            delete[] emailCole;
        }
        int largo{0};
        while (email_c[largo] != '\0'){
        largo++;
    }
        emailCole = new char[largo + 1];
        if (!emailCole) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            emailCole[i] = email_c[i];
        }

        emailCole[largo] = '\0';
    }
}

const char* Pedido::getEmailCole() const {
    return emailCole;
}

void Pedido::setNombreResp(const char* nombre_r) {
    if (nombre_r != nullptr) {
        if (nombreResp != nullptr) {
            delete[] nombreResp;
        }
        int largo{0};
        while (nombre_r[largo] != '\0'){
        largo++;
    }
        nombreResp = new char[largo + 1];
        if (!nombreResp) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            nombreResp[i] = nombre_r[i];
        }

        nombreResp[largo] = '\0';
    }
}

const char* Pedido::getNombreResp() const {
    return nombreResp;
}

void Pedido::setNumTele(int num_tel) {
    if (num_tel >= 0) {
        numTele = num_tel;
    }
}

int Pedido::getNumTele() const {
    return numTele;
}

void Pedido::setCodigoCole(long long cod_col) {
    if (cod_col >= 0) {
        codigoCole = cod_col;
    }
}

long long Pedido::getCodigoCole() const {
    return codigoCole;
}

void Pedido::setCodigoRUC(long long cod_ruc) {
    if (cod_ruc >= 0) {
        codigoRUC = cod_ruc;
    }
}

long long Pedido::getCodigoRUC() const {
    return codigoRUC;
}

void Pedido::print_pedido() const {
    cout << "\n\tResumen Pedido: \n\n"
         << "Nombre del Colegio: " << (nombreCole ? nombreCole : "N/A") << endl
         << "Codigo del Colegio: " << codigoCole << endl
         << "Direccion: " << (direccionCole ? direccionCole : "N/A") << endl
         << "Email: " << (emailCole ? emailCole : "N/A") << endl
         << "Nombre del Responsable: " << (nombreResp ? nombreResp : "N/A") << endl
         << "Numero de Telefono: " << numTele << endl
         << "Codigo de RUC: " << codigoRUC << endl;
}

/*#include <iostream>
#include "clase_pedidos.h"
#include "wa.h"
using namespace std;
Pedido::Pedido(){
    cerr << "constructor nulo invocado xd" << endl;
    nombreCole = nullptr;
    direccionCole = nullptr;
    emailCole = nullptr;
    nombreResp = nullptr;
    numTele = 0;
    codigoCole = 0;
    codigoRUC = 0;
}
Pedido::Pedido(const char *nom_c, const char *dir_c, const char *email_c, const char *nombre_r, int num_tel, long long cod_col, long long cod_ruc) {
    cerr << "constructor lleno invocado xd" << endl;
    codigoCole = cod_col;
    /*set_char(nombreCole, nom_c);
    set_char(direccionCole, dir_c);
    set_char(emailCole, email_c);
    set_char(nombreResp, nombre_r);
    numTele = num_tel;
    codigoRUC = cod_ruc;
}

Pedido::Pedido(const Pedido& copy) {
    numTele = copy.numTele;
    codigoCole = copy.codigoCole;
    codigoRUC = copy.codigoRUC;
}
Pedido::~Pedido(){
	cerr << "\nDestructor invocado";
}

void Pedido::set_char2(char*& atributo, char param[50]) {
    //cerr << "no se pudo asignar char en pedidos xd" << endl;
    int largo{0};
    while (param[largo] != '\0'){
        largo++;
    }
    cerr << largo << endl;
    atributo = new char[largo + 1];
    if (!atributo) {
        cerr << "no se pudo asignar memoria xd" << endl;
    }
    for (int i = 0; i < largo; i++) {
        atributo[i] = param[i];
    }

    atributo[largo] = '\0'; 
}
void Pedido::print_pedido()  {
    cout << "\n\tResumen Pedido: \n\n"
        << "Nombre del Colegio: " << *nombreCole << endl
        << "Codigo del Colegio: " << codigoCole << endl
        << "Direccion: " << direccionCole << endl
        << "Email: " << emailCole << endl
        << "Nombre del Responsable: " << nombreResp << endl
        << "Numero de Telefono: " << numTele << endl
        << "Codigo de RUC: " << codigoRUC << endl;
}*/