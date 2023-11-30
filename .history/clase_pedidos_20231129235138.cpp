#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "header1.h"
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
    catalogoPtr = nullptr;//
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();

}

Pedido::Pedido(Listas& lista_has,Listas& lista_viv,Usuario& usuario1) {
    cerr << "constructor lleno pedidos invocado xd" << endl;
    nombreCole = nullptr;
    direccionCole = nullptr;
    emailCole = nullptr;
    nombreResp = nullptr;
    numTele = 0;
    codigoCole = 0;
    codigoRUC = 0;
    catalogoPtr = nullptr;
    canalesPtr = nullptr;
    this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
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
			<< "\x1B[33;5;88m" << "\n\t1. Crear Nuevo Pedido (recuerda que debes llenar el carrito xd)" << "\x1B[m"<< "\n"
            << "\x1B[33;5;88m" << "\n\t2. Regresar al Menu" << "\x1B[m"<< "\n"
            << "\x1B[33;5;88m" << "\n\t3. Regresar a Catalogo" << "\x1B[m"<< "\n"
			<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || !(op >= 1 && op <=3)){
			error_valor();
		} else {
			ofstream archivo("../src/Project_0013/data_ped.txt", ios::out);
            if (!archivo) {
                cerr << "Error al abrir el archivoo" << endl;
            }
            /*int op;
            bool retro1 = true;*/
			switch (op){
			case 1:
                system("cls");
                recibir_datos();
                print_pedido();
                //print carrito de compras(); 
                do {
                    cout <<"\x1B[88m" << "\n\t1. Confirmar Pedido -> Ir a Canales de Venta" << "\x1B[m" << "\n"
                        << "\x1B[88m" << "\n\t2. Corregir datos ingresados" << "\x1B[m" << "\n"
                        << "\x1B[88m" << "\n\t3. Corregir Productos anadidos" << "\x1B[m" << "\n"
                        << "\x1B[46m" << "\n\tEscoger Opcion: " << "\x1B[m";
                    cin >> op;
                    if (std::cin.fail() || !(op >= 1 && op <= 3)) {
                        error_valor();
                    } else {
                        switch (op) {
                        case 1:
                            retro = false;
                            archivo<<nombreCole<<", "<<codigoCole<<", "<<direccionCole<<", "<<emailCole<<", "<<nombreResp<<", "<<numTele<<", "<<codigoRUC<<endl;
                            archivo.close();
                            canalesPtr->tab_canales();
                            break;
                        case 2:
                            retro = true;
                            system("cls");
                            cout << "reingresar datos" << endl;
                            recibir_datos();
                            break;
                        case 3:
                            retro = true;
                            system("cls");
                            cout << "reingresar productos" << endl;
                            //vaciar carro de compras();
                            catalogoPtr->tab_catalogo();
                            break;
                        default:
                            error_valor();
                        }
                    }
                } while (retro);
                
                
                retro= false;
                
                break;
            case 2:
                retro= false;
                pantalla_start(true, lista_has, lista_viv, usuario1);
                break;
            case 3:
                catalogoPtr->tab_catalogo();
                retro= false;
                break;
            }
            

		}
	} while(retro);
}
void Pedido::setCatalogo(Catalogo* cat) {
    this->catalogoPtr = cat;
}
void Pedido::setCanales(CanalesV* can) {
    this->canalesPtr = can;
}

void Pedido::setUsuario(Usuario* usu) {
    this->usuarioPtr = usu;
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
void Pedido::recibir_datos() {
    cout << "\x1B[34m" << "\nCREAR NUEVO PEDIDO" << "\x1B[m"<< "\n\n";
    do {
        long long codi;
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
        char nom[50];
        cout << "\n\t- Ingrese nombre del colegio: \n";
        cin >> nom;
        setNombreCole(nom);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);

    do {
        char dir[50];
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
        int num_tel;
        cin >> num_tel;
        setNumTele(num_tel);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);

    do {
        char email[50];
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
        long long cod_ruc;
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
        char nom_resp[50];
        cout << "\n\t- Ingrese nombre del responsable del colegio:\n";
        cin >> nom_resp;
        setNombreResp(nom_resp);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
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