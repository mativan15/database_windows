//clase_usuario.cpp
#include <iostream>
#include "clase_usuario.h"
using namespace std;
Usuario::Usuario(){
	nombre=nullptr;
	edad=0;
	DNI=0;
	usuario=nullptr;
	contrasena=nullptr;
}
Usuario::Usuario(const char* n,int e,int dni,const char* u,const char* c){
	set_char3(nombre,n);
	edad=e;
	DNI=dni;
	set_char3(contrasena,c);
	set_char3(usuario,u);
	
	
}
Usuario::~Usuario(){
	cerr << "\nDestructor invocado";
}
void Usuario::set_char3(char*& atri, const char *char_para){
	int largo{0};
    while (char_para[largo] != '\0'){
        largo++;
    }
    cerr << largo << endl;
    atri = new char[largo + 1];
    if (!atri) {
        cerr << "no se pudo asignar memoria xd" << endl;
    }
    for (int i = 0; i < largo; i++) {
        atri[i] = char_para[i];
    }
}