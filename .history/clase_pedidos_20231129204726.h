//clase_pedidos.h
#include <iostream>
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
//#include "clase_catalogo.h"
//#include "clase_canales_v.h"
#ifndef CLASE_PEDIDOS_H
#define CLASE_PEDIDOS_H
class Catalogo;
class CanalesV;
class Pedido {
private:
    char* nombreCole;
    char* direccionCole;
    char* emailCole;
    char* nombreResp;
    int numTele;
    long long codigoCole;
    long long codigoRUC;

    Catalogo* catalogoPtr;
    CanalesV* canalesPtr;
	Usuario* usuarioPtr;
public:
    
    Pedido();
    Pedido(const char* nom_c, const char* dir_c, const char* email_c, const char* nombre_r, int num_tel, long long cod_col, long long cod_ruc);
    /*Pedido(const Pedido& copy);*/
    ~Pedido();

    void tab_pedido();
    void setCatalogo(Catalogo* cat_ptr);
    void setCanales(CanalesV* can_ptr);
    void setUsuario(Usuario* usu_ptr);

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
