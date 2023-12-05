#include <iostream>
#include <iomanip>
#include <fstream>
#include "clase_pedidos.h"
#include "clase_producto.h"
#include "clase_listas.h"
#include "clase_usuario.h"
#include "header1.h"
#include "clase_catalogo.h"
#include "clase_canales_v.h"

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
        cout << "\n\tCatalogo\n"
             << "\x1B[34m" << "\n\t1. Ingresar a catalogo 'HAS'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Ingresar a catalogo 'vivo'" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Ir a Pedidos" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (std::cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                system("cls");
                cout << "\x1B[34m" << "\n\tCATALOGO HAS" << "\x1B[m" << "\n\n";
                retro = false;
                print_catalogo(lista_has);
                break;
            case 2:
                system("cls");
                cout << "\x1B[34m" << "\n\tCATALOGO VIVO" << "\x1B[m" << "\n\n";
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
    limpiar_archivo(1);
    do {
        cout << "print cat catalogo\x1B[34m" << "\n\t1. Anadir a Pedido" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t2. Opciones para Ordenar y Filtrar" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t3. Regresar a Catalogo" << "\x1B[m" << "\n"
             << "\x1B[34m" << "\n\t4. Regresar al Menu" << "\x1B[m" << "\n"
             << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
        cin >> op;
        if (cin.fail() || !(op >= 1 && op <= 4)) {
            error_valor();
        } else {
            switch (op) {
            case 1:
                retro = false;
                cout << "\n\nEscoja indice del producto que desea anadir: " << endl;
                do {
                    Producto producto_añadir;
                    cout << "\x1B[34m" << "\n\t0. para volver a catalogo" << "\x1B[m" << "\n";
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
                            ofstream archivo("../src/Project_0013/data_array.txt", ios::app);
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
                system("cls");
                cout << "Filtrar por: " << endl;
                do {
                    cout << "\x1B[34m" << "\n\t1. Descripcion" << "\x1B[m" << "\n"
                        << "\x1B[34m" << "\n\t2. Nivel" << "\x1B[m" << "\n"
                        << "\x1B[34m" << "\n\t3. Grado" << "\x1B[m" << "\n"
                        << "\x1B[34m" << "\n\t4. Area" << "\x1B[m" << "\n"
                        << "\x1B[34m" << "\n\t5. Regresar a Catalogo" << "\x1B[m" << "\n"
                        << "\x1B[37m" << "\n\tEscoger Opcion: " << "\x1B[m";
                    cin >> op_;
                    if (std::cin.fail() || !(op_ >= 1 && op_ <= 5)) {
                        error_valor();
                    } else {
                        switch (op_) {
                        case 1:
                            retro1 = true;
                            cout << "filtrar por descripcion pronto sera implementado xd";
                            filtrar_producto(op_);
                            break;
                        case 2:
                            retro1 = true;
                            cout << "filtrar por Nivel pronto sera implementado xd";
                            break;
                        case 3:
                            retro1 = true;
                            cout << "filtrar por grado pronto sera implementado xd";
                            break;
                        case 4:
                            retro1 = true;
                            cout << "filtrar por area pronto sera implementado xd";
                            break;
                        case 5:
                            retro1 = false;
                            system("cls");
                            tab_catalogo();
                            break;
                        default:
                            error_valor();
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
//Listas *Catalogo::filtrar_producto(int tipo){ -> usando lista dinamica
void Catalogo::filtrar_producto(int tipo){
    //Listas *lista_filtrada = new Listas(); -> usando lista dinamica (pendiente de implementar)
    switch (tipo) {
    case 1:
        cout << "filtrar por descripcion pronto sera implementado xd";
        cout  << endl << left << setw(18) << "ISBN" << left << setw(38) << "Titulo" << left << setw(20) << "Descripcion" << left << setw(15) << "Nivel" << left << setw(12) << "Grado" << left << setw(22) << "Area"   << left << setw(12) << "Precio" << left << setw(8) << "Stock" << endl;
        const char* c = "P";
        for (int i = 0; i < lista_has.get_tamano_lista(); i++) {
            const char* descripcion = lista_has.get_array()[i].getDescripcionLib();
            if (descripcion[0] == c[0]) {
                cout << left << setw(18) << lista_has.get_array()[i].getCodigoISBN()
                     << left << setw(38) << lista_has.get_array()[i].getNombreLibro()
                     << left << setw(20) << lista_has.get_array()[i].getDescripcionLib() 
                     << left << setw(15) << lista_has.get_array()[i].getNivel()
                     << left << setw(12) << lista_has.get_array()[i].getGrado()
                     << left << setw(22) << lista_has.get_array()[i].getArea()
                     << left << setw(12) << lista_has.get_array()[i].getPrecio()
                     << left << setw(8) << lista_has.get_array()[i].getStock() << endl;
            }
            /* Producto *temp_array = new Producto[tamano_lista];
            for (int i = 0; i < tamano_lista; i++) {
                temp_array[i] = array_libros_lista[i];
            }
            delete [] array_libros_lista;
            tamano_lista++;
            array_libros_lista = new Producto[tamano_lista];
            for (int i = 0; i < tamano_lista - 1; i++) {
                array_libros_lista[i] = temp_array[i];
            }
            array_libros_lista[tamano_lista - 1] = Producto(cod, nom, descr, nivel, grado, area, precio, stock);
            delete [] temp_array;*/
                //lista_filtrada->insertar_elemento(lista_has.get_elemento(i));
            }
        
        break;
    }
}