#include <iostream>
#include "clase_factura.h"
using namespace std;
Factura::Factura() : Venta() {
    numero_factura=0;
}
void Factura::setNumero_factura(int num_f) {
    numero_factura=num_f;
}
int Factura::getNumero_factura() const {
    return numero_factura;
}
void Factura::setRazon_social(char* razon_soc) {
    if (razon_soc != nullptr) {
        if (razon_social != nullptr) {
            delete[] razon_social;
        }
        int largo{0};
        while (razon_soc[largo] != '\0'){
        largo++;
    }
        razon_social = new char[largo + 1];
        if (!razon_social) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            razon_social[i] = razon_soc[i];
        }
        razon_social[largo] = '\0';
    }
}
char* Factura::getRazon_social() const {
    return razon_social;
}
void Factura::print_comprobante() {
    cout << "---------------------------------------------" << endl;				
    setArray_productos();
	cout << "---------------------------------------------" << endl
    	 << "                    FACTURA                   " << endl
		 << "Santillana S.A.C" << endl
		 << "Av. 10 de Noviembre 2do piso" << endl
		 << "Tel. 985 67 78" << endl
		 << "RUC 20489810981" << endl
         << asctime(localtime(&tiempoactual)) << endl
    	 << "---------------------------------------------" << endl
    	 << "    Numero de factura: " << numero_factura << endl
    	 << "\n    Cliente: " << nombre_cliente << endl
		 << "    Numero de RUC: " << ruc << endl
		 << "    Direccion: " << direccion << endl
		 << "    Telefono: " << telefono << endl
    	 << "---------------------------------------------" << endl
		 << "    DETALLES                                " << endl
    	 << left << setw(38) << "Producto" << setw(10) << "Cantidad" << setw(15) << "Precio Unitario" << setw(15) << "Subtotal" << endl
    	 << "---------------------------------------------" << endl;
	for (int i = 0; i < tamaño_array; i++) {
   	 	cout << left << setw(38) << array_productos[i].getNombreLibro() << setw(10) << array_productos[i].get_cantidad() << setw(15) << array_productos[i].getPrecio() << setw(15) << array_productos[i].get_subtotal() << endl;
		total_venta += array_productos[i].get_subtotal();
	}
    cout << "---------------------------------------------" << endl
         << right << setw(45) << "Total de compra: $" << total_venta << endl
         << "---------------------------------------------" << endl
         << "¡Gracias por su compra!" << endl;
}

