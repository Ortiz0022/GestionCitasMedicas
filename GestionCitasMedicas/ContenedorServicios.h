#pragma once
#include "Librerias.h"  //Se incluye el .h con las librerias necesarias
#include "Servicios.h" //Se incluye el .h de la clase Servicios
#include "Reutilizados.h" //Se incluye la clase con mensajes reutilizados

class ContenedorServicios //Inicio de la clase ContenedorServicios
{
private:
	vector <Servicios> listaServicios; //Se declara el vector de la clase Servicios

public:
	Reutilizados reutilizar; //Instancia de la clase Reutilizados

	void AddNuevoServicio(Servicios _servicio) { //Método para agregar un nuevo servicio a la lista
		listaServicios.push_back(_servicio); //Se envian los datos al vector
	} //Fin método AddNuevoServicio

	void ModificarServicios() { //Método para modificar los servicios existentes
		if (listaServicios.empty()) { //Comprobar si la lista de servicios está vacía
			reutilizar.DatoInexistente();
		}
		else {
			string cod;    //Declaracion de variables
			string descripcion, dis;
			float costo;
			bool disponibilidad, exito = true;

		codigo:
			cout << "Ingrese el codigo del servicio a modificar: ";
			cin >> cod;

			while (cod.empty()) {
				cout << "Ingrese la informacion solicitada!\n";
				goto codigo;
			}

			for (int i = 0; i < listaServicios.size(); i++) { //Recorrer la lista de servicios para encontrar el servicio con el código ingresado
				if (listaServicios[i].getCod() == cod) {
					system("cls"); //Limpia pantalla

					cin.ignore();
				descrip:
					cout << "Ingrese la descripcion del servicio: "; //Solicita los datos a modificar
					getline(cin, descripcion);

					while (descripcion.empty()) {
						cout << "Ingrese la informacion solicitada!\n";
						goto descrip;
					}

					cout << "El costo debe de ser mayor a 0!\n";
					cout << "Ingrese el costo del servicio: ";
					cin >> costo;

					while (costo == 0) {
						cout << "Ingrese la informacion solicitada!\n";
						goto codigo;
					}

					while (!(cin >> costo)) {
						cout << " \n** Debe ingresar solo números. \nIntente nuevamente: ";
						cin.clear();
						cin.ignore(10000, '\n');
					}

					if (costo < 0) {
						reutilizar.NoValidos();
					}

					else {
						cout << "Desea cambiar la disponibilidad? (SI/NO): ";
						cin >> dis;

						if (dis == "NO") {
							disponibilidad = true;
						}
						else if (dis == "SI") {
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

						else {
							reutilizar.NoValidos();
							break;
						}

						listaServicios[i].setActualizarServicio(descripcion, costo, disponibilidad); //Se actualizan los datos del servicio en la lista
						GuardarServicios("ArchivoServicio.txt");
						reutilizar.DatosAlmacenados();
						cout << "              Lista de servicios.           " << endl;
						cout << "------------------------------------------" << endl;
						for (int i = 0; i < listaServicios.size(); i++) {
							listaServicios[i].getDatosServicio();
							cout << "\n------------------------------------------" << endl;
							exito = false;
						}
					}
				}
			}
			if (exito) {
				reutilizar.SinInformacion(); //Caso contrario muestra el mensaje de que aun no se han ingresado datos
			}
		}
	}//Fin método ModificarServicios

	double BuscarServicio(string cod) { //Método para buscar un servicio en especifico
		DescargarServicios("ArchivoServicio.txt");
		bool exito = false;
		string respuesta;
		int e = 0;
		for (int i = 0; i < listaServicios.size(); i++) {
			if (listaServicios[i].getCod() == cod && listaServicios[i].getDisponibilidad()==true) { //En caso de que el servicio si exista se retorna un 1
				exito = true;
				e = i;
				return listaServicios[i].getCosto();
			}
		}
		if (!exito && listaServicios[e].getDisponibilidad() == false) { //Si no, se muestra un mensaje de que el servicio no existe y se retorna un 0
			reutilizar.DatoInexistente();
			return 0;
		}
		else {
			reutilizar.NoValidos();
			return 2;
		}
	}

	void getConsultarServicio() { //Método para poder ver toda la lista de servicios
		DescargarServicios("ArchivoServicios.txt");
		int contDispo = 0, contNoDispo = 0;
		if (listaServicios.empty()) { //Verifica si la lista de servicios está vacía
			reutilizar.SinInformacion(); //Si la lista está vacía, muestra de mensaje de que aun no se han ingresado datos
		}
		else { //Si no está vacía, se muestra en pantalla toda la lista de servicios
			system("cls");
			cout << "------------------------------------------" << endl;
			cout << "              Lista de servicios.           " << endl;
			cout << "------------------------------------------" << endl;
			cout << "SERVICIOS DISPONIBLES" << endl;
			cout << "------------------------------------------" << endl; //Se muestra en pantalla los servicios que estan disponibles
			for (int i = 0; i < listaServicios.size(); i++) {
				if (listaServicios[i].getDisponibilidad() == true) {
					listaServicios[i].getDatosServicio();
					cout << "\n------------------------------------------" << endl;
					contDispo += 1; //Cuenta la cantidad de servicios disponibles
				}
			}
			cout << "SERVICIOS NO DISPONIBLES" << endl;
			cout << "------------------------------------------" << endl;//Se muestra en pantalla los servicios que no estan disponibles
			for (int i = 0; i < listaServicios.size(); i++) {
				if (listaServicios[i].getDisponibilidad() == false) {
					listaServicios[i].getDatosServicio();
					cout << "\n------------------------------------------" << endl;
					contNoDispo += 1; //Cuenta la cantidad de servicios no disponibles
				}
			}
			cout << "\n *** CANTIDAD TOTAL DE SERVICIOS ENCONTRADOS: " << listaServicios.size() << " ***" << endl << endl;
			cout << "\n *** SERVICIOS DISPONIBLES: " << contDispo << " ***" << endl << endl;
			cout << "\n *** SERVICIOS NO DISPONIBLES: " << contNoDispo << " ***" << endl << endl;
		}

	}//Fin método getConsultarServicios

	void GuardarServicios(const string& nombreArchivo) { //Método para guardar los datos en archivo txt
		ofstream archivo(nombreArchivo);
		if (archivo.is_open()) { //Verificar si el archivo esta abierto
			for (int i = 0; i < listaServicios.size(); i++) {
				int disponible = 1;
				if (listaServicios[i].getDisponibilidad() == true) {
					disponible = 1;
				}
				else {
					disponible = 0;
				}
				archivo << listaServicios[i].getDescripcion() << "-" << listaServicios[i].getCosto()
					<< "-" << listaServicios[i].getCod() << "-" << disponible << endl;
			}
			archivo.close(); //Cerrar el archivo despues de guardar los datos
		}
	}//Fin método GuardarServicios
	void DescargarServicios(const string& nombreArchivo) { //Método para descargar datos del archivo txt
		listaServicios.clear();
		ifstream archivo(nombreArchivo);
		if (archivo.is_open()) { //Verificar si el archivo esta abierto
			string linea;
			while (getline(archivo, linea)) {
				stringstream ss(linea);
				string cod, descripcion, costo, disponibilidad;

				getline(ss, descripcion, '-');

				getline(ss, costo, '-');
				float _costo = stof(costo);

				getline(ss, cod, '-');

				getline(ss, disponibilidad, '-');
				bool _disponibilidad;

				if (disponibilidad == "1") {
					_disponibilidad = true;
				}
				else {
					_disponibilidad = false;
				}

				Servicios servicio = Servicios(cod, descripcion, _costo, _disponibilidad);
				AddNuevoServicio(servicio);
			}
			archivo.close(); //Cerrar el archivo despues de descargar los datos
		}

	}//Fin método DescargarServicio

	void setNuevoServicio() { //Método para agregar servicios
		string cod, descripcion; //Declaracion de variables
		float costo = 0;
		bool disponibilidad = true;
		bool exito = false;
		string nombreArchivo = "ArchivoServicio.txt";
		DescargarServicios(nombreArchivo);

	codigo:
		system("cls"); //Limpia pantalla
		cout << "TOME EN CUENTA LAS SIGUIENTES RESTRICCIONES: \n"; // Muestra restricciones al usuario
		cout << "1. El codigo no puede tener mas de 10 digitos.\n2. No incluya guiones o numeros negativos.\n3. Puede ingresar letras si lo requiere." << endl;
		cout << "Ingrese el codigo del servicio: "; //Solicita al usuario ingresar el código del servicio
		cin >> cod;


		while (cod.empty()) {
			cout << "Ingrese la informacion solicitada!\n";
			goto codigo;
		}

		for (char c : cod) { //Verifica si el código es negativo y muestra un mensaje de error si es así
			if (c == '-') {
				reutilizar.NoValidos();
				exito = true;
				break;
			}
		}

		for (int i = 0; i < listaServicios.size(); i++) { // Verifica si el código ya existe en la lista de servicios y muestra un mensaje de error si es así
			if (listaServicios[i].getCod() == cod && exito != true) {
				reutilizar.NoValidos();
				system("pause");
				exito = true;
			}
		}
		if (!exito) { //Si no hubo errores, solicita y registra la descripción y costo del servicio.
			if (cod.length() > 0 && cod.length() <= 10) {
				cin.ignore();
			descrip:
				cout << "Ingrese la descripcion del servicio: ";
				getline(cin, descripcion);

				while (descripcion.empty()) {
					cout << "Ingrese la informacion solicitada!\n";
					goto descrip;
				}

			cost:
				cout << "El costo debe de ser mayor a 0!\n";
				cout << "Ingrese el costo del servicio: ";
				cin >> costo;

				while (costo == 0) {
					cout << "Ingrese la informacion solicitada!\n";
					goto cost;
				}

				while (!(cin >> costo)) {
					cout << " \n** Debe ingresar solo números. Intente nuevamente: ";
					cin.clear();
					cin.ignore(10000, '\n');
				}

				if (costo < 0) {
					reutilizar.NoValidos();
				}

				else {
					Servicios servicio = Servicios(cod, descripcion, costo, disponibilidad); //Crea un objeto Servicios y lo agrega a la lista de servicios
					AddNuevoServicio(servicio);
					GuardarServicios(nombreArchivo);

					//Muestra la lista de servicios para comprobar que ya se guardó
					system("cls");
					cout << "\n\n            LISTA SERVICIOS" << endl;
					cout << "------------------------------------------" << endl;

					for (int i = 0; i < listaServicios.size(); i++) {
						listaServicios[i].getDatosServicio();
						cout << "\n------------------------------------------" << endl;
					}
					cout << "\n *** CANTIDAD TOTAL DE SERVICIOS ENCONTRADOS: " << listaServicios.size() << " ***" << endl << endl;
					cout << "\n  COMPRUEBE QUE EL NUEVO SERVICIO SE ANADIERA CORRECTAMENTE   " << endl << endl;
					system("pause");
				}
			}
			else {
				reutilizar.NoValidos();
				system("pause");
			}
		}
	}//Fin método setNuevoServicio 

	void ConsultarEspecifico() {
		string cod;
		bool exito = false;
		cout << "Ingrese el codigo de servicio que desea buscar: ";
		cin >> cod;

		for (int i = 0; i < listaServicios.size(); i++) {
			if (listaServicios[i].getCod() == cod) {
				cout << "Servicio encontrado!" << endl;
				listaServicios[i].getDatosServicio();
				exito = true;
			}
		}
		if (!exito) {
			reutilizar.DatoInexistente();
		}
	}

	void MenuServicio() { //Método para mostrar el menu de servicios
		int opcion; //Declaracion de variables
		string descripcion, correo, dis, cod;
		float costo;
		bool disponibilidad;
		string nombreArchivo = "ArchivoServicio.txt";

		do {
			system("cls");
			cout << "------------------------------------------" << endl; //Menu de opciones
			cout << "             MENU SERVICIOS" << endl;
			cout << "------------------------------------------\n" << endl;
			cout << "1. Registrar un nuevo servicio." << endl;
			cout << "2. Modificar un servicio" << endl;
			cout << "3. Consultar todos los servicios" << endl;
			cout << "4. Guardar contenedor en archivo" << endl;
			cout << "5. Recuperar datos del archivo" << endl;
			cout << "6. Consultar servicio especifico" << endl;
			cout << "\n7. Regresar al menu principal" << endl;
			cout << "------------------------------------------" << endl;

			while (!(cin >> opcion)) {
				cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
				cout << "\nSeleccione una opción: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}

			switch (opcion) {
			case 1: {
				system("cls");
				setNuevoServicio();
				break;
			}
			case 2: {
				system("cls");
				ModificarServicios();
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				DescargarServicios(nombreArchivo);
				getConsultarServicio();
				system("pause");
				break;
			}
			case 4: {
				system("cls");
				GuardarServicios(nombreArchivo);
				reutilizar.DatosAlmacenados(); //Mostrar mensaje de datos almacenados correctamente
				system("pause");
				break;
			}
			case 5: {
				system("cls");
				DescargarServicios(nombreArchivo);
				reutilizar.DatosAlmacenados();//Mostrar mensaje de datos almacenados correctamente
				system("pause");
				break;
			}
			case 6: {
				system("cls");
				DescargarServicios(nombreArchivo);
				ConsultarEspecifico();
				system("pause");
				break;
			}
			case 7: {
				reutilizar.SalidaDeMenu();
				break;
			}
			default: {
				reutilizar.Default();
				break;
			}
			}//Fin switch

		} //Fin do

		while (opcion != 7);
	}//Fin método MenuServicio
};