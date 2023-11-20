#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "clase_listas.h"
#include "clase_producto.h"

using namespace std;
Listas::Listas(int tipo) {
    
    array_libros_lista = nullptr;
	//cerr << "constructor pointer\n";
	
	//cerr << "constructor new\n";
    int contador {0};
    char nombre_archivo[13];
    ifstream archivo;
    if (tipo==1){//has
        tamano_lista = 45;
        archivo.open("../src/Project_0015/data_has.txt");
    } else {//viv
        tamano_lista = 80;
        archivo.open("../src/Project_0015/data_viv.txt");
    }
    array_libros_lista = new Producto [tamano_lista];// ............
        if (!archivo) {
            cerr << "no se pudo abrir archivo xd" << endl;
        }
        //cerr << "constructor abrir arc\n";
    /*string line1, line2;
    if (std::getline(archivo, line1)) {
        std::cout << "Line 1: " << line1 << std::endl;
    } else {
        std::cerr << "Error reading line 1." << std::endl;
    }

    // Read the second line
    if (std::getline(archivo, line2)) {
        std::cout << "Line 2: " << line2 << std::endl;
    } else {
        std::cerr << "Error reading line 2." << std::endl;
    }
    */
        string line;
        int num_lineas = count(istreambuf_iterator<char>(archivo), istreambuf_iterator<char>(), '\n');
        
        while (getline(archivo, line)) {
                vector<string> l_valores;
                istringstream iss(line);
                string dato;
                //cerr << "constructor varialbes\n";
            while (getline(iss, dato, ',')) {
                    l_valores.push_back(dato);
            }
            //cerr << "constructor lineas\n";
            if (l_valores.size() == 8) {
                    const char* cod = l_valores[0].c_str();
                    const char* nom = l_valores[1].c_str();
                    const char* descr = l_valores[2].c_str();
                    const char* nivel = l_valores[3].c_str();
                    int grado = stoi(l_valores[4]);
                    const char* area = l_valores[5].c_str();
                    double precio = stod(l_valores[6]);
                    int stock = stoi(l_valores[7]);
                    //cerr << "constructor extraer vlores\n";
                    
                    //cerr << "constructor convertir" << cod << nom << descr<< nivel<< grado<< area<< precio<< stock<< endl;
                    //Producto("123456789122", title, bookType, level, grado, subject, precio, stock);
                    array_libros_lista[contador] = Producto(cod, nom, descr, nivel, grado, area, precio, stock);
                    //cerr << "constructor instanciar bojeto" << contador << "\n";
            } else {
                    cerr << "error en el numero de valores " << line << endl;
            }
                
            contador++;
        }
        //tamano_lista = tamano_l;
    
  
    //cout << num_lineas << endl;
}
    
Listas::~Listas() {
    delete [] array_libros_lista;
}
void Listas::print_lista(){
    cout << tamano_lista << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;

    for (int i = 0; i < tamano_lista; i++){
        cout << left << setw(18) << array_libros_lista[i].codigoISBN
                << left << setw(38) << array_libros_lista[i].nombreLibro
                << left << setw(20) << array_libros_lista[i].descripcionLib 
                << left << setw(15) << array_libros_lista[i].nivel
                << left << setw(12) << array_libros_lista[i].grado
                << left << setw(22) << array_libros_lista[i].area
                << left << setw(12) << array_libros_lista[i].precio
                << left << setw(8) << array_libros_lista[i].stock << endl;
    }
}