#include <iostream>
#include <iomanip>

using namespace std;

class Producto {
public:
    string nombreLibro;
	string descripcionLib;
	string nivel;
	string grado;
	string area;
    int codigoISBN;
    int precio;
    int stock;
	 
    Producto(string nom_l, string desc_l, string niv_l, string grad_l, string area_l, int cod_l, int pre_l, int sto_l){
        nombreLibro = nom_l;
		descripcionLib = desc_l;
		nivel = niv_l;
		grado = grad_l;
		area = area_l;
		codigoISBN = cod_l;
		precio = pre_l;
		stock = sto_l;
    }
};


void print_tabla_libros(){
	cout << left << setw(10) << "Name" << left << setw(5) << "Age" << 
		left << setw(8) << "Marks" << left  << setw(5) << "Year\n";
    for (int i = 0; i < 4; i++){
        cout << left << setw(10) << array_libros[i].nombreLibro
            << left << setw(5) << array_libros[i].descripcionLib 
			<< left << setw(8) << array_libros[i].nivel
			<< left << setw(8) << array_libros[i].grado
			<< left << setw(8) << array_libros[i].area
			<< left << setw(8) << array_libros[i].codigoISBN
			<< left << setw(8) << array_libros[i].precio
            << left << setw(5) << array_libros[i].stock << endl;
    }
}
int main(){
    instanciar_muestras();

    
    return 0;
} 
void instanciar_muestras(){
	Producto array_libros[4] = {Producto("Libro Mat 'Crecemos Juntos'", "descripcion 1", "primaria", "5°grado", "matematica", 20, 80, 2018), Producto("Libro Com 'Crecemos Juntos'", "descripcion 2", "primaria", "2°grado", "comunicacion", 21, 82, 2018), Producto("Libro CS 'Aprende'", "descripcion 3", "secundaria", "4°grado", "ciencias sociales", 23, 85, 2017), Producto("Libro Personal Social 'Crecemos Juntos'", "descripcion 4", "primaria", "1°grado", "personal", 18, 89, 2019)};
}