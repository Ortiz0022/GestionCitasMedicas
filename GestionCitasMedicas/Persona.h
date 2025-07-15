#pragma once
#pragma once
#include "Librerias.h" //Se incluye el .h con las librerias necesarias

class Persona //inicio de clase persona
{
protected:
	string nombre; //variables que hereda a las subclases 
	int telefono;
	string correo;

public:
	Persona(string _nombre, int _telefono, string _correo) { //contructor de la clase persona que recibe por parametros
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->correo = _correo;
	}

	const void getPersona() const { //muestra la informacion de la persona, la palabra const indica que no se modificara
		cout << " Nombre:         " << this->nombre << endl;
		cout << " Telefono:       " << this->telefono << endl;
		cout << " Correo:         " << this->correo << endl;
	}
};