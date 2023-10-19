#include <iostream>
#include <iomanip>

using namespace std;

class Producto {
public:
    string nombreLibro;
	string descripcionLib;
	string nivel;
	string area;
	int grado;
    int codigoISBN;
    int precio;
    int stock;
	Producto() {
        nombreLibro = "";
        descripcionLib = "";
        nivel = "";
        area = "";
		grado = 0;
        codigoISBN = 0;
        precio = 0;
        stock = 0;
    }
    Producto (string nom_l, string desc_l, string niv_l, string area_l, int grad_l, int cod_l, int pre_l, int sto_l){
        nombreLibro = nom_l;
		descripcionLib = desc_l;
		nivel = niv_l;
		area = area_l;
		grado = grad_l;
		codigoISBN = cod_l;
		precio = pre_l;
		stock = sto_l;
    }
};
void instanciar_muestras(Producto array_libros[]);
void print_tabla_libros(Producto array_libros[]);

int main(){
    Producto array_libros[4];
	instanciar_muestras(array_libros);
    print_tabla_libros(array_libros);

    return 0;
} 

void instanciar_muestras(Producto array_libros[]){
	array_libros[0] = Producto("Mat 'Crecemos Juntos'", "descripcion 1", "primaria",  "matematica",4, 20, 120, 20112);
    array_libros[1] = Producto("Com 'Crecemos Juntos'", "descripcion 2", "primaria", "comunicacion",2 , 21, 122, 20112);
    array_libros[2] = Producto("CS 'Aprende'", "descripcion 3", "secundaria", "ciencias s.", 4, 23, 128, 2017);
    array_libros[3] = Producto("Personal Social 'Crecemos J'", "descripcion 4", "primaria", "personal", 1, 112, 129, 2019);
}

void print_tabla_libros(Producto array_libros[]){
	system("cls");
	cout << left << setw(30) << "Nombre" << left << setw(25) << "Descripcion" << left << setw(12) << "Nivel" << left << setw(12) << "Area" << left << setw(12) << "Grado" << left << setw(12) << "ISBN" << left << setw(12) << "Price" << left << setw(8) << "Stock" << endl;

    for (int i = 0; i < 4; i++){
        cout << left << setw(30) << array_libros[i].nombreLibro
            << left << setw(25) << array_libros[i].descripcionLib 
			<< left << setw(12) << array_libros[i].nivel
			<< left << setw(12) << array_libros[i].area
			<< left << setw(12) << array_libros[i].grado
			<< left << setw(12) << array_libros[i].codigoISBN
			<< left << setw(12) << array_libros[i].precio
            << left << setw(8) << array_libros[i].stock << endl;
    }
}