#pragma once
#include "Librerias.h" //Se incluye el .h con las librerias necesarias
#include "Persona.h" //Se incluye el .h de la clase madre persona

class Paciente : public Persona { //Inicio de la subclase Paciente que heredada de la clase madre persona
private:
	string apellidoP;  //Atributos de la suclase Paciente
	string fechaRegistroP;
	string cedulaP;

public:
	Paciente(string _cedulaP, string _apellidoP, string _nombre, int _telefono, string _correo, string _fechaRegistroP) : Persona(_nombre, _telefono, _correo) { //Constructor que recibe por parametros los atributos propios y los que hereda
		this->apellidoP = _apellidoP;
		this->fechaRegistroP = _fechaRegistroP;
		this->cedulaP = _cedulaP;
	}

	void setActualizarPaciente(string _apellidoP, string _nombre, int _telefono, string _correo, string _fechaRegistroP) { //Método para actualizar los datos del paciente
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->correo = _correo;
		this->apellidoP = _apellidoP;
		this->fechaRegistroP = _fechaRegistroP;
	}

	void getDatosPaciente() { //Método para obtener los datos del paciente
		cout << " Cédula:         " <<cedulaP <<endl;
		cout << " Apellidos:      " << this->apellidoP << endl;
		Persona::getPersona(); //Metodo heredado de persona
		cout << " Fecha registro: " << this->fechaRegistroP << endl;

	}

	const string getCedulaP() const { //Métodos para obtener los valores por separado
		return this->cedulaP;
	}

	const string getApellidosP() const {
		return this->apellidoP;
	}

	const string getFechaRegistroP() const {
		return this->fechaRegistroP;
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