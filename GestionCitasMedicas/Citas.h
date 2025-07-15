#pragma once
#include "Librerias.h" //Se incluye el .h con las librerias necesarias

class Citas { //Inicio de la clase Citas 
private:
	int numCita; //Atributos de la clase Citas
	string cedUsuario;
	string codMedico;
	string fecha;
	string codServicio;
	double costoTotal;
public:

	void addCita(int _numCita, string _cedUsuario, string _codMedico, string _fecha, string _codServicio, double _costoTotal) { //Constructor que recibe por parametros
		this->numCita = _numCita;
		this->cedUsuario = _cedUsuario;
		this->codMedico = _codMedico;
		this->fecha = _fecha;
		this->codServicio = _codServicio;
		this->costoTotal = _costoTotal;
	}

	void getCitas() { //Método para obtener y mostrar los datos de la cita
		cout << "Numero de cita: " << numCita << endl;
		cout << "Cedula usuario: " << cedUsuario << endl;
		cout << "Codigo medico: " << codMedico << endl;
		cout << "Fecha: " << fecha << endl;
		cout << "Codigo servicio: " << codServicio << endl;
		cout << "Costo total: " << costoTotal << endl;
	}

	void setActualizarFechaCitas(string _fecha) { // Método para actualizar la fecha de la cita
		this->fecha = _fecha;
	}

	int const getNumCitas() const { //Métodos para obtener los valores por separado (const no se modifican)
		return numCita;
	}

	string const getCedUsuarios() const {
		return cedUsuario;
	}

	string const getCodMedico() const {
		return codMedico;
	}

	string const getFecha() const {
		return fecha;
	}

	string const getCodServicio() const {
		return codServicio;
	}

	double const getCostoTotal() const {
		return costoTotal;
	}
};