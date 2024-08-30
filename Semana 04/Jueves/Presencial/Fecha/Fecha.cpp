#include "Fecha.h"
#include <ctime>

Fecha::Fecha(){
    establecerFechaPorDefecto();
}

Fecha::Fecha(int dia, int mes, int anio){

    if (anio <= 0)
    {
        establecerFechaPorDefecto();
        return;
    }

    if (!(mes >= 1 && mes <= 12)){
        establecerFechaPorDefecto();
        return;
    }

    int diasxMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (esBisiesto()){
        diasxMes[1]++;
    }

    if (!(dia >= 1 && dia <= diasxMes[mes-1])){
        establecerFechaPorDefecto();
        return;
    }

    _dia = dia;
    _mes = mes;
    _anio = anio;
}

bool Fecha::esBisiesto(){
    return true;
}

void Fecha::establecerFechaPorDefecto(){
    time_t timestamp = time(0);
    tm *diaactual = localtime(&timestamp);
    _dia = diaactual->tm_mday;
    _mes = diaactual->tm_mon+1;
    _anio = diaactual->tm_year+1900;
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

std::string Fecha::toString(){
    std::string fechaADevolver;
    fechaADevolver = std::to_string(_dia) + "/";
    fechaADevolver += std::to_string(_mes) + "/";
    fechaADevolver += std::to_string(_anio);
    return fechaADevolver;
}
