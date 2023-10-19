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
	 
    Producto (string nom_l, string desc_l, string niv_l, string grad_l, string area_l, int cod_l, int pre_l, int sto_l){
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
void instanciar_muestras(Producto array_libros[]);
void print_tabla_libros(Producto array_libros[]);

int main(){
     Producto array_libros[4] = {
        Producto("Libro Mat 'Crecemos Juntos'", "descripcion 1", "primaria", "8°grado", "matematica", 20, 120, 20112),
        Producto("Libro Com 'Crecemos Juntos'", "descripcion 2", "primaria", "2°grado", "comunicacion", 21, 122, 20112),
        Producto("Libro CS 'Aprende'", "descripcion 3", "secundaria", "4°grado", "ciencias sociales", 23, 128, 2017),
        Producto("Libro Personal Social 'Crecemos Juntos'", "descripcion 4", "primaria", "1°grado", "personal", 112, 129, 2019)
    };

    print_tabla_libros(array_libros);

    return 0;
} 

void instanciar_muestras(Producto array_libros[]){
	array_libros[0] = Producto("Mat 'Crecemos Juntos'", "descripcion 1", "primaria", "8°grado", "matematica", 20, 120, 20112);
    array_libros[1] = Producto("Com 'Crecemos Juntos'", "descripcion 2", "primaria", "2°grado", "comunicacion", 21, 122, 20112);
    array_libros[2] = Producto("CS 'Aprende'", "descripcion 3", "secundaria", "4°grado", "ciencias sociales", 23, 128, 2017);
    array_libros[3] = Producto("Personal Social 'Crecemos Juntos'", "descripcion 4", "primaria", "1°grado", "personal", 112, 129, 2019);
}

void print_tabla_libros(Producto array_libros[]){
	cout << left << setw(30) << "Nombre" << left << setw(25) << "descripcion" << left << setw(12) << "Nivel" << left << setw(12) << "Grado" << left << setw(12) << "Area" << left << setw(12) << "ISBN" << left << setw(12) << "Price" << left << setw(8) << "Stock\n";
		//left << setw(12) << "Marks" << left  << setw(8) << "Year\n";
    for (int i = 0; i < 4; i++){
        cout << left << setw(30) << array_libros[i].nombreLibro
            << left << setw(25) << array_libros[i].descripcionLib 
			<< left << setw(12) << array_libros[i].nivel
			<< left << setw(12) << array_libros[i].grado
			<< left << setw(12) << array_libros[i].area
			<< left << setw(12) << array_libros[i].codigoISBN
			<< left << setw(12) << array_libros[i].precio
            << left << setw(8) << array_libros[i].stock << endl;
    }
}