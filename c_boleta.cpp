#include "c_boleta.h"
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
	cout << "\t---------------------------------------------" << endl;				
    setArray_productos();
	cout << "\t---------------------------------------------" << endl
    	 << "\t                    BOLETA                   " << endl
		 << "\tSantillana S.A.C" << endl
		 << "\tAv. 10 de Noviembre 2do piso" << endl
		 << "\tTel. 985 67 78" << endl
		 << "\tRUC 20489810981" << endl
		 << "\t" << asctime(localtime(&tiempoactual)) << endl
    	 << "\t---------------------------------------------" << endl
    	 << "\t    Numero de boleta: " << numero_boleta << endl
    	 << "\n\t    Cliente: " << nombre_cliente << endl
		 << "\t    Numero de DNI: " << dni << endl
		 << "\t    Direccion: " << direccion << endl
		 << "\t    Telefono: " << telefono << endl
    	 << "\t---------------------------------------------" << endl
		 << "\t    DETALLES                                " << endl
    	<< "\t"  << left << setw(38) << "Producto" << setw(10) << "Cantidad" << setw(15) << "Precio Unitario" << setw(15) << "Subtotal" << endl
    	 << "\t---------------------------------------------" << endl;
	for (int i = 0; i < tamaño_array; i++) {
   	 	cout<< "\t"  << left << setw(38) << array_productos[i].getNombreLibro() << setw(10) << array_productos[i].get_cantidad() << setw(15) << array_productos[i].getPrecio() << setw(15) << array_productos[i].get_subtotal() << endl;
		total_venta += array_productos[i].get_subtotal();
	}

    cout << "\t---------------------------------------------" << endl
    	 << "\t" << right << setw(45) << "Total de compra: S/" << total_venta << endl
         << "\t---------------------------------------------" << endl
    	 << "\tGracias por su compra!" << endl;
}