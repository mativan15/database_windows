// clase_pedidos.cpp
#include "clase_pedidos.h"
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

// Constructors and Destructor
Pedido::Pedido() {
    cerr << "constructor nulo invocado xd" << endl;
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
    cerr << "\nDestructor invocado";
    // Destructor to release dynamically allocated memory
    delete[] nombreCole;
    delete[] direccionCole;
    delete[] emailCole;
    delete[] nombreResp;
}

// Setters and Getters
void Pedido::setNombreCole(const char* nom_c) {
    if (nom_c != nullptr) {
        if (nombreCole != nullptr) {
            delete[] nombreCole;
        }

        nombreCole = new char[strlen(nom_c) + 1];
        strcpy(nombreCole, nom_c);
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

        direccionCole = new char[strlen(dir_c) + 1];
        strcpy(direccionCole, dir_c);
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

        emailCole = new char[strlen(email_c) + 1];
        strcpy(emailCole, email_c);
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

        nombreResp = new char[strlen(nombre_r) + 1];
        strcpy(nombreResp, nombre_r);
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