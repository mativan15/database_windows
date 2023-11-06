#include <iostream>
#include "clase_pedidos.h"
using namespace std;
Pedido::Pedido(){
    nombreCole[0] = '\0';
    direccionCole[0] = '\0';
    emailCole[0] = '\0';
    nombreResp[0] = '\0';
    numTele = 0;
    codigoCole = 0;
    codigoRUC = 0;
}
Pedido::Pedido(char *nombreCole, char *direccionCole, char *emailCole, char *nombreResp, int num_tel, long long cod_col, long long cod_ruc) {

}
void Pedido::setnombreCole(char *nombreCole) {
    for (int i; i<80; i++) {
        nombreCole[i] = nombreCole[i];
        if (nombreCole[i] == '\0') {
            break;
        }
    }
}
void Pedido::setdireccionCole(char *direccionCole) {
    for (int i; i<64; i++) {
        direccionCole[i] = direccionCole[i];
        if (direccionCole[i] == '\0') {
            break;
        }
    }
}
void Pedido::setemailCole(char *emailCole) {
    for (int i; i<64; i++) {
        emailCole[i] = emailCole[i];
        if (emailCole[i] == '\0') {
            break;
        }
    }
}
void Pedido::setnombreResp(char *nombreResp) {
    for (int i; i<64; i++) {
        nombreResp[i] = nombreResp[i];
        if (nombreResp[i] == '\0') {
            break;
        }
    }
}
void Pedido::print_pedido()  {
    cout << "\n\tResumen Pedido: \n\n"
		<< "\n\tResumen Pedido: \n\n"
        << "Nombre del Colegio: " << nombreCole << endl
        << "Codigo del Colegio: " << codigoCole << endl
        << "Direccion: " << direccionCole << endl
        << "Email: " << emailCole << endl
        << "Nombre del Responsable: " << nombreResp << endl
        << "Numero de Telefono: " << numTele << endl
        << "Codigo de RUC: " << codigoRUC << endl;
}