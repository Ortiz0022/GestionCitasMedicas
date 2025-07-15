# Medical Appointment Management System

This C++ console-based application allows managing patients, doctors, medical services, and appointment scheduling. It was developed as a practical academic project for organizing and handling basic operations of a small medical clinic.

## Key Features

- Registration and management of patients and doctors.
- Scheduling and listing of medical appointments.
- Management of available services.
- Data persistence through plain text files.
- Modular design using object-oriented programming.

## Project Structure

- `Persona.h`: Base class for `Paciente` and `Medico`.
- `Paciente.h`, `Medico.h`: Represent patient and doctor data.
- `Citas.h`: Appointment class with relevant fields.
- `ContenedorPaciente.h`, `ContenedorMedico.h`, `ContenedorCitas.h`, `ContenedorServicios.h`: Handle vectors and file operations for each entity.
- `Archivo*.txt`: Files for storing persistent data.
- `Proyecto Segundo Semestre KAKG.cpp`: Main entry point and menu system.

## Authors

This project was developed collaboratively by:

- **Angélica Ortiz Barrantes**
- **Greilyn Esquivel Salazar**
- **Katheryn Méndez Quirós**
- **Krystel Salazar Chavarría**
  
As part of a C++ programming course focused on object-oriented design.
