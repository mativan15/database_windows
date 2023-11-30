//clase_persona.cpp
#include <iostream>
#include "clase_persona.h"
using namespace std;
Persona::Persona(){
	nombre=nullptr;
	edad=0;
	DNI=0;
	usuario=nullptr;
	contrasena=nullptr;
}
Persona::Persona(const char* n,int e,int dni,const char* u,const char* c){
	set_char3(nombre,n);
	edad=e;
	DNI=dni;
	set_char3(contrasena,c);
	set_char3(usuario,u);
	
	
}
Persona::~Persona(){
	cerr << "\nDestructor invocado";
}
void Persona::set_char3(char*& atri, const char *char_para){
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