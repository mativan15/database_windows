//clase_persona.h
#include <iostream>


#ifndef CLASE_PERSONA_H
#define CLASE_PERSONA_H
using namespace std;
class Persona{
	public:
	char* nombre;
	int edad;
	int DNI;
	char* usuario;
	char* contrasena;
	Persona();
	Persona(const char* n,int e,int dni,const char* u,const char* c);
	~Persona();
	void set_char3(char*& atri, const char *char_para);
	
};
#endif