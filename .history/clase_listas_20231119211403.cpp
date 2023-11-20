#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "clase_listas.h"
#include "clase_producto.h"

using namespace std;
Listas::Listas(int tipo) {
    
    array_libros_lista = nullptr;
	//cerr << "constructor pointer\n";
	
	//cerr << "constructor new\n";
    int contador {1};
    
    ifstream archivo;
    if (tipo==1){//has
        //tamano_lista = 45;
        archivo.open("../src/Project_0015/data_has.txt");
    } else {//viv
        //tamano_lista = 80;
        archivo.open("../src/Project_0015/data_viv.txt");
    }
    array_libros_lista = new Producto [contador];// ............
    if (!archivo) {
            cerr << "no se pudo abrir archivo xd" << endl;
    }
        //cerr << "constructor abrir arc\n";
    string line;
        //int num_lineas = std::count(std::istreambuf_iterator<char>(archivo), std::istreambuf_iterator<char>(), '\n');
        
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
        cerr << "constructor extraer vlores\n";
                    
                    //cerr << "constructor convertir" << cod << nom << descr<< nivel<< grado<< area<< precio<< stock<< endl;
                    //Producto("123456789122", title, bookType, level, grado, subject, precio, stock);
                    //array_libros_lista[contador] = 
                    //cerr << "constructor instanciar bojeto" << contador << "\n";
        Producto *temp_array = new Producto[contador];
        for (int i = 0; i < contador; i++) {
            temp_array[i] = array_libros_lista[i];
        }
            delete [] array_libros_lista;
            contador++;
            array_libros_lista = new Producto[contador];
            array_libros_lista[contador - 1] = Producto(cod, nom, descr, nivel, grado, area, precio, stock);
            delete [] temp_array;
        } else {
                    cerr << "error en el numero de valores " << line << endl;
        }
            
            
    }
        //tamano_lista = tamano_l;
    
    /*ifstream archivo(nombre_archivo);
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    cerr << "constructor abrir arc\n";
    string line;
    int num_lineas = std::count(std::istreambuf_iterator<char>(archivo), std::istreambuf_iterator<char>(), '\n');
    
    while (getline(archivo, line)) {
            vector<string> l_valores;
            istringstream iss(line);
            string dato;
            cerr << "constructor varialbes\n";
        while (getline(iss, dato, ',')) {
                l_valores.push_back(dato);
        }
        cerr << "constructor lineas\n";
        if (l_valores.size() == 8) {
                const char* cod = l_valores[0].c_str();
                const char* nom = l_valores[1].c_str();
                const char* descr = l_valores[2].c_str();
                const char* nivel = l_valores[3].c_str();
                int grado = stoi(l_valores[4]);
                const char* area = l_valores[5].c_str();
                double precio = stod(l_valores[6]);
                int stock = stoi(l_valores[7]);
                cerr << "constructor extraer vlores\n";
                char noConst_cod[14];
                char noConst_nom[50];
                char noConst_descr[100];
                char noConst_nivel[20];
                char noConst_area[20];
                sprintf(noConst_cod,cod,'\0');
                sprintf(noConst_nom,nom,'\0');
                sprintf(noConst_descr,descr,'\0');
                sprintf(noConst_nivel,nivel,'\0');
                sprintf(noConst_area,area,'\0');
                cerr << "constructor convertir" << noConst_cod << noConst_nom << noConst_descr<< noConst_nivel<< grado<< noConst_area<< precio<< stock<< endl;
                //Producto("123456789122", title, bookType, level, grado, subject, precio, stock);
                array_libros_lista[contador] = Producto(noConst_cod, noConst_nom, noConst_descr, noConst_nivel, grado, noConst_area, precio, stock);
                cerr << "constructor instanciar bojeto" << contador << "\n";
        } else {
                cerr << "Invalid number of l_valores on a line: " << line << endl;
        }
            
        contador++;
    }
    cout << num_lineas << endl;*/
}
    /*    
    char noConst_cod[14];
    char noConst_nom[50];
	char noConst_descr[100];
	char noConst_nivel[20];
	char noConst_area[20];

	cerr << "constructor chrs";
	sprintf(noConst_cod,"1234567890123",'\0');
	sprintf(noConst_nom,"Matematica - Crecemos J.",'\0');
	sprintf(noConst_descr,"Lib. Act.",'\0');
	sprintf(noConst_nivel,"Primaria",'\0');
	sprintf(noConst_area,"Matematica",'\0');
	cerr << "constructor sprintf";
	array_libros_lista[0] = Producto(noConst_cod, noConst_nom, noConst_descr, noConst_nivel, 4, noConst_area, 25, 63);
	cerr << "constructor array";
        char noConst_cod[14];
        char noConst_nom[50];
        char noConst_descr[100];
        char noConst_nivel[20];
        char noConst_area[20];

        // Llenar los arreglos con datos específicos o generados dinámicamente
        sprintf(noConst_cod, "1234567890123", '\0');
        sprintf(noConst_nom, "Libro %d", i + 1, '\0');  // Nombre dinámico
        sprintf(noConst_descr, "Descripcion %d", i + 1, '\0');  // Descripción dinámica
        sprintf(noConst_nivel, "Nivel %d", i + 1, '\0');  // Nivel dinámico
        sprintf(noConst_area, "area %d", i + 1, '\0');  // Área dinámica
        */
        // Crear el objeto Producto y añadirlo al array
        //array_libros_lista[i] = Producto("1234567890123", noConst_nom, noConst_descr, noConst_nivel, 4, noConst_area, 25, 63);
	
    /*char noConst_cod[14];
    char noConst_nom[50];
	char noConst_descr[100];
	char noConst_nivel[20];
	char noConst_area[20];

	cerr << "constructor chrs";
	sprintf(noConst_cod,"1234567890123",'\0');
	sprintf(noConst_nom,"Matematica - Crecemos J.",'\0');
	sprintf(noConst_descr,"Lib. Act.",'\0');
	sprintf(noConst_nivel,"Primaria",'\0');
	sprintf(noConst_area,"Matematica",'\0');
	cerr << "constructor sprintf";
	array_libros_lista[0] = Producto(noConst_cod, noConst_nom, noConst_descr, noConst_nivel, 4, noConst_area, 25, 63);
	cerr << "constructor array";*/

//Listas::Listas(int tamano_l, char *nombre_archivo) {
    /*tamano_lista = tamano_l;
    int contador {0};
    ifstream archivo(nombre_archivo);
    if (!archivo) {
        cerr << "no se pudo abrir archivo xd" << endl;
    }
    string line;
    while (getline(archivo, line)) {
        vector<string> l_valores;
        istringstream iss(line);
        string dato;
        while (getline(iss, dato, ',')) {
            l_valores.push_back(dato);
        }
        if (l_valores.size() == 8) {
            const char* cod = l_valores[0].c_str();
            const char* nom = l_valores[1].c_str();
            const char* descr = l_valores[2].c_str();
            const char* nivel = l_valores[3].c_str();
            int grado = stoi(l_valores[4]);
            const char* area = l_valores[5].c_str();
            double precio = stod(l_valores[6]);
            int stock = stoi(l_valores[7]);

            char noConst_cod[14];
            char noConst_nom[50];
            char noConst_descr[100];
            char noConst_nivel[20];
            char noConst_area[20];
            sprintf(noConst_cod,cod,'\0');
            sprintf(noConst_nom,nom,'\0');
            sprintf(noConst_descr,descr,'\0');
            sprintf(noConst_nivel,nivel,'\0');
            sprintf(noConst_area,area,'\0');
            //Producto("123456789122", title, bookType, level, grado, subject, precio, stock);
            array_libros_lista[contador] = Producto(noConst_cod, noConst_nom, noConst_descr, noConst_nivel, grado, noConst_area, precio, stock);
        } else {
            cerr << "Invalid number of l_valores on a line: " << line << endl;
        }
        
        contador++;
    }
   
    archivo.close(); 
   */

//}
/*void Listas::insertar_lista(Producto libro) {
    Producto *temp_array = new Producto[tamano_lista];
    for (int i = 0; i < tamano_lista; i++) {
        temp_array[i] = array_libros_lista[i];
    }
    delete [] array_libros_lista;
    array_libros_lista = new Producto[tamano_lista];
    array_libros_lista[tamano_lista - 1] = libro;
    delete [] temp_array;
}*/
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