#include <iostream>
#include <iomanip>
#include <fstream>
#include "c_pedidos.h"
#include "c_producto.h"
#include "c_listas.h"
#include "c_usuario.h"
#include "header1.h"
#include "c_catalogo.h"
#include "c_canales_v.h"

using namespace std;

Catalogo::Catalogo() {
    lista_has = Listas();
    lista_viv = Listas();
    usuario1 = Usuario();
    PedidoPtr = nullptr;
    canalesPtr = nullptr;
}

Catalogo::Catalogo(Listas& lista_has,Listas& lista_viv,Usuario& usuario1) {
    this->lista_has = lista_has;
    this->lista_viv = lista_viv;
    this->usuario1 = usuario1;
    PedidoPtr = nullptr;
    canalesPtr = nullptr;
    productos_anadidos = Listas();
}
void Catalogo::tab_catalogo() {
    bool retro = true;
    int op;
    do {
        system("cls");
        cout << "\x1B[31m"<< "\n\tCatalogo\n"<< "\x1B[m"
             << "\x1B[96m"<< "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m" << "\n"
             << "\x1B[96m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m" << "\n"
             << "\x1B[96m" << "\n\t3. Ir a Pedidos  (No olvides añadir los productos del catalogo)" << "\x1B[m" << "\n"
             << "\x1B[96m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[32m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                system("cls");
                cout << "\x1B[94m" << "\n\tCATALOGO HAS" << "\x1B[m" << "\n\n";
                retro = false;
                print_catalogo(lista_has);
                break;
            case 2:
                system("cls");
                cout << "\x1B[94m" << "\n\tCATALOGO VIVO" << "\x1B[m" << "\n\n";
                retro = false;
                print_catalogo(lista_viv);
                break;
            case 3:
                retro = false;
                PedidoPtr->tab_pedido();
                break;
            case 4:
                retro = false;
                pantalla_start(true, lista_has, lista_viv, usuario1);	
                break;
            default:
                error_valor();
            }
        }
    } while (retro);
    
}
void Catalogo::set_pedidoPtr(Pedido* PedidoPtr) {
    this->PedidoPtr = PedidoPtr;
}
void Catalogo::set_canalesPtr(CanalesV* canalesPtr) {
    this->canalesPtr = canalesPtr;
}

void Catalogo::print_catalogo(Listas& array_catalogo) {
    try {
        array_catalogo.print_lista();
    } catch (const invalid_argument& e) {
        cerr << "Exception while print_lista :c " << e.what() << endl;
    }
    int op;
    double index;
    int op_;
    bool retro = true;
    bool retro1 = true;
    do {
        cout << "\x1B[94m" << "\n\t1. Anadir a Pedido" << "\x1B[m" << "\n"
             <<"\x1B[94m" << "\n\t2. Opciones para Ordenar y Filtrar" << "\x1B[m" << "\n"
             << "\x1B[94m" << "\n\t3. Regresar a Catalogo" << "\x1B[m" << "\n"
             << "\x1B[94m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[94m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                retro = false;
                cout <<"\x1B[32m"<< "\n\nIngrese el indice del producto que desea anadir: "<<"\x1B[m" << endl;
                do {
                    Producto producto_añadir;
                    cout << "\x1B[94m"<< "\n\t0. para volver a catalogo" << "\x1B[m" << "\n";
                    cin >> index;
                    if (cin.fail() || !(index >= 0 && index <= array_catalogo.get_tamano_lista())) {
                        error_valor();
                    } else {
                        if (index == 0) {
                            retro1 = false;
                            system("cls");
                            tab_catalogo();
                        } else {
                            int tipooo = array_catalogo.get_tipo();
                            index--;
                            producto_añadir = array_catalogo.get_elemento(index);
                            productos_anadidos.añadir_elemento(producto_añadir);
                            cout << "Producto anadido :p\n";	//
                            productos_anadidos.print_lista();
                            if (tipooo == 1){//has
                                index += 0.1;
                            }
                            ofstream archivo("../src/Project_0014/data_array.txt", ios::app);
                            if (!archivo) {
                                cerr << "Error al abrir el archivoo" << endl;
                            }
                            archivo<< index << endl;
                            archivo.close();
                            retro1 = true;                           
                        }
                    }
                }while (retro1);
                break;
            case 2:
                retro = false;
                do {
                    system("cls");
                    cout << "\x1B[31m"<< "Filtrar por: " << "\x1B[m"<< endl;
                    cout << "\x1B[94m" << "\n\t1. Descripcion" << "\x1B[m" << "\n"
                        << "\x1B[94m" << "\n\t2. Nivel" << "\x1B[m" << "\n"
                        << "\x1B[94m" << "\n\t3. Grado" << "\x1B[m" << "\n"
                        << "\x1B[94m" << "\n\t4. Area" << "\x1B[m" << "\n"
                        << "\x1B[94m" << "\n\t5. Regresar a Catalogo" << "\x1B[m" << "\n"
                        << "\x1B[94m" << "\n\tEscoger Opcion: " << "\x1B[m";
                    cin >> op_;
                    if (std::cin.fail() || !(op_ >= 1 && op_ <= 5)) {
                        error_valor();
                    } else {
                        switch (op_) {
                        case 5:
                            retro1 = false;
                            system("cls");
                            tab_catalogo();
                            break;
                        default:
                            retro1 = true;
                            filtrar_producto(op_);
                            break;
                        }
                    }
                }while (retro1);
                break;
            case 3:
                retro = false;
                system("cls");
                tab_catalogo();
                break;
            case 4:
                retro = false;
                pantalla_start(true, lista_has, lista_viv, usuario1);	
                break;
            default:
                error_valor();
            }
        }
    } while (retro);
}
void Catalogo::filtrar_producto(int tipo){
    int opcion_interna;
    bool bucle{true};
    const char* c;
    int pos;
    switch (tipo) {
    case 1:
        do {
            cout << "\x1B[31m"<< "\nFiltrar por descripcion:\n"<<"\x1B[m"
                <<"\x1B[94m"<< "1. Pack\n"
                << "2. Libro de Actividades\n"
                << "3. Libro de Texto\n"
                << "4. Regresar\n"<<"\x1B[m";
            cin >> opcion_interna;
            if (std::cin.fail() || !(opcion_interna >= 1 && opcion_interna <= 4)) {
                error_valor();
            } else {
                switch (opcion_interna) {
                case 1:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nPack:\n"<<"\x1B[m";
                    c = "P";
                    pos = 0;
                    break;
                case 2:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nLibro de Actividades:\n"<<"\x1B[m";
                    c = "A";
                    pos = 5;
                    break;
                case 3:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nLibro de Texto:\n"<<"\x1B[m";
                    c = "T";
                    pos = 5;
                    break;
                case 4:
                    bucle = false;
                    break;
                }
                cout  << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
                for (int i = 0; i < lista_has.get_tamano_lista(); i++) {
                    const char* descripcion = lista_has.get_array()[i].getDescripcionLib();
                    if (descripcion[pos] == c[0]) {
                        cout << lista_has.get_array()[i];
                    }
                }
            }
        }while (bucle);
        break;
    case 2:
        do {
            cout << "\x1B[31m"<< "\nFiltrar por nivel:\n"<<"\x1B[m"
                <<"\x1B[94m"<< "1. Primaria\n"
                << "2. Secundaria\n"
                << "3. Regresar\n"<<"\x1B[m";
            cin >> opcion_interna;
            if (std::cin.fail() || !(opcion_interna >= 1 && opcion_interna <= 3)) {
                error_valor();
            } else {
                switch (opcion_interna) {
                case 1:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nPrimaria:\n"<<"\x1B[m";
                    c = "P";
                    pos = 0;
                    break;
                case 2:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nSecundaria:\n"<<"\x1B[m";
                    c = "S";
                    pos = 0;
                    break;
                case 3:
                    bucle = false;
                    break;
                }
                cout  << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
                for (int i = 0; i < lista_has.get_tamano_lista(); i++) {
                    const char* nivel = lista_has.get_array()[i].getNivel();
                    if (nivel[pos] == c[0]) {
                        cout << lista_has.get_array()[i];
                    }
                }
            }
        }while (bucle);
        break;
    case 3:
        do {
            cout << "\x1B[31m"<< "\nFiltrar por grado:\n"<<"\x1B[m"
                <<"\x1B[94m"<< "1er grado\n"
                << "2do grado\n"
                << "3er grado\n"
                << "4to grado\n"
                << "5to grado\n"
                << "6. Regresar\n"<<"\x1B[m";
            cin >> opcion_interna;
            if (std::cin.fail() || !(opcion_interna >= 1 && opcion_interna <= 6)) {
                error_valor();
            } else {
                switch (opcion_interna) {
                case 1:
                    bucle = true;
                    cout << "\x1B[31m"<< "\n1er grado:\n"<<"\x1B[m";
                    pos = 1;
                    break;
                case 2:
                    bucle = true;
                    cout << "\x1B[31m"<< "\n2do grado:\n"<<"\x1B[m";
                    pos = 2;
                    break;
                case 3:
                    bucle = true;
                    cout << "\x1B[31m"<< "\n3er grado:\n"<<"\x1B[m";
                    pos = 3;
                    break;
                case 4:
                    bucle = true;
                    cout << "\x1B[31m"<< "\n4to grado:\n"<<"\x1B[m";
                    pos = 4;
                    break;
                case 5:
                    bucle = true;
                    cout<< "\x1B[31m" << "\n5to grado:\n"<<"\x1B[m";
                    pos = 5;
                    break;
                case 6:
                    bucle = false;
                    break;
                }
                cout  << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
                for (int i = 0; i < lista_has.get_tamano_lista(); i++) {
                    int grado = lista_has.get_array()[i].getGrado();
                    if (grado == pos) {
                         cout << lista_has.get_array()[i];
                    }
                }
            }
        }while (bucle);
        break;
    case 4:
        do {
            cout << "\x1B[31m"<< "\nFiltrar por area:\n"<<"\x1B[m"
                <<"\x1B[94m"<< "1. Matematica\n"
                << "2. Ciencias Naturales\n"
                << "3. Geografia\n"
                << "4. Lenguaje\n"
                << "5. Regresar\n"<<"\x1B[m";
            cin >> opcion_interna;
            if (std::cin.fail() || !(opcion_interna >= 1 && opcion_interna <= 5)) {
                error_valor();
            } else {
                pos = 0;
                switch (opcion_interna) {
                case 1:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nMatematica:\n"<<"\x1B[m";
                    c = "M";
                    break;
                case 2:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nCiencias Naturales:\n"<<"\x1B[m";
                    c = "C";
                    break;
                case 3:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nGeografia:\n"<<"\x1B[m";
                    c = "G";
                    break;
                case 4:
                    bucle = true;
                    cout << "\x1B[31m"<< "\nLenguaje:\n"<<"\x1B[m";
                    c = "L";
                    break;
                case 5:
                    bucle = false;
                    break;
                }
                cout  << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
                for (int i = 0; i < lista_has.get_tamano_lista(); i++) {
                    const char* area = lista_has.get_array()[i].getArea();
                    if (area[pos] == c[0]) {
                        cout << lista_has.get_array()[i];
                    }
                }
            }
        }while (bucle);
        break;
    }
}