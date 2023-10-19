#include <iostream>
#include <string>
using namespace std;


void pantalla_start();
void caratula();
void catalogo();
void pedidos();
void canales_de_venta();

int main(){
    pantalla_start();
	return 0;
} 
 
void pantalla_start(){
    bool repite = true;
	int opcion;
	bool repertirinicio = true;	
	
	do {	
	
		
		system("cls");
		
		
		cout << "\x1B[1;97m" << "\n\t\t\t\t\tSales Management Dashboard - Santillana" << "\x1B[m \n";
		caratula();
		
		cout << "\x1B[33;5;88m" << "\n\t1. Catalogo" << "\x1B[m"<< "\n";
		cout << "\x1B[33;5;88m" << "\n\t2. Pedidos" << "\x1B[m"<< "\n";
		cout << "\x1B[33;5;88m" << "\n\t3. Canales de venta" << "\x1B[m"<< "\n";
		cout << "\x1B[33;5;88m" << "\n\t4. SALIR" << "\x1B[m"<< "\n";
		cout << "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> opcion;
		
		if (std::cin.fail() || (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)) { //comprabacion de erroes
			std::cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		} else {
			switch (opcion){
				case 1:
					system("cls");
					catalogo();
					break;
				   
				case 2:
					system("cls");
					pedidos();
					break;
				case 3:
					system("cls");
					canales_de_venta();
					break;

				case 4:
				   repite = false;
				   break;			
			}
		}
	} while (repite);
	
}
void caratula(){
	string universidad = "UCSP "; 
	string escuela = "Escuela Profesional de Ciencia de la Computacion I"; 
	string curso ="Ciencia de la Computacion I"; 
	string alumnos = "Alumnos: \nIvan Matthias Sardon Medina \nAnthony Huicho Perez";
	string ciudad_año = "Arequipa 2023 - II";
    cout << "\x1B[31;5;88m" << universidad<< "\x1B[m"<< "\n";
	cout << "\x1B[33;5;88m" << escuela << "\x1B[m"<< "\n";
	cout << curso << "\n";
	cout << "\x1B[38;5;46m" << alumnos<< "\x1B[m"<< "\n";
	cout << ciudad_año << "\n"; 
}

void catalogo(){
	bool retro =true;
	int op;
	do{
		cout<<"catalogo";
		cout << "\x1B[33;5;88m" << "\n\t1. Regresar" << "\x1B[m"<< "\n";
		cout << "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (std::cin.fail() || (op != 1) ){
			std::cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		}else{
			switch (op){
				case 1:
					retro = false;
				   break;
				case 2:
					retro= true;
				   break;
			}
		}
		
	
	}while(retro);
	
}

void pedidos(){
	bool retro =true;
	int op;
	do{
		cout<<"pedidos";
		cout << "\x1B[33;5;88m" << "\n\t1. Regresar" << "\x1B[m"<< "\n";
		cout << "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (std::cin.fail() || (op != 1) ){
			std::cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		}else{
			switch (op){
				case 1:
					retro = false;
				   break;
				case 2:
					retro= true;
				   break;
			}
		}

	}while(retro);

}
void canales_de_venta(){
	bool retro =true;
	int op;
	do{
		cout<<"canales de venta ";
		cout << "\x1B[33;5;88m" << "\n\t1. Regresar" << "\x1B[m"<< "\n";
		cout << "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (std::cin.fail() || (op != 1 )){
			std::cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			std::cin.clear();           
			std::cin.ignore(100, '\n');
		}else{
			switch (op){
				case 1:
					retro = false;
				   break;
				case 2:
					retro= true;
				   break;
			}
		}
			
			
	
	}while(retro);
	

	
}


