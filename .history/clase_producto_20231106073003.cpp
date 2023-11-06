#include "clase_producto.h"

Producto::Producto() {
    codigoISBN = 0;
    nombreLibro[0] = '\0';
    descripcionLib[0] = '\0';
    nivel[0] = '\0';
	grado = 0;
    area[0] = '\0';
    precio = 0;
    stock = 0;
}
Producto::Producto(long long cod_l, const char *nom_l, const char desc_l, const char niv_l, int grad_l, const char area_l, float pre_l, int sto_l) {
    codigoISBN = cod_l;
    for (int i; i<50; i++) {
        nombreLibro[i] = nom_l[i];
        if (nom_l[i] == '\0') {
            break;
        }
    }
    grado = grad_l;

    precio = pre_l;
    stock = sto_l;
}
Producto::Producto(const Producto& copy) {
    codigoISBN = copy.codigoISBN;
    strncpy(nombreLibro, copy.nombreLibro, sizeof(nombreLibro));
    strncpy(descripcionLib, copy.descripcionLib, sizeof(descripcionLib));
    strncpy(nivel, copy.nivel, sizeof(nivel));
    grado = copy.grado;
    strncpy(area, copy.area, sizeof(area));
    precio = copy.precio;
    stock = copy.stock;
}