#include <iostream>
#include <cmath>
#include <string>

using namespace std;
void imprimir_tri (float var1, float var2, float col, int multiplo);
void caratula(){
	string universidad = "Universidad Catolica San PablOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo "; 
	string escuela = "Escuela Profesional de Ciencia de la Computacion I"; 
	string curso ="Curso de Ciencia de la Computacion I"; 
	string alumnos = "Alumnos: \nIvan Matthias Sardon Medina \nAnthony Huicho";
	string ciudad_año = "Arequipa 2023 - II";
	system("cls"); 
	cout << "\x1B[H" << "\x1B[3;34m" << "//" << endl << "\x1B[m";
    cout << "\x1B[31;5;88m" << universidad<< "\x1B[m"<< "\n";
	cout << "\x1B[33;5;88m" << escuela << "\x1B[m"<< "\n";
	cout << curso << "\n";
	cout << "\x1B[38;5;46m" << alumnos<< "\x1B[m"<< "\n";
	cout << ciudad_año << "\n";
	cout << "\x1B[3;34m"<< "//" << endl << "\x1B[m";  
}

int main(){
    bool bucle{true}; 
	int res{ };
	int num{ };
	char rep{ };
	caratula();
	do {
		bucle=true;
		int multiplo{0};
		cout << "\nBienvenido\nIngrese un numero del 1 al 100:\n";
		cin >> num;
		if (cin.fail() || !(num>0 && num<=100)){
			cout << "\nEl valor ingresado no es valido, intente de nuevo\n ";
			cin.clear();           
			cin.ignore(100, '\n');
			continue;
		} else {
			for (int i=3 ; i<8 ; i++){
				res = num%i;
				if (res==0){
					multiplo = i;
					cout << "\nEl numero " << num << " es multiplo de " << i << "\n";
					break;
				}
			}
			if (multiplo == 0){
				cout << "\nEl numero " << num << " no es multiplo de un cateto, intente con otro numero\n";
				continue;
			} else {
				float var1,var2{};
				switch (multiplo){
					case 3:
					imprimir_tri (var1, var2, 4.0, multiplo);
					break;
					case 4:
					imprimir_tri (var1, var2, 3.0, multiplo);
					break;
					case 5:
					imprimir_tri (var1, var2, 6.0, multiplo);
					break;
					case 7:
					imprimir_tri (var1, var2, 24.0, multiplo);
					break;
				}
			}
			cout << "\n\nIngrese 'q' para detener, otra tecla para repetir: \n"; 
			cin >> rep;
			if (rep=='q' || rep =='Q'){
				bucle=false;
			}
		}
	} while (bucle); 
	cout << "\nFin del programa";
	
	return 0;
}

void imprimir_tri (float var1, float var2, float col, int multiplo){
	var1 = col/multiplo;//relacion de incremento
	var2= var1;
	for(int i = 1; i< multiplo+1; i++){
		var2 = round(var1*i);
		cout << "\n";//nueva fila
		for(int j = 0; j < var2; j++){//nueva columna
			cout << " @";
		}
	}
}


