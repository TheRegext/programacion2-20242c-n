#pragma once

#include <string>

class Herramienta {
protected:
    std::string _nombre;
    float _peso;
    float _longitud;

    void setPrecio(float precio);
private:
    float _precio;
public:
    Herramienta();
    Herramienta(float p,float l);
    void setPeso(float p);
    void setLongitud(float l);
    float getPeso();
    float getLongitud();
    void mostrarInformacion();
};
