#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "header1.h"
#include "c_pedidos.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_canales_v.h"
#include "c_catalogo.h"
using namespace std;

Pedido::Pedido() {
    cerr << "constructor nulo pedidos invocado xd" << endl;
    nombreCole = nullptr;
    direccionCole = nullptr;
    emailCole = nullptr;
    nombreResp = nullptr;
    numTele = 0;
    codigoCole = 0;
    codigoRUC = 0;
    catalogoPtr = nullptr;//
    canalesPtr = nullptr;
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();
    cantidad_tot = 0;
}
Pedido::Pedido(Listas& lista_has,Listas& lista_viv,Usuario& usuario1) {
    cerr << "constructor lleno pedidos invocado xd" << endl;
    nombreCole = nullptr;
    direccionCole = nullptr;
    emailCole = nullptr;
    nombreResp = nullptr;
    numTele = 0;
    codigoCole = 0;
    codigoRUC = 0;
    catalogoPtr = nullptr;
    canalesPtr = nullptr;
    this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
    cantidad_tot = 0;
}


Pedido::~Pedido() {
    cerr << "\nDestructor de pedido invocado";
    delete[] nombreCole;
    delete[] direccionCole;
    delete[] emailCole;
    delete[] nombreResp;
}
void Pedido::tab_pedido() {
	bool retro = true;
	int op;
    limpiar_archivo(2);
	do{
		system("cls");
        int cant = canalesPtr->get_cant_total();
		cout<<"\tPEDIDOS\n" << cant 
			<< "\x1B[94m" << "\n\t1. Crear Nuevo Pedido (Recuerda que debes llenar el carrito )" << "\x1B[m"<< "\n"
            << "\x1B[94m" << "\n\t2. Regresar a Catalogo" << "\x1B[m"<< "\n"
            << "\x1B[94m" << "\n\t3. Ir a Canales de Venta (No olvides rellenar el pedido)" << "\x1B[m"<< "\n"
            << "\x1B[94m" << "\n\t4. Regresar al Menu" << "\x1B[m"<< "\n"
			<< "\x1B[92m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || !(op >= 1 && op <=4)){
			error_valor();
		} else {
            limpiar_archivo(2);  
			ofstream archivo("../src/Project_0014/data_ped.txt", ios::app);
            if (!archivo) {
                cerr << "Error al abrir el archivoo" << endl;
            }
			switch (op){
			case 1:
                system("cls");
                recibir_datos();
                print_pedido();
                add_listas_pedidos(lista_has, lista_viv, productos_anadidos_has, productos_anadidos_viv);
                if (productos_anadidos_viv.get_tamano_lista() != 0){
                    cout << "\nListas de productos anadidos del catalogo Vivo:\n";
                    set_lista_venta(productos_anadidos_viv);
                } else {
                    cout << "\nListas de productos anadidos del catalogo Vivo vacia :(\n";
                }
                if (productos_anadidos_has.get_tamano_lista() != 0){
                    cout << "\nListas de productos anadidos del catalogo HAS:\n";
                    set_lista_venta(productos_anadidos_has);
                } else {
                    cout << "\nListas de productos anadidos del catalogo HAS vacia :(\n";
                }
                do {
                    cout <<"\x1B[92m" << "\n\t1. Confirmar Pedido -> Ir a Canales de Venta" << "\x1B[m" << "\n"
                        << "\x1B[92m" << "\n\t2. Corregir datos ingresados" << "\x1B[m" << "\n"
                        <<"\x1B[96m" << "\n\t3. Corregir Productos anadidos" << "\x1B[m" << "\n"
                        << "\x1B[46m" << "\n\tEscoger Opcion: " << "\x1B[m";
                    cin >> op;
                    if (cin.fail() || !(op >= 1 && op <= 3)) {
                        error_valor();
                    } else {
                        switch (op) {
                        case 1:
                            retro = false;
                            archivo<<nombreCole<<", "<<codigoCole<<", "<<direccionCole<<", "<<emailCole<<", "<<nombreResp<<", "<<numTele<<", "<<codigoRUC<<endl;
                            archivo<<cantidad_tot<<endl;
                            archivo.close();
                            canalesPtr->tab_canales();
                            break;
                        case 2:
                            retro = true;
                            system("cls");
                            cout << "reingresar datos" << endl;
                            recibir_datos();
                            break;
                        case 3:
                            retro = true;
                            system("cls");
                            cout << "reingresar productos" << endl;
                            limpiar_archivo(1);
                            catalogoPtr->tab_catalogo();
                            break;
                        default:
                            error_valor();
                        }
                    }
                } while (retro);
                retro= false;
                break;
            case 2:
                retro= false;
                catalogoPtr->tab_catalogo();
                break;
            case 3:
                canalesPtr->tab_canales();
                retro= false;
                break;
            case 4:
                pantalla_start(true, lista_has, lista_viv, usuario1);
                retro= false;
                break;
            }
		}
	} while(retro);
}
void Pedido::setCatalogo(Catalogo* cat) {
    this->catalogoPtr = cat;
}
void Pedido::setCanales(CanalesV* can) {
    this->canalesPtr = can;
}
void Pedido::setUsuario(Usuario* usu) {
    this->usuarioPtr = usu;
}
void Pedido::setNombreCole(const char* nom_c) {
    if (nom_c != nullptr) {
        if (nombreCole != nullptr) {
            delete[] nombreCole;
        }
        int largo{0};
        while (nom_c[largo] != '\0'){
        largo++;
    }
        nombreCole = new char[largo + 1];
        if (!nombreCole) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            nombreCole[i] = nom_c[i];
        }
        nombreCole[largo] = '\0';
    }
}
const char* Pedido::getNombreCole() const {
    return nombreCole;
}
void Pedido::setDireccionCole(const char* dir_c) {
    if (dir_c != nullptr) {
        if (direccionCole != nullptr) {
            delete[] direccionCole;
        }
        int largo{0};
        while (dir_c[largo] != '\0'){
        largo++;
    }
        direccionCole = new char[largo + 1];
        if (!direccionCole) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            direccionCole[i] = dir_c[i];
        }

        direccionCole[largo] = '\0';
    }
}
const char* Pedido::getDireccionCole() const {
    return direccionCole;
}
void Pedido::setEmailCole(const char* email_c) {
    if (email_c != nullptr) {
        if (emailCole != nullptr) {
            delete[] emailCole;
        }
        int largo{0};
        while (email_c[largo] != '\0'){
        largo++;
    }
        emailCole = new char[largo + 1];
        if (!emailCole) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            emailCole[i] = email_c[i];
        }

        emailCole[largo] = '\0';
    }
}
const char* Pedido::getEmailCole() const {
    return emailCole;
}
void Pedido::setNombreResp(const char* nombre_r) {
    if (nombre_r != nullptr) {
        if (nombreResp != nullptr) {
            delete[] nombreResp;
        }
        int largo{0};
        while (nombre_r[largo] != '\0'){
        largo++;
    }
        nombreResp = new char[largo + 1];
        if (!nombreResp) {
            cerr << "no se pudo asignar memoria xd" << endl;
        }
        for (int i = 0; i < largo; i++) {
            nombreResp[i] = nombre_r[i];
        }

        nombreResp[largo] = '\0';
    }
}
const char* Pedido::getNombreResp() const {
    return nombreResp;
}
void Pedido::setNumTele(int num_tel) {
    numTele = (num_tel >= 0) ? num_tel : numTele;
}
int Pedido::getNumTele() const {
    return numTele;
}
void Pedido::setCodigoCole(long long cod_col) {
    codigoCole = (cod_col >= 0) ? cod_col : codigoCole;
}
long long Pedido::getCodigoCole() const {
    return codigoCole;
}
void Pedido::setCodigoRUC(long long cod_ruc) {
    codigoRUC = (cod_ruc >= 0) ? cod_ruc : codigoRUC;
}
long long Pedido::getCodigoRUC() const {
    return codigoRUC;
}
void Pedido::recibir_datos() {
    cout << "\x1B[34m" << "\nCREAR NUEVO PEDIDO" << "\x1B[m"<< "\n\n";
    do {
        long long codi;
        cout << "\x1B[96m" << "\n\t- Ingrese codigo del colegio:\n"<< "\x1B[m";
        cin >> codi;
        setCodigoCole(codi);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        char nom[50];
        cout << "\x1B[96m" << "\n\t- Ingrese nombre del colegio: \n"<< "\x1B[m";
        cin >> nom;
        setNombreCole(nom);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        char dir[50];
        cout << "\x1B[96m" << "\n\t- Ingrese direccion del colegio:\n"<< "\x1B[m";
        cin >> dir;
        setDireccionCole(dir);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        cout << "\x1B[96m" << "\n\t- Ingrese telefono del colegio:\n"<< "\x1B[m";
        int num_tel;
        cin >> num_tel;
        setNumTele(num_tel);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        char email[50];
        cout << "\x1B[96m" << "\n\t- Ingrese email del colegio:\n"<< "\x1B[m";
        cin >> email;
        setEmailCole(email);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        long long cod_ruc;
        cout << "\x1B[96m" << "\n\t- Ingrese RUC del colegio:\n"<< "\x1B[m";
        cin >> cod_ruc;
        setCodigoRUC(cod_ruc);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        char nom_resp[50];
        cout << "\x1B[96m" << "\n\t- Ingrese nombre del responsable del colegio:\n"<< "\x1B[m";
        cin >> nom_resp;
        setNombreResp(nom_resp);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
}
void Pedido::print_pedido() {
    cout << "\x1B[32m" << "\n\tResumen Pedido: \n\n"<< "\x1B[m"
         << "\x1B[40m" << "Nombre del Colegio: " << "\x1B[m"<< (nombreCole ? nombreCole : "N/A") << endl
         << "\x1B[32m" << "Codigo del Colegio: " << "\x1B[m"<< codigoCole << endl
         << "\x1B[32m" << "Direccion: " << "\x1B[m"<< (direccionCole ? direccionCole : "N/A") << endl
         << "\x1B[32m" << "Email: " << "\x1B[m"<< (emailCole ? emailCole : "N/A") << endl
         << "\x1B[32m" << "Nombre del Responsable: " << "\x1B[m"<< (nombreResp ? nombreResp : "N/A") << endl
         << "\x1B[32m" << "Numero de Telefono: " << "\x1B[m"<< numTele << endl
         << "\x1B[32m" << "Codigo de RUC: " << "\x1B[m"<< codigoRUC << endl;  
}
void Pedido::set_lista_venta(Listas productos_anadidos){
    
    cout << "\t" << left << setw(8) << "Index" << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
    int cantidad;
    const char* nombre;
    float precio;
    ofstream archivo("../src/Project_0014/data_ped.txt", ios::app);
    for (int i = 0; i < productos_anadidos.get_tamano_lista(); i++){
        cout << "\t" << left << setw(8) << i+1 << productos_anadidos.get_array()[i]
             << "Ingrese cantidad:" << endl;
        cin >> cantidad;
        cantidad_tot += cantidad;
        nombre = productos_anadidos.get_array()[i].getNombreLibro();
        precio = productos_anadidos.get_array()[i].getPrecio();
       if (!archivo) {
            cerr << "Error al abrir el archivoo" << endl;
        }
        archivo<< cantidad <<", "<< nombre <<", "<<precio << endl;
    }
    archivo.close();
    
}
int Pedido::get_cantidad_tot() const {
    return cantidad_tot;
}