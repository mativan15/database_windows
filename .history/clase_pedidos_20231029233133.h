//clase_pedidos.h
#include <iostream>
#include <iomanip>
#include <string>

#ifndef CLASE_PEDIDOS_H
#define CLASE_PEDIDOS_H
using namespace std;
class Pedido {
public:
    string nombreCole;
	string direccionCole;
	string emailCole;
	string nombreResp;
	int numTele;
    long long codigoCole;
    long long codigoRUC;
	Pedido() {
        nombreCole = "";
        direccionCole = "";
        emailCole = "";
        nombreResp = "";
        numTele = 0;
        codigoCole = 0;
        codigoRUC = 0;
    }
    Pedido (string nom_col, string dir_col, string em_col, string nom_res, int num_tel, long long cod_col, long long cod_ruc){
        nombreCole = nom_col;
        direccionCole = dir_col;
        emailCole = em_col;
        nombreResp = nom_res;
        numTele = num_tel;
        codigoCole = cod_col;
        codigoRUC = cod_ruc;
    }
    void print_pedido() {
        cout << "Resumen Pedido: \n\n"
            << "Nombre del Colegio: " << nombreCole << endl
            << "Codigo del Colegio: " << codigoCole << endl
            << "Direccion: " << direccionCole << endl
            << "Email: " << emailCole << endl
            << "Nombre del Responsable: " << nombreResp << endl
            << "Numero de Telefono: " << numTele << endl
            << "Codigo de RUC: " << codigoRUC << endl;
    }
};
#endif