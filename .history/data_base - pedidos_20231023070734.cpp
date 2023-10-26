#include <iostream>
#include <iomanip>
#include <string>
#include "wa.h"

using namespace std;


void pedidos(){
	bool retro =true;
	int op;
	do{
		cout<<"pedidos";
		cout << "\x1B[33;5;88m" << "\n\t1. Regresar" << "\x1B[m"<< "\n";
		cout << "\x1B[38;5;46m" << "\n\tEscoger Opcion: " << "\x1B[m";
		cin >> op;
		if (cin.fail() || (op != 1) ){
			cout << "\nValor incorrecto!!! Ingrese una opcion valida:\n"; 
			cin.clear();           
			cin.ignore(100, '\n');
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


