#pragma once
#include "Librerias.h"
#include "Medico.h"
#include "Reutilizados.h"

class ContenedorMedico
{
private:
	vector <Medico> listaMedicos;
public:
	Reutilizados reutilizar;

	void addNuevoMedico(Medico _medico) {
		listaMedicos.push_back(_medico);
	}//fin metodo addnuevomedico


	void setNuevoMedico()
	{
		string nombre, correo, cod;
		int telefono = 0;
		bool disponibilidad = true, exito = false;
		string nombreArchivo = "ArchivoMedico.txt";
		DescargarMedicos(nombreArchivo);

	codigo:
		system("cls");
		cout << "La cedula del paciente tiene ciertas restricciones: \n";
		cout << "1-EL CODIGO DE MEDICO NO PUEDE TENER NUMEROS NEGATIVOS.\n2-EL CODIGO DE MEDICO NO PUEDE TENER MAS DE 4 DIGITOS.\nPuede incluir letras si asi lo necesita!\n";
		cout << "Ingrese el codigo del medico: ";
		cin >> cod;

		while (cod.empty()) {
			cout << "Ingrese un valor!\n";
			goto codigo;
		}

		for (char c : cod) { //Recorre la variable cedulaP, para asegurarse de que no hayan valores negativos
			if (c == '-') {
				reutilizar.NoValidos(); //En caso de encontrar un valor negativo muestra el mensaje anteriormente
				exito = true; //Se usa para evitar los mensajes dobles
				break;
			}
		}

		for (int i = 0; i < listaMedicos.size(); i++) {
			if (cod == listaMedicos[i].getCod() && exito != true) {
				reutilizar.NoValidos();
				exito = true;
			}
		} //final for case 1
		if (!exito) {
			if (cod.length() > 0 && cod.length() <= 4) {
				cin.ignore();
			med:
				cout << "Ingrese el nombre del medico: ";
				getline(cin, nombre);

				while (nombre.empty()) {
					cout << "Ingrese un valor!\n";
					goto med;
				}
			tel:
				cout << "Ingrese el numero de telefono del medico ";
				cin >> telefono;

				while (telefono == 0) {
					cout << "Ingrese un valor!\n";
					goto tel;
				}

				cin.ignore();
			cor:
				cout << "Ingrese la direccion de correo del medico: ";
				getline(cin, correo);

				while (correo.empty()) {
					cout << "Ingrese un valor!\n";
					goto cor;
				}

				Medico medico = Medico(nombre, telefono, correo, cod, disponibilidad);
				addNuevoMedico(medico);
				GuardarMedico(nombreArchivo);

				//Mostrar la lista de medicos para comprobar que ya se guardó
				mostrarListaMedicos();
				system("cls");
			}
			else {
				reutilizar.NoValidos();
			}
		}
	}

	void mostrarListaMedicos() {
		DescargarMedicos("ArchivoMEDICO.txt");
		int contDisponibles = 0, contOcupado = 0;
		if (listaMedicos.empty()) {
			reutilizar.SinInformacion();
		}
		else {
			cout << "------------------------------------------" << endl;
			cout << "              Lista de medicos.           " << endl;
			cout << "------------------------------------------" << endl;
			cout << "MEDICOS DISPONIBLES\n";
			cout << "------------------------------------------" << endl;

			for (int i = 0; i < listaMedicos.size(); i++) {
				if (listaMedicos[i].getDisponibilidad() == true && listaMedicos[i].getDisponibilidad() != false) {
					listaMedicos[i].getDatosMedico();
					cout << "\n------------------------------------------" << endl;
					contDisponibles += 1;
				}
			}
			/*if (contDisponibles == 0) {
				reutilizar.SinInformacion();
			}*/

			cout << "MEDICOS OCUPADOS\n";
			cout << "------------------------------------------" << endl;
			for (int i = 0; i < listaMedicos.size(); i++) {
				if (listaMedicos[i].getDisponibilidad() == false && listaMedicos[i].getDisponibilidad() != true) {
					listaMedicos[i].getDatosMedico();
					cout << "\n------------------------------------------" << endl;
					contOcupado += 1;
				}
			}
			if (contOcupado == 0) {
				reutilizar.SinInformacion();
			}

			cout << "\n *** CANTIDAD TOTAL DE MEDICOS ENCONTRADOS: " << listaMedicos.size() << " ***" << endl << endl;
			cout << "\n *** MEDICOS DISPONIBLES: " << contDisponibles << " ***" << endl << endl;
			cout << "\n *** MEDICOS NO DISPONIBLES: " << contOcupado << " ***" << endl << endl;

			cout << endl;
		}
	} //fin metodo mostrarListaMedicos()

	string BuscarMedico(string codMedico) {
		DescargarMedicos("ArchivoMEDICO.txt");
		bool exito = false;
		string respuesta;
		int e = 0;
		for (int i = 0; i < listaMedicos.size(); i++) {
			if (listaMedicos[i].getCod() == codMedico) { //En caso de que el medico si exista
				exito = true;
				e = i;
			}
		}
		if (!exito) { //Si no, se muestra un mensaje de que el medico no existe y se retorna un 0
			if (e == 0) {
				reutilizar.DatoInexistente();
				return "0";
			}
		}
		else if (exito && listaMedicos[e].getDisponibilidad() != false) {
			reutilizar.NoValidos();
			return "2";
		}
	}

	void ModificarMedico() {
		if (listaMedicos.empty()) {
			reutilizar.SinInformacion();
		}
		else {
			string nombre, correo, dis, cod;
			int telefono;
			bool disponibilidad, exito = true;
		codigo:
			cout << "Ingrese el codigo del medico a modificar: ";
			cin >> cod;

			while (cod.empty()) {
				cout << "Ingrese un valor!\n";
				goto codigo;
			}

			for (int i = 0; i < listaMedicos.size(); i++) {
				if (listaMedicos[i].getCod() == cod) {
					system("cls");
					cin.ignore();
				med:
					cout << "Ingrese el nombre del medico: ";
					getline(cin, nombre);

					while (nombre.empty()) {
						cout << "Ingrese un valor!\n";
						goto med;
					}

				tel:
					cout << "Ingrese el numero de telefono del medico ";
					cin >> telefono;

					while (telefono == 0) {
						cout << "Ingrese un valor!\n";
						goto tel;
					}
					cin.ignore();
				cor:
					cout << "Ingrese la direccion de correo del medico: ";
					getline(cin, correo);

					while (correo.empty()) {
						cout << "Ingrese un valor!\n";
						goto cor;
					}

				dispo:
					cout << "Desea cambiar la disponibilidad? (SI/NO): ";
					cin >> dis;

					while (dis.empty()) {
						cout << "Ingrese un valor!\n";
						goto dispo;
					}

					if (dis == "NO") {
						disponibilidad = true;
					}
					else {
						int num;
					men:
						cout << "1-Disponible.\n";
						cout << "2-No disponible.\n";
						cout << "Ingrese un numero valido: ";
						cin >> num;
						if (num == 1) {
							disponibilidad = true;
						}
						else if (num == 2) {
							disponibilidad = false;
						}
						else {
							cout << "No existe esa opcion!\n";
							goto men;
						}
					}

					listaMedicos[i].setActualizarMedico(nombre, telefono, correo, disponibilidad);
					GuardarMedico("ArchivoMEDICO.txt");
					reutilizar.DatosAlmacenados();
					cout << "------------------------------------------" << endl;
					cout << "              Lista de medicos.           " << endl;
					cout << "------------------------------------------" << endl;
					for (int i = 0; i < listaMedicos.size(); i++) {
						listaMedicos[i].getDatosMedico();
						cout << "\n------------------------------------------" << endl;
					}
					exito = true;
				}
			}
			if (!exito) {
				reutilizar.DatoInexistente();
			}
		}
	} //fin metodo ModificarMedico
	void GuardarMedico(const string& nombreArchivo) { //Método para guardar los datos en archivo txt
		ofstream archivo(nombreArchivo);
		if (archivo.is_open()) { //Verificar si el archivo esta abierto
			for (int i = 0; i < listaMedicos.size(); i++) {
				int disponible = 1;
				if (listaMedicos[i].getDisponibilidad() == true) {
					disponible = 1;
				}
				else {
					disponible = 0;
				}
				archivo << listaMedicos[i].getNombre() << "-" << listaMedicos[i].getTelefono()
					<< "-" << listaMedicos[i].getCorreo() << "-" << listaMedicos[i].getCod() << "-" << disponible << endl;
			}
			archivo.close(); //Cerrar el archivo despues de guardar los datos
		}
	}//Fin método GuardarServicios

	void DescargarMedicos(const string& nombreArchivo) { //Descargar los datos guardados del txt
		ifstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			string linea;
			listaMedicos.clear();
			while (getline(archivo, linea)) {
				stringstream ss(linea);
				string nombre, telefono, correo, disponibilidad, cod;

				getline(ss, nombre, '-');

				getline(ss, telefono, '-');
				int _telefono = stoi(telefono);

				getline(ss, correo, '-');

				getline(ss, cod, '-');

				getline(ss, disponibilidad, '-');
				bool _disponibilidad;

				if (disponibilidad == "1") {// Convierte a bool
					_disponibilidad = true;
				}
				else {
					_disponibilidad = false;
				}

				Medico medico = Medico(nombre, _telefono, correo, cod, _disponibilidad);
				addNuevoMedico(medico);
			}
			archivo.close();
		}
	}

	void menuMedico() {
		int opcion;
		string nombre, correo, cod;
		int telefono;
		bool disponibilidad;
		string nombreArchivo = "ArchivoMEDICO.txt";

		do {
			system("cls");
			cout << "------------------------------------------\n" << endl;
			cout << "             MENU MEDICOS" << endl;
			cout << "------------------------------------------\n" << endl;
			cout << " 1. Registrar nuevo medico." << endl;
			cout << "2. Modificar datos de un medico" << endl;
			cout << "3. Consultar todos los datos" << endl;
			cout << "4. Guardar contenedor en archivo" << endl;
			cout << "5. Recuperar datos del archivo" << endl;
			cout << "\n6. Regresar al menu principal" << endl;
			cout << "------------------------------------------\n" << endl;
			cout << "Ingrese una opcion valida: ";
			while (!(cin >> opcion)) {
				cout << "Debe ingresar solo numeros. Intentelo nuevamente." << endl;
				cout << "Ingrese una opcion valida: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}

			switch (opcion) {
			case 1: {
				system("cls");
				setNuevoMedico();
				reutilizar.DatosAlmacenados();
				system("pause");
				break;
			}
			case 2: {
				system("cls");
				ModificarMedico();
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				DescargarMedicos(nombreArchivo);
				mostrarListaMedicos();
				system("pause");
				break;
			}
			case 4: {
				system("cls");
				GuardarMedico(nombreArchivo);
				reutilizar.DatosAlmacenados();
				system("pause");
				break;
			}
			case 5: {
				system("cls");
				DescargarMedicos(nombreArchivo);
				reutilizar.DatosAlmacenados();
				system("pause");
				break;
			}
			case 6: {
				reutilizar.SalidaDeMenu();
				break;
			}
			default: {
				reutilizar.Default();
				system("pause");
				break;
			}
			}//fin switch
		} //fin do
		while (opcion != 6);
	}
};