//clase_pedidos.h
#include <iostream>
#include <iomanip>


using namespace std;
class Pedido {
public:
    char nombreCole[128];
	char direccionCole[64];
	char emailCole[64];
	char nombreResp[64];
	int numTele;
    long long codigoCole;
    long long codigoRUC;
	Pedido();
    Pedido (char *nombreCole, char *direccionCole, char *emailCole, char *nombreResp, int num_tel, long long cod_col, long long cod_ruc);
    Pedido(const Pedido& copy);
    void print_pedido() {
        cout << "\n\tResumen Pedido: \n\n"
			<< "\n\tResumen Pedido: \n\n"
            << "Nombre del Colegio: " << nombreCole << endl
            << "Codigo del Colegio: " << codigoCole << endl
            << "Direccion: " << direccionCole << endl
            << "Email: " << emailCole << endl
            << "Nombre del Responsable: " << nombreResp << endl
            << "Numero de Telefono: " << numTele << endl
            << "Codigo de RUC: " << codigoRUC << endl;
    }
};
