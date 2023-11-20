// clase_producto.h
#ifndef CLASE_PRODUCTO_H
#define CLASE_PRODUCTO_H

class Producto {
private:
    char* codigoISBN;
    char* nombreLibro;
    char* descripcionLib;
    char* nivel;
    char* area;
    int grado;
    float precio;
    int stock;

public:
    Producto();
    Producto(const char* cod_l, const char* nom_l, const char* desc_l, const char* niv_l, int grad_l, const char* area_l, float pre_l, int sto_l);
    Producto(const Producto& copy);
    ~Producto();

    void setCodigoISBN(const char* cod_l);
    const char* getCodigoISBN() const;

    void setNombreLibro(const char* nom_l);
    const char* getNombreLibro() const;

    void setDescripcionLib(const char* desc_l);
    const char* getDescripcionLib() const;

    void setNivel(const char* niv_l);
    const char* getNivel() const;

    void setGrado(int grad_l);
    int getGrado() const;

    void setArea(const char* area_l);
    const char* getArea() const;

    void setPrecio(float pre_l);
    float getPrecio() const;

    void setStock(int sto_l);
    int getStock() const;

    void printProducto() const;
};

#endif
