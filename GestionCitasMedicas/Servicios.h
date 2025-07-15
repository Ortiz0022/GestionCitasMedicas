#pragma once
#include "Librerias.h"

class Servicios
{
private:
    string cod;
    string descripcion;
    float costo;
    bool disponibilidad;

public:
    Servicios(string _cod, string _descripcion, float _costo, bool _disponibilidad)
    {
        this->cod = _cod;
        this->descripcion = _descripcion;
        this->costo = _costo;
        this->disponibilidad = _disponibilidad;
    }

    void setActualizarServicio(string _descripcion, float _costo, bool _disponibilidad)
    {
        this->descripcion = _descripcion;
        this->costo = _costo;
        this->disponibilidad = _disponibilidad;
    }
    const void getDatosServicio() const
    {
        string disponible;
        if (disponibilidad==true) {
            disponible = "Disponible";
        }
        else {
            disponible = "Inhabilitado";
        }
        cout << "Codigo del servicio: " << cod << endl;
        cout << "Descripcion del servicio: " << descripcion << endl;
        cout << "Costo del servicio: " << costo << endl;
        cout << "Disponibilidad del servicio: " << disponible;
    }

    const string getCod() const
    {
        return this->cod;
    }
    const string getDescripcion() const
    {
        return this->descripcion;
    }

    const float getCosto() const
    {
        return this->costo;
    }
    const bool getDisponibilidad() const
    {
        return this->disponibilidad;
    }

};