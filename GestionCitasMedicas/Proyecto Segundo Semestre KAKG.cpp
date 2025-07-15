#include "Librerias.h"
#include "ContenedorCitas.h"
#include "ContenedorMedico.h"
#include "ContenedorPaciente.h"
#include "ContenedorServicios.h"

int main() {

    system("color 70"); // Este comando sirve para cambiar el color de fondo y el color de la letra

    int opcion;

    //Se hacen las instancias de los contenedores y de reutilizadas
    ContenedorPaciente contenedorPaciente;
    ContenedorMedico contenedorMedico;
    ContenedorServicios contenedorServicios;
    ContenedorCitas contenedorCitas;
    Reutilizados reutilizar;

    bool salir = false;

    do {
        system("cls");
        cout << "------------------------------------------" << endl;
        cout << "             MENU PRINCIPAL" << endl;
        cout << "------------------------------------------\n" << endl;
        cout << "1. Gestion de servicios." << endl;
        cout << "2. Gestion de medicos." << endl;
        cout << "3. Gestion de pacientes." << endl;
        cout << "4. Agendar cita medica." << endl;
        cout << "\n5. Salir del sistema." << endl;
        cout << "------------------------------------------\n" << endl;
        cout << "Ingrese una opcion valida: ";
       
        while (!(cin >> opcion)) {
            cout << " \n** Debe ingresar solo números. Intente nuevamente. **" << endl;
            cout << "\nSeleccione una opción: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        switch (opcion) {
            case 1: { //Gestion de servicios
                system("cls");
                contenedorServicios.MenuServicio();
                system("pause");
                break;
            }

            case 2: { //Gestion de medicos
                system("cls");
                contenedorMedico.menuMedico();
                system("pause");
                break;
            }

            case 3: { //Gestion de pacientes
                system("cls");
                contenedorPaciente.menuPacientes();
                system("pause");
                break;
            }

            case 4: { //Agendar citas
                system("cls");
                contenedorCitas.MenuCitas();
                system("pause");
                break;
            }

            case 5: { //Salir del programa
                char confirmacion;
                cout << "Esta seguro de salir? (S/N): ";
                cin >> confirmacion;
                if (confirmacion == 'S' || confirmacion == 's') { //Si desea salir, el programa terminara aca
                    salir = true;
                    reutilizar.SalidaDeMenu();
                }
                system("pause");
                break;
            }

            default: {
                reutilizar.FinalizoPrograma();
                system("pause");
                break;
            }
        }// Fin del switch
    } while (!salir); // Volver al menú principal si no se confirma la salida
}