#include "ServicioMesa.h"

ServicioMesa::ServicioMesa(){
    _IDServicioMesa = 0;
    _IDMozo = 0;
    _IDPlato = 0;
    _tiempoPreparacion = 0;
    _puntajeObtenido = 0;
    _propina = 0;
    _importe = 0;
    _fecha = Fecha();
}

ServicioMesa::ServicioMesa(int IDServicioMesa, int IDMozo, int IDPlato, int tiempoPreparacion, float puntajeObtenido, float propina, float importe, Fecha fecha){
    _IDServicioMesa = IDServicioMesa;
    _IDMozo = IDMozo;
    _IDPlato = IDPlato;
    _tiempoPreparacion = tiempoPreparacion;
    _puntajeObtenido = puntajeObtenido;
    _propina = propina;
    _importe = importe;
    _fecha = fecha;
}

int ServicioMesa::getIDServicioMesa(){
    return _IDServicioMesa;
}

int ServicioMesa::getIDMozo(){
    return _IDMozo;
}

int ServicioMesa::getIDPlato(){
    return _IDPlato;
}

int ServicioMesa::getTiempoPreparacion(){
    return _tiempoPreparacion;
}

float ServicioMesa::getPuntajeObtenido(){
    return _puntajeObtenido;
}

float ServicioMesa::getPropina(){
    return _propina;
}

float ServicioMesa::getImporte(){
    return _importe;
}

Fecha ServicioMesa::getFecha(){
    return _fecha;
}

void ServicioMesa::setIDServicioMesa(int IDServicioMesa){
    _IDServicioMesa = IDServicioMesa;
}

void ServicioMesa::setIDMozo(int IDMozo){
    _IDMozo = IDMozo;
}

void ServicioMesa::setIDPlato(int IDPlato){
    _IDPlato = IDPlato;
}

void ServicioMesa::setTiempoPreparacion(int TiempoPreparacion){
    _tiempoPreparacion = TiempoPreparacion;
}

void ServicioMesa::setPuntajeObtenido(float PuntajeObtenido){
    _puntajeObtenido = PuntajeObtenido;
}

void ServicioMesa::setPropina(float Propina){
    _propina = Propina;
}

void ServicioMesa::setImporte(float Importe){
    _importe = Importe;
}

void ServicioMesa::setFecha(Fecha fecha){
    _fecha = fecha;
}

std::string ServicioMesa::toCSV(){

    std::string str = std::to_string(_IDServicioMesa) + "," + std::to_string(_IDMozo) + "," + std::to_string(_IDPlato) + "," + std::to_string(_tiempoPreparacion) + "," + std::to_string(_puntajeObtenido) + "," + std::to_string((int) _propina) + "," + std::to_string((int) _importe) + "," + _fecha.toString();
    return str;
}
