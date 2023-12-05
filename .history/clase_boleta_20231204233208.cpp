#include "clase_boleta.h"
using namespace std;

Boleta::Boleta() : Venta() {
	dni=0;
	numero_boleta=0;
}
void Boleta::setNumero_boleta(int num_b){
	numero_boleta=num_b;
}
int Boleta::getNumero_boleta() const{
	return numero_boleta;
}
void Boleta::setdni(int dnI){
	dni=dnI;
}
int Boleta::getdnI() const{
	return dni;
}
void Boleta::print_comprobante() {
	cout << "---------------------------------------------" << endl;				
    setArray_productos();
	cout << "---------------------------------------------" << endl
    	 << "                    BOLETA                   " << endl
		 << "Santillana S.A.C" << endl
		 << "Av. 10 de Noviembre 2do piso" << endl
		 << "Tel. 985 67 78" << endl
		 << "RUC 20489810981" << endl
    	 << "---------------------------------------------" << endl
    	 << "    Numero de boleta: " << numero_boleta << endl
    	 << "\n    Cliente: " << nombre_cliente << endl
		 << "    Numero de DNI: " << dni << endl
		 << "    Direccion: " << direccion << endl
		 << "    Telefono: " << telefono << endl
    	 << "---------------------------------------------" << endl
		 << "    DETALLES                                " << endl
    	 << left << setw(20) << "Producto" << setw(10) << "Cantidad" << setw(15) << "Precio Unitario" << setw(15) << "Subtotal" << endl
    	 << "---------------------------------------------" << endl;
	for (int i = 0; i < tamaño_array; i++) {
   	 	cout << left << setw(20) << array_productos[i].getNombreLibro() << setw(10) << array_productos[i].get_cantidad() << setw(15) << array_productos[i].getPrecio() << setw(15) << array_productos[i].get_subtotal() << endl;
		total_venta += array_productos[i].get_subtotal();
	}

    cout << "---------------------------------------------" << endl;

    // Total de la compra
    cout << right << setw(45) << "Total de compra: $" << total_venta << endl;
    cout << "---------------------------------------------" << endl;

    // Fin de la boleta
    cout << "¡Gracias por su compra!" << endl;
}