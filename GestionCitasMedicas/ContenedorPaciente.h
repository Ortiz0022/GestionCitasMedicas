#pragma once
#include "Librerias.h"   //Se incluye el .h con las librebrías necesarias
#include "Paciente.h"    //Incluye el .h de la clase Paciente
#include "Reutilizados.h" //Incluye la clase con mensajes reutilizados

class ContenedorPaciente {  //Inicio clase ContenedorPaciente
private:
	vector <Paciente> listaPacientes;   //Se declara el vector de la clase Paciente

public:
	Reutilizados reutilizar;  //Instancia de la clase Reutilizados

	void addNuevoPaciente(Paciente _paciente) {  //Método para el push.back de los pacientes ingresados
		this->listaPacientes.push_back(_paciente);  //Se envían los datos al vector
	}

	void MostrarListaPacientes() {  //Método para mostrar los pacientes ingresados
		int opcionM;
		if (listaPacientes.empty()) { //Si no se han ingresado pacientes,
			reutilizar.SinInformacion(); // muestra un mensaje de error.
		}
		else { //En caso contrario, muestra un mini menú consultar
			do {
				system("cls");
				cout << "------------------------------------------\n" << endl;
				cout << "             MENU CONSULTAR" << endl;
				cout << "------------------------------------------\n" << endl;
				cout << "1. Mostrar todos los pacientes registrados" << endl;
				cout << "2. Buscar pacientes por fecha de ingreso" << endl;
				cout << "3. Regresar al menu pacientes" << endl;
				cout << "------------------------------------------\n" << endl;
				cout << "Seleccione una opción: ";

				while (!(cin >> opcionM)) {
					cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
					cout << "\nSeleccione una opción: ";
					cin.clear();
					cin.ignore(10000, '\n');
				}

				switch (opcionM) {  //Inicio switch mini menú
				case 1: {      //Inicio case 1
					system("cls");
					cout << "\n            LISTA PACIENTES" << endl;       //Se muestran todos los pacientes ingresados
					cout << "------------------------------------------" << endl;
					for (int i = 0; i < listaPacientes.size(); i++) {  //Recorre el vector
						listaPacientes[i].getDatosPaciente();
						cout << "------------------------------------------" << endl;
					}    //MUESTRA LA CANTIDAD DE PACIENTES INGRESADOS USANDO EL .size()
					cout << "\n *** CANTIDAD TOTAL DE PACIENTES REGISTRADOS: " << listaPacientes.size() << " *** " << endl << endl;
					system("pause");
					break;
				} //Final case 1 mini menú
				case 2: {   //Inicio case 2 mini menú
					string fechaR;
					int contador = 0;
					bool encontrado = false;
					cin.ignore();
					cout << "\nIngrese la fecha de registro que desea consultar (DD/MM/AA): ";
					getline(cin, fechaR);
					system("cls");
					cout << "\n    LISTA PACIENTES " << fechaR << endl;
					cout << "------------------------------------------" << endl;
					for (int i = 0; i < listaPacientes.size(); i++) {  //Recorre el vector
						if (fechaR == listaPacientes[i].getFechaRegistroP()) { //Compara los datos y muestra todos los que coincidan.
							contador++;
							listaPacientes[i].getDatosPaciente();		//Muestra los datos encontrados		
							cout << "------------------------------------------" << endl;
							encontrado = true;
						}
					}
					cout << "\n *** CANTIDAD TOTAL DE PACIENTES ENCONTRADOS: " << contador << " *** " << endl << endl;
					if (!encontrado) {
						reutilizar.DatoInexistente();
					}
					system("pause");
					break;
				} //Fin case 2 menú consultar
				case 3: {   //Case 3 mini menú para regresar al menú anterior
					break;
				} //Fin case 3 mini menú
				default: {   //Inicio default
					reutilizar.Default();
					break;
				} //Final default
				}   // fin del switch
			}  //Fin del do 
			while (opcionM != 3);
		} //Fin del else
	} //Fin del void MostrarListaPacientes

	void ModificarPaciente() {  //Método para modificar un paciente
		bool encontrado = false;
		if (listaPacientes.empty()) {   //Si no se han ingresado pacientes, muestra un error
			reutilizar.SinInformacion();
		}
		else {
			int telefono;
			string correo, apellidoP, fechaRegistroP, nombre, ced;
			string nombreArchivo = "ArchivoPaciente.txt";

			cout << "-----------------------------------------------" << endl;
			cout << "  NO INCLUYA GUIONES. UTILICE UN 0 EN SU LUGAR \n";
			cout << "-----------------------------------------------" << endl;
			cout << "Ingrese el numero de cedula del paciente a modificar: ";
			cin >> ced;
			for (int i = 0; i < listaPacientes.size(); i++) { //Recorre el vector
				if (ced == listaPacientes[i].getCedulaP()) {  //Compara datos  muestra el dato que coincidiera
					cin.ignore();    //Consulta los datos a modificar
					cout << "\n\nIngrese el nombre del paciente: ";
					getline(cin, nombre);
					cout << "\nIngrese los apellidos del paciente: ";
					getline(cin, apellidoP);
					cout << "\nIngrese el numero de telefono del paciente: ";
					while (!(cin >> telefono)) {
						cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
						cout << "\nIngrese el numero de telefono del paciente: ";
						cin.clear();
						cin.ignore(10000, '\n');
					}

					cin.ignore();
					cout << "\nIngrese la direccion de correo del paciente: ";
					getline(cin, correo);
					cout << "\nIngrese la fecha de registro del paciente: ";
					getline(cin, fechaRegistroP);
					listaPacientes[i].setActualizarPaciente(nombre, apellidoP, telefono, correo, fechaRegistroP); //Se guardan en el espacio encontrado con el método de actualizar paciente
					GuardarPacientes(nombreArchivo);   //Guarda datos en el archivo

					//MOSTRAR TODOS LOS DATOS PARA COMPROBAR QUE SE MODIFICARA CORRECTAMENTE
					system("cls");
					cout << "\n\n            LISTA PACIENTES" << endl;
					cout << "------------------------------------------" << endl;
					for (int i = 0; i < listaPacientes.size(); i++) {    //Recorre el vector
						listaPacientes[i].getDatosPaciente();           //Muestra lista de pacientes
						cout << "------------------------------------------" << endl;
					}
					cout << "\n *** COMPRUEBE QUE LOS DATOS SE MODIFICARAN CORRECTAMENTE *** " << endl << endl;
					encontrado = true;
				}
			}
		}
		if (!encontrado) {   //Caso contrario del bool, muestra un error de dato inexistente 
			reutilizar.DatoInexistente();
		}
	}

	string BuscarPaciente(string cedulaPaciente) { //Se utilizara en contenedor de citas, para asegurarse de si existe o no un paciente, o si ya posee una cita
		DescargarPacientes("ArchivoPaciente.txt");
		bool exito = false;
		string respuesta;
		for (int i = 0; i < listaPacientes.size(); i++) {
			if (listaPacientes[i].getCedulaP() == cedulaPaciente) { //En caso de que el paciente si exista se retorna un 1
				exito = true;
			}
		}
		if (!exito) { //Si no, se muestra un mensaje de que el paciente no existe y se retorna un 0
			reutilizar.DatoInexistente();
			return "0";
		}
		else {
			return "1";
		}
	}

	void GuardarPacientes(const string& nombreArchivo) { //Método para guardar los datos en archivo txt
		ofstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			for (int i = 0; i < listaPacientes.size(); i++) {
				archivo << listaPacientes[i].getCedulaP() << "-" << listaPacientes[i].getApellidosP() << "-" << listaPacientes[i].getNombre()
					<< "-" << listaPacientes[i].getTelefono() << "-" << listaPacientes[i].getCorreo()
					<< "-" << listaPacientes[i].getFechaRegistroP() << endl;
			}
			archivo.close();
			reutilizar.DatosAlmacenados();
		}
	}  //Fin del método GuardarPacientes

	void DescargarPacientes(const string& nombreArchivo) {  //Método para descargar datos del archivo txt
			listaPacientes.clear();
			ifstream archivo(nombreArchivo);
			if (archivo.is_open()) {
				string linea;
				while (getline(archivo, linea)) {
					stringstream ss(linea);
					string cedulaP, nombre, telefono, correo, apellidoP, fechaRegistroP;

					getline(ss, cedulaP, '-');

					getline(ss, apellidoP, '-');

					getline(ss, nombre, '-');

					getline(ss, telefono, '-');
					int _telefono = stoi(telefono);

					getline(ss, correo, '-');

					getline(ss, fechaRegistroP, '-');

					Paciente paciente = Paciente(cedulaP, apellidoP, nombre, _telefono, correo, fechaRegistroP);
					addNuevoPaciente(paciente);
				}
				archivo.close();
			}
	}  //Fin del método descargarPacientes

	void setNuevoPaciente()       //Método para agregar pacientes
	{
		bool cedulaEncontrada = false;
		int telefono;
		string cedulaP;
		string correo, apellidoP, fechaRegistroP, nombre;
		string nombreArchivo = "ArchivoPaciente.txt";  //Es necesario declara esta variable aquí para poder guardar los datos
		DescargarPacientes(nombreArchivo);
		//en archivo apenas son ingresados y se puedan mostrar en la lista de pacientes
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "TOME EN CUENTA LAS SIGUIENTES RESTRICCIONES: \n";
		cout << "1. La cedula no puede tener mas de 10 digitos.\n 2. No incluya guiones, use un 0 en su lugar. \n3. Puede ingresar letras si lo requiere." << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "\nIngrese el numero de cedula del paciente: ";
		cin >> cedulaP;

		for (char c : cedulaP) { //Recorre la variable cedulaP, para asegurarse de que no hayan valores negativos
			if (c == '-') {
				reutilizar.NoValidos(); //En caso de encontrar un valor negativo muestra el mensaje anteriormente
				cedulaEncontrada = true; //Se usa para evitar los mensajes dobles
				break;
			}
		}

		for (int i = 0; i < listaPacientes.size(); i++) {  //Se recorre el vector
			if (cedulaP == listaPacientes[i].getCedulaP() && cedulaEncontrada != true) {  //Si al realizar la comprobación se encuentra otra cédula igual,solo se entra a esta comprobacion si no posee valores negativos
				reutilizar.NoValidos();                       //envía un mensaje de error y no permite que se guarde en vector
				cedulaEncontrada = true;
				break;
			}
		}
		if (!cedulaEncontrada) {
			if (cedulaP.length() > 0 && cedulaP.length() <= 10) {  //Comprueba que no se ingresen números negativos o mayores de 10 dígitos
				cin.ignore();
				cout << "\nIngrese el nombre del paciente: ";
				getline(cin, nombre);
				cout << "\nIngrese los apellidos del paciente: ";
				getline(cin, apellidoP);
				cout << "\nIngrese el numero de telefono del paciente: ";
				while (!(cin >> telefono)) {
					cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
					cout << "\nIngrese el numero de telefono del paciente: ";
					cin.clear();
					cin.ignore(10000, '\n');
				}

				cin.ignore();
				cout << "\nIngrese la direccion de correo del paciente: ";
				getline(cin, correo);
				cout << "\nIngrese la fecha de registro del paciente (DD/MM/AA): ";
				getline(cin, fechaRegistroP);

				Paciente paciente = Paciente(cedulaP, apellidoP, nombre, telefono, correo, fechaRegistroP);
				addNuevoPaciente(paciente);           // Se guardan los datos en el método que recibe por parámetro
				GuardarPacientes(nombreArchivo); //Se almacenan los datos en el archivo txt
				system("pause");
				system("cls");
				cout << "\n\n            LISTA PACIENTES" << endl;//Mostrar la lista de pacientes para comprobar que ya se guardó
				cout << "------------------------------------------" << endl;
				for (int i = 0; i < listaPacientes.size(); i++) {         //Recorre el vector
					listaPacientes[i].getDatosPaciente();                 //Muestra todos los pacientes ingresados 
					cout << "------------------------------------------" << endl;
				}
				cout << "\n  COMPRUEBE QUE EL NUEVO PACIENTE SE ANADIERA CORRECTAMENTE   " << endl << endl;
				system("pause");
			}
			else {      //Si no se cumple lo que se pide en el if, envía un mensaje de error y no guarda los datos en vector
				reutilizar.NoValidos();
			}
		}
	}  //Final del método setNuevoPaciente

	void menuPacientes() {    //Método para el mimi menú de gestión de pacientes
		int opcion;
		string correo, apellidoP, fechaRegistroP, cedulaP, nombre;
		string nombreArchivo = "ArchivoPaciente.txt";
		do {
			system("cls");           //Menu gestión de pacientes
			cout << "------------------------------------------" << endl;
			cout << "             MENU PACIENTES" << endl;
			cout << "------------------------------------------\n" << endl;
			cout << "1. Registrar nuevo paciente." << endl;
			cout << "2. Modificar paciente." << endl;
			cout << "3. Consultar todos los datos." << endl;
			cout << "4. Guardar contenedor en archivo." << endl;
			cout << "5. Recuperar datos del archivo." << endl;
			cout << "\n6. Regresar al menú principal." << endl;
			cout << "------------------------------------------\n" << endl;
			cout << "Seleccione una opcion: ";
			while (!(cin >> opcion)) {
				cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
				cout << "\nSeleccione una opción: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}

			switch (opcion) {
			case 1: {   //Case 2 menu paciente
				system("cls");
				setNuevoPaciente();
				break;
			}  //final case 1
			case 2: {   //Case 2 menu paciente
				system("cls");
				ModificarPaciente();
				system("pause");
				break;
			}   //Fin case 2 menu paciente
			case 3: {  //Case 3 menu paciente
				system("cls");
				DescargarPacientes(nombreArchivo);
				MostrarListaPacientes();
				system("pause");
				break;
			}   //Fin case 3 menu paciente
			case 4: {  //Case 4 menu paciente
				system("cls");
				GuardarPacientes(nombreArchivo);
				system("pause");
				break;
			}  //Fin case 4 menu paciente
			case 5: { //Case 5 menu paciente
				system("cls");
				DescargarPacientes(nombreArchivo);
				reutilizar.DatosAlmacenados();
				system("pause");
				break;
			}  //Fin case 5 menu paciente
			case 6: { //Case 6 menu paciente
				reutilizar.SalidaDeMenu();
				break;
			}
			default: {  //default menu paciente
				reutilizar.Default();
				system("pause");
				break;
			}  //Fin default menu paciente
			}//Fn del switch
		}//Fin del do menú pacientes
		while (opcion != 6);
	} //Fin del void menuPaciente
}; //fin de la clase ContenedorPaciente