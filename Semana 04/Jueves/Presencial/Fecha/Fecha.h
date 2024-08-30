#pragma once
#include <string>

class Fecha{
    private:
    int _dia, _mes, _anio;
    void establecerFechaPorDefecto();
    bool esBisiesto();


    public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    std::string toString();
};
