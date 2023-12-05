#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include "header1.h"
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_canales_v.h"
#include "clase_catalogo.h"
#include "clase_v_producto.h"
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
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();

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
}

/*Pedido::Pedido(const Pedido& copy) {
    cerr << "constructor de copia invocado xd" << endl;
    numTele = copy.numTele;
    codigoCole = copy.codigoCole;
    codigoRUC = copy.codigoRUC;
    // Copy constructor for dynamic memory
    setNombreCole(copy.nombreCole);
    setDireccionCole(copy.direccionCole);
    setEmailCole(copy.emailCole);
    setNombreResp(copy.nombreResp);
}*/

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
	do{
		system("cls");
        int cant = canalesPtr->get_cant_total();
		cout<<"\tPEDIDOS\n" << cant 
			<< "\x1B[33;5;88m" << "\n\t1. Crear Nuevo Pedido (recuerda que debes llenar el carrito xd)" << "\x1B[m"<< "\n"
            << "\x1B[33;5;88m" << "\n\t2. Regresar a Catalogo" << "\x1B[m"<< "\n"
            << "\x1B[33;5;88m" << "\n\t3. Ir a Canales de Venta" << "\x1B[m"<< "\n"
            << "\x1B[33;5;88m" << "\n\t4. Regresar al Menu" << "\x1B[m"<< "\n"
			<< "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || !(op >= 1 && op <=4)){
			error_valor();
		} else {
			ofstream archivo("../src/Project_0013/data_ped.txt", ios::out);
            if (!archivo) {
                cerr << "Error al abrir el archivoo" << endl;
            }
            
			switch (op){
			case 1:
                system("cls");
                recibir_datos();
                print_pedido();
                add_listas_pedidos(lista_has, lista_viv, productos_anadidos_has, productos_anadidos_viv);
                cout << "\nListas de productos anadidos del catalogo Vivo:\n";
                set_lista_venta(productos_anadidos_viv);
                cout << "\nListas de productos anadidos del catalogo Has:\n";
                set_lista_venta(productos_anadidos_has);
                do {
                    cout <<"\x1B[88m" << "\n\t1. Confirmar Pedido -> Ir a Canales de Venta" << "\x1B[m" << "\n"
                        << "\x1B[88m" << "\n\t2. Corregir datos ingresados" << "\x1B[m" << "\n"
                        << "\x1B[88m" << "\n\t3. Corregir Productos anadidos" << "\x1B[m" << "\n"
                        << "\x1B[46m" << "\n\tEscoger Opcion: " << "\x1B[m";
                    cin >> op;
                    if (cin.fail() || !(op >= 1 && op <= 3)) {
                        error_valor();
                    } else {
                        switch (op) {
                        case 1:
                            retro = false;
                            archivo<<nombreCole<<", "<<codigoCole<<", "<<direccionCole<<", "<<emailCole<<", "<<nombreResp<<", "<<numTele<<", "<<codigoRUC<<endl;
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
                            limpiar_archivo();
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
        cout << "\n\t- Ingrese codigo del colegio:\n";
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
        cout << "\n\t- Ingrese nombre del colegio: \n";
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
        cout << "\n\t- Ingrese direccion del colegio:\n";
        cin >> dir;
        setDireccionCole(dir);
        if (cin.fail()) {
            error_valor();
        } else {
            break;
        }
    } while (true);
    do {
        cout << "\n\t- Ingrese telefono del colegio:\n";
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
        cout << "\n\t- Ingrese email del colegio:\n";
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
        cout << "\n\t- Ingrese RUC del colegio:\n";
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
        cout << "\n\t- Ingrese nombre del responsable del colegio:\n";
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
    cout << "\n\tResumen Pedido: \n\n"
         << "Nombre del Colegio: " << (nombreCole ? nombreCole : "N/A") << endl
         << "Codigo del Colegio: " << codigoCole << endl
         << "Direccion: " << (direccionCole ? direccionCole : "N/A") << endl
         << "Email: " << (emailCole ? emailCole : "N/A") << endl
         << "Nombre del Responsable: " << (nombreResp ? nombreResp : "N/A") << endl
         << "Numero de Telefono: " << numTele << endl
         << "Codigo de RUC: " << codigoRUC << endl;  
}
void Pedido::set_lista_venta(Listas productos_anadidos){
    cout << "\t" << left << setw(8) << "Index" << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
    int cantidad;
    const char* nombre;
    float precio;
    ofstream archivo("../src/Project_0013/data_ped.txt", ios::app);
                            
    for (int i = 0; i < productos_anadidos.get_tamano_lista(); i++){
        cout << "\t" << left << setw(8) << i+1 
             << left << setw(18) << productos_anadidos.get_array()[i].getCodigoISBN()
             << left << setw(38) << productos_anadidos.get_array()[i].getNombreLibro()
             << left << setw(20) << productos_anadidos.get_array()[i].getDescripcionLib() 
             << left << setw(15) << productos_anadidos.get_array()[i].getNivel()
             << left << setw(12) << productos_anadidos.get_array()[i].getGrado()
             << left << setw(22) << productos_anadidos.get_array()[i].getArea()
             << left << setw(12) << productos_anadidos.get_array()[i].getPrecio()
             << left << setw(8) << productos_anadidos.get_array()[i].getStock() << endl
             << "Ingrese cantidad:" << endl;
        cin >> cantidad;
        nombre = productos_anadidos.get_array()[i].getNombreLibro();
        precio = productos_anadidos.get_array()[i].getPrecio();
        VentaProducto temp_producto(nombre, precio, cantidad);
        //productos_anadidos.get_array()[i].
        cout << endl << left << setw(20) << temp_producto.getNombreLibro() << setw(10) << temp_producto.get_cantidad() << setw(15) << temp_producto.getPrecio() << setw(15) << temp_producto.get_subtotal() << endl;
        /*canalesPtr->ventaPtr->insertar_producto(temp_producto);
        cerr << "cantidadddd" <<canalesPtr->ventaPtr->getArray_productos()[i].get_cantidad() << endl;
        cerr << "nombreee" << canalesPtr->ventaPtr->getArray_productos()[i].getNombreLibro() << endl;*/
       // canalesPtr->ventaPtr->getArray_productos()[i].set_cantidad(cantidad);
       if (!archivo) {
            cerr << "Error al abrir el archivoo" << endl;
        }
        archivo<< cantidad <<", "<< nombre <<", "<<precio << endl;
    }
    archivo.close();
}