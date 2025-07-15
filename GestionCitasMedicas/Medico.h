#pragma once
#include "Librerias.h"
#include "Persona.h"

class Medico : public Persona
{
private:
	bool disponibilidad;
	string cod;

public:
	Medico(string _nombre, int _telefono, string _correo, string _cod, bool _disponibilidad) : Persona(_nombre, _telefono, _correo) {
		this->cod = _cod;
		this->disponibilidad = _disponibilidad;
	}
	void setActualizarMedico(string _nombre, int _telefono, string _correo, bool _disponibilidad) {
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->correo = _correo;
		this->disponibilidad = _disponibilidad;
	}
	const string getCod() const {
		return this->cod;
	}
	const bool getDisponibilidad() const {
		return this->disponibilidad;
	}
	const void getDatosMedico() const {
		Persona::getPersona();
		string dispo;
		if (disponibilidad == true) {
			dispo = "Si";
		}
		else {
			dispo = "No";
		}
		cout << "Codigo del Medico: " << cod << endl;
		cout << "Disponible: " << dispo;
	}

	const int getTelefono() const {
		return this->telefono;
	}

	const string getNombre() const {
		return this->nombre;
	}

	const string getCorreo() const {
		return this->correo;
	}
};