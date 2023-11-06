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
Producto::Producto(long long cod_l, char *nom_l, char *desc_l, char *niv_l, int grad_l, char *area_l, float pre_l, int sto_l) {
    codigoISBN = cod_l;
    setnombreLibro(nom_l);
    setdescripcionLib(desc_l);
    setnivel(niv_l);
    grado = grad_l;
    setarea(area_l);
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

void Producto::setnombreLibro(char *nom_l) {
    for (int i; i<50; i++) {
        nombreLibro[i] = nom_l[i];
        if (nom_l[i] == '\0') {
            break;
        }
    }
}
void Producto::setdescripcionLib(char *desc_l) {
    for (int i; i<50; i++) {
        descripcionLib[i] = desc_l[i];
        if (desc_l[i] == '\0') {
            break;
        }
    }
}
void Producto::setnivel(char *niv_l) {
    for (int i; i<50; i++) {
        nivel[i] = niv_l[i];
        if (niv_l[i] == '\0') {
            break;
        }
    }
}
void Producto::setarea(char *area_l) {
    for (int i; i<50; i++) {
        area[i] = area_l[i];
        if (area_l[i] == '\0') {
            break;
        }
    }
}