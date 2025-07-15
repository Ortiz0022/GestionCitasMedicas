#pragma once
#include "Librerias.h" //Se incluye el .h con las librerias necesarias
#include "Citas.h" //Se incluye el .h de la clase citas
#include "Reutilizados.h" //Se incluye la clase con mensajes reutilizados
#include "ContenedorMedico.h"//Se incluye el .h de la clase ContenedorMedico para hacer los comprobaciones respectivas
#include "ContenedorPaciente.h"//Se incluye el .h de la clase ContenedorPaciente para hacer las comprobaciones respectivss
#include "ContenedorServicios.h"//Se incluye el .h de la clase ContenedorServicios para hacer los calculos respectivos

class ContenedorCitas { //Inicio de la clase ContenedorCitas
private:
	vector <Citas> listacitas; //Se declara el vector de la clase Citas
public:
	Reutilizados reutilizar; //Instancia de la clase Reutilizados

	void addNuevaCita(Citas citas) { //Método para agregar una cita a la lista
		listacitas.push_back(citas);//Se envian los datos al vector
		reutilizar.DatosAlmacenados(); //Se muestra en pantalla un mensaje que los datos han sido almacenados correctamente
	}//Fin metodo AddNuevaCita

	void MostrarListaCitas() { //Inicio del metodo MostrarListaCitas
		DescargarCitas("prestamos.txt"); //Desacargar datos del archivo txt
		int opcionM;
		if (listacitas.empty()) { //Verifica si la lista de citas está vacía
			reutilizar.SinInformacion(); //Se muestra en pantalla un mensaje que no existen datos almacenados
		}
		else {
			do {
				system("cls");
				cout << "------------------------------------------\n" << endl; //Se abre un nuevo menu de opciones que el usuario tendra para poder consultar las citas
				cout << "             MENÚ CONSULTAR" << endl;
				cout << "------------------------------------------\n" << endl;
				cout << "1. Mostrar todas las citas agendadas." << endl;
				cout << "2. Buscar cita por número asignado." << endl;
				cout << "3. Regresar al menú agendar citas." << endl;
				cout << "------------------------------------------\n" << endl;
				cout << "\nSeleccione una opción: ";
				cin >> opcionM;

				switch (opcionM) {
				case 1: {
					system("cls");
					cout << "\n            LISTA CITAS" << endl; //Se muestran las citas agendadas
					cout << "------------------------------------------" << endl;

					for (int i = 0; i < listacitas.size(); i++) {
						listacitas[i].getCitas();
						cout << "------------------------------------------" << endl;
					}
					system("pause");
					break;
				} //Fin caso 1 menu consultar

				case 2: { //Se muestra la cita que se busque por numero especifico
					int numCita;
					bool encontrado = false;

					cout << "\nIngrese el número de cita a consultar: ";
					cin >> numCita;
					system("cls");
					cout << "\n         CITA NÚMERO " << numCita << endl;
					cout << "------------------------------------------" << endl;
					for (int i = 0; i < listacitas.size(); i++) {
						if (numCita == listacitas[i].getNumCitas()) {
							listacitas[i].getCitas();
							cout << "------------------------------------------" << endl;
							encontrado = true;
						}
					}
					if (!encontrado) {
						reutilizar.DatoInexistente();  //Se muestra en pantalla un mensaje que no existen datos almacenados
					}
					system("pause");
					break;
				} //Fin caso 2 menú consultar

				case 3: {
					reutilizar.SalidaDeMenu();
					system("pause");
					break;
				}//Fin caso 3 menú consultar

				default: { //Se muestra un mensaje de error si se digita una opcion invalida
					reutilizar.Default();
					system("pause");
					break;
				}
				}
			} while (opcionM != 3);
		}
	}//Fin metodo MostrarListaCitas

	void getModificarCitas() { //Inicio del metodo getModificarCitas
		DescargarCitas("prestamos.txt");
		int numCitas; //Declaracion de variables
		string fecha;
		bool citaEncontrada = false;

		if (listacitas.empty()) //Comprobar si la lista de citas está vacía
		{
			reutilizar.SinInformacion();
		}
		else
		{
			cout << "\nIngrese el numero de cita que desea modificar: ";
			cin >> numCitas;

			for (int i = 0; i < listacitas.size(); i++) { //Recorrer la lista de citas para encontrar la cita con el numero ingresado
				if (listacitas[i].getNumCitas() == numCitas) {
					system("cls"); //Limpia pantalla
					cout << "\nIngrese la fecha actualizada (DD/MM/AA): ";

					while (!(cin >> fecha)) {
						cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
						cout << "\nSeleccione una opción: ";
						cin.clear();
						cin.ignore(10000, '\n');
					}

					listacitas[i].setActualizarFechaCitas(fecha); //Se actualiza la fecha de la cita en la lista
					citaEncontrada = true;
					reutilizar.DatosAlmacenados();
				}
			}
		}
		if (!citaEncontrada)
		{
			reutilizar.DatoInexistente(); //Caso contrario muestra el mensaje de que aun no se han ingresado datos
		}
	}

	void GuardarCitas(const string& txt) { //Método para guardar los datos en archivo txt
		ofstream archivo(txt.c_str());
		if (archivo.is_open()) { //Verificar si el archivo esta abierto
			for (int i = 0; i < listacitas.size(); i++) {
				archivo << listacitas[i].getNumCitas() << "-" << listacitas[i].getCedUsuarios() << "-" << listacitas[i].getCodMedico() << "-"
					<< listacitas[i].getFecha() << "-" << listacitas[i].getCostoTotal() << endl;
			}
			archivo.close(); //Cerrar el archivo despues de guardar los datos
			reutilizar.DatosAlmacenados();
		}
	}//Fin método GuardarServicios

	void DescargarCitas(const string& txt) { //Método para descargar datos del archivo txt
		ifstream archivo(txt);
		if (archivo.is_open()) { //Verificar si el archivo esta abierto
			string linea;
			while (getline(archivo, linea)) {
				stringstream ss(linea);
				string numCitaStr, cedUsuario, codMedico, fecha, codServicio, costoTotalStr;

				getline(ss, numCitaStr, '-');
				int _numCitas = stoi(numCitaStr);

				getline(ss, cedUsuario, '-');

				getline(ss, codMedico, '-');
				double _codMedico = stod(codMedico);

				getline(ss, fecha, '-');

				getline(ss, codServicio, '-');

				getline(ss, costoTotalStr, '-');
				double _costoTotal = stod(costoTotalStr);

				Citas citas;
				citas.addCita(_numCitas, cedUsuario, codMedico, fecha, codServicio, _costoTotal);
			}
			archivo.close(); //Cerrar el archivo despues de descargar los datos
			reutilizar.DatosAlmacenados();
		}
	} //Fin método DescargarCitas

	void MenuCitas() { //Método para mostrar el menu de citas
		int numCita = 1;
		int opcion = 0;
		string txt = "ArchivoCitas.txt";

		do {
			system("cls");
			cout << "------------------------------------------\n" << endl; //Menu de opciones
			cout << "             MENÚ CITAS" << endl;
			cout << "------------------------------------------\n" << endl;
			cout << "1. Registrar una nueva cita." << endl;
			cout << "2. Modificar una cita." << endl;
			cout << "3. Consultar todos los datos." << endl;
			cout << "4. Guardar contenedor en archivo." << endl;
			cout << "5. Recuperar datos del archivo." << endl;
			cout << "\n6. Regresar al menú principal." << endl;
			cout << "------------------------------------------\n" << endl;
			
			while (!(cin >> opcion)) {
				cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
				cout << "\nSeleccione una opción: ";
				cin.clear();
				cin.ignore(10000, '\n');
			}

			switch (opcion) {
			case 1: {//Registro de citas medicas
				system("cls");

				string cedUsuario, codMedico, fecha, codServicio;
				string ComprobacionPaciente, respuesta, ComprobacionMedico;
				double costoTotal = 0, ComprobacionServicio;
				DescargarCitas(txt);

			paciente:
				system("cls");
				ContenedorPaciente pacientes;
				cout << "NO SE PERMITEN A LOS PACIENTES AGENDAR \nDOS CITAS EL MISMO DIA!\n\n\n"; //MENSAJE DE RESTRICCION
				cout << "Ingrese la cedula del paciente: ";
				cin >> cedUsuario;
				bool exito = true;

				//Instancias que se utilizaran para comprobar la existencia de servicios, medicos, pacientes y citas agregadas
				
				ComprobacionPaciente = pacientes.BuscarPaciente(cedUsuario);
				ContenedorServicios servicios;
				ContenedorMedico medicos;

				if (ComprobacionPaciente == "0") {
				pac:
					cout << "Desea registrar el paciente? (SI/NO): ";
					cin >> respuesta;
					if (respuesta == "SI") {
						pacientes.setNuevoPaciente();
						goto paciente;
					}
					else if (respuesta == "NO") {
						exito = false;
					}
					else {
						reutilizar.NoValidos();
						goto pac;
					}
				}
				else if (ComprobacionPaciente == " 1") {
					exito = true;
				}

				if (exito) {
					cout << "Ingrese la fecha en la que desea agendar la cita (DD/MM/AA): ";
					
					while (!(cin >> fecha)) {
						cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
						cout << "\nSeleccione una opción: ";
						cin.clear();
						cin.ignore(10000, '\n');
					}

					for (int i = 0; i < listacitas.size(); i++) {
						if (listacitas[i].getFecha() == fecha && listacitas[i].getCedUsuarios() == cedUsuario) {
							reutilizar.NoValidos();
							cout << "Ya posee una cita en esa fecha!\n";
							exito = false;
						}
					}

					if (exito) {
					servicio:
						system("cls");
						servicios.getConsultarServicio();
						cout << "Ingrese el codigo del servicio que desea solicitar: ";
						cin >> codServicio;
						ComprobacionServicio = servicios.BuscarServicio(codServicio);
						exito = true;

						if (ComprobacionServicio == 0) {
						ser:
							cout << "Desea registrar el servicio? (SI/NO): ";
							cin >> respuesta;
							if (respuesta == "SI") {
								servicios.setNuevoServicio();
								goto servicio;
							}
							else if (respuesta == "NO") {
								exito = false;
							}
							else {
								reutilizar.NoValidos();
								goto ser;
							}
						}

						else if (ComprobacionServicio == 2) {
						ser2:
							cout << "El servicio no esta disponible! Desea ingresar otro? (SI/NO): " << endl;
							cin >> respuesta;
							if (respuesta == "SI") {
								servicios.getConsultarServicio();
								goto servicio;
							}
							else if (respuesta == "NO") {
								exito = false;
							}
							else {
								reutilizar.NoValidos();
								goto ser2;
							}
						}

						if (exito) {
							costoTotal = ComprobacionServicio;
						medico:
							medicos.mostrarListaMedicos();
							cout << "Ingrese el codigo de medico que atendera al paciente: ";
							cin >> codMedico;
							ComprobacionMedico = medicos.BuscarMedico(codMedico);
							exito = true;

							if (ComprobacionMedico == "0") {
							med:
								cout << "Desea registrar el medico? (SI/NO): ";
								cin >> respuesta;
								if (respuesta == "SI") {
									medicos.setNuevoMedico();
									goto medico;
								}
								else if (respuesta == "NO") {
									exito = false;
								}
								else {
									reutilizar.NoValidos();
									goto med;
								}
							}

							else if (ComprobacionMedico == "2") {
							med2:
								cout << "El medico no esta disponible! Desea ingresar otro? (SI/NO): " << endl;
								cin >> respuesta;
								if (respuesta == "SI") {
									medicos.mostrarListaMedicos(); //Cambiar por el metodo que se va a crear para mostrar unicamente los medicos que ya estan registrados
									goto medico;
								}
								else if (respuesta == "NO") {
									exito = false;
								}
								else {
									reutilizar.NoValidos();
									goto med2;
								}
							}

							if (exito) {
								double impuestoDos, impuestoDiez;
								impuestoDiez = costoTotal * 0, 10; //Se calcula el impuesto de 10%, por gastos administrativos 
								impuestoDos = costoTotal * 0, 02;  //Se calcula el impuesto de 2% por gastos de servicios
								costoTotal += impuestoDos + impuestoDiez;

								for (int i = 0; i < listacitas.size(); i++) {
									if (numCita == listacitas[i].getNumCitas()) {
										numCita += 1;
									}
								}

								Citas citas;
								citas.addCita(numCita, cedUsuario, codMedico, fecha, codServicio, costoTotal);
								addNuevaCita(citas);
								GuardarCitas(txt);
								system("pause");
								system("cls");
								cout << "\n            LISTA CITAS" << endl; //Se muestra la lista de citas para comprobar que se almaceno
								cout << "------------------------------------------" << endl;

								for (int i = 0; i < listacitas.size(); i++) {
									listacitas[i].getCitas();
									cout << "------------------------------------------" << endl;
								}
								cout << "\n  COMPRUEBE QUE LA NUEVA CITA SE AÑADIERA CORRECTAMENTE   " << endl << endl;
							}
						}
					}
				}
				system("pause");
				break;
			}
			case 2: { //Modificar una cita
				system("cls");
				getModificarCitas();
				system("pause");
				break;
			}
			case 3: { //Consultar las citas ingresadas
				system("cls");
				MostrarListaCitas();
				system("pause");
				break;
			}
			case 4: { //Guardar las citas en el archivo txt
				system("cls");
				GuardarCitas(txt);
				system("pause");
				break;
			}
			case 5: { //Descargar las citas almacenadas en el archivo txt
				system("cls");
				DescargarCitas(txt);
				system("pause");
				break;
			}
			case 6: { // Regresar al menu principal
				system("cls");
				reutilizar.SalidaDeMenu();
				break;
			}
			default: {
				system("cls");
				reutilizar.Default();
				system("pause");
				break;
			}
			}
		} while (opcion != 6);
	}

};