//clase_Usuario.h
#include <iostream>


#ifndef CLASE_USUARIO_H
#define CLASE_USUARIO_H
using namespace std;
class Usuario{
	public:
	char* nombre;
	int edad;
	int DNI;
	char* usuario;
	char* contrasena;
	Usuario();
	Usuario(const char* n,int e,int dni,const char* u,const char* c);
	~Usuario();
	void set_char3(char*& atri, const char *char_para);
	
};
#endif