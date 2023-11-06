//clase_pedidos.h
#include <iostream>
#include <iomanip>
#ifndef CLASE_PEDIDOS_H
#define CLASE_PEDIDOS_H
class Pedido {
public:
    char nombreCole[80];
	char direccionCole[64];
	char emailCole[64];
	char nombreResp[64];
	int numTele;
    long long codigoCole;
    long long codigoRUC;
	Pedido();
    Pedido (char *nombreCole, char *direccionCole, char *emailCole, char *nombreResp, int num_tel, long long cod_col, long long cod_ruc);
    Pedido(const Pedido& copy);
    void setnombreCole(char *nombreCole);
    void setdireccionCole(char *direccionCole);
    void setemailCole(char *emailCole);
    void setnombreResp(char *nombreResp);
    void print_pedido();
};
#endif
