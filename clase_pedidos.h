//clase_pedidos.h
#include <iostream>
#include <iomanip>
#ifndef CLASE_PEDIDOS_H
#define CLASE_PEDIDOS_H
class Pedido {
public:
    char* nombreCole;
	char* direccionCole;
	char* emailCole;
	char* nombreResp;
	int numTele;
    long long codigoCole;
    long long codigoRUC;
	Pedido();
    Pedido (const char *nom_c, const char *dir_c, const char *email_c, const char *nombre_r, int num_tel, long long cod_col, long long cod_ruc);
    Pedido(const Pedido& copy);
	~Pedido();
    void set_char2(char*& atributo, char param[50]);
    void print_pedido();
};
#endif
