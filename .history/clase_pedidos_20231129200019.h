//clase_pedidos.h
#include <iostream>
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"
#ifndef CLASE_PEDIDOS_H
#define CLASE_PEDIDOS_H
class Pedido {
private:
    char* nombreCole;
    char* direccionCole;
    char* emailCole;
    char* nombreResp;
    int numTele;
    long long codigoCole;
    long long codigoRUC;

    Pedido Pedido1;	
	Listas lista_has;
	Listas lista_viv;
	Usuario usuario1;
public:
    
    Pedido();
    Pedido(const char* nom_c, const char* dir_c, const char* email_c, const char* nombre_r, int num_tel, long long cod_col, long long cod_ruc);
    /*Pedido(const Pedido& copy);*/
    ~Pedido();

    void tab_pedido();

    void setNombreCole(const char* nom_c);
    const char* getNombreCole() const;

    void setDireccionCole(const char* dir_c);
    const char* getDireccionCole() const;

    void setEmailCole(const char* email_c);
    const char* getEmailCole() const;

    void setNombreResp(const char* nombre_r);
    const char* getNombreResp() const;

    void setNumTele(int num_tel);
    int getNumTele() const;

    void setCodigoCole(long long cod_col);
    long long getCodigoCole() const;

    void setCodigoRUC(long long cod_ruc);
    long long getCodigoRUC() const;

    void print_pedido() const;
};
#endif
