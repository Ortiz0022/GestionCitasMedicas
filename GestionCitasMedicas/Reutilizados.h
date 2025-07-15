#pragma once
#include "Librerias.h" //Se incluye el .h con las librerias necesarias


class Reutilizados {//Clase Reutilizados contiene mensajes repetitivos para mostrar en pantalla
public:

	void DatosAlmacenados() {//Muestra un mensaje cuando los datos han sido ingresados correctamente
		system("cls");  // Limpia la pantalla
		cout << "\n\n------------------------------------------" << endl;
		cout << "     Datos ingresados correctamente." << endl;
		cout << "------------------------------------------" << endl;
	}


	void DatoInexistente() {//Muestrao un mensaje cuando no se encuentra la información solicitada
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "   No se encontro la informacion solicitada." << endl;
		cout << "-----------------------------------------------" << endl;
	}


	void SalidaDeMenu() {//Muestra un mensaje cuando el usuario ha salido del menú
		system("cls");
		cout << "-----------------------------------------------" << endl;
		cout << "		Usted ha salido del menu" << endl;
		cout << "-----------------------------------------------" << endl;
	}


	void SinInformacion() {//Muestra un mensaje cuando no se han ingresado datos
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "      Aun no se han ingresado datos." << endl;
		cout << "------------------------------------------" << endl;
	}

	void FinalizoPrograma()  //Muestra un mensaje cuando se decida salir del programa
	{
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "        Programa finalizado." << endl;
		cout << "------------------------------------------" << endl;
	}

	void Default() {//Muestra un mensaje cuando se ingresa una opción inválida
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "       Ingrese una opcion valida." << endl;
		cout << "------------------------------------------" << endl;
	}


	void NoValidos() {//Muestra un mensaje cuando se ingresan datos no válidos
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "          Datos no validos" << endl;
		cout << "------------------------------------------" << endl;
	}
};