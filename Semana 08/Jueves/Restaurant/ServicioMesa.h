#pragma once
#include "Fecha.h"

class ServicioMesa{
    private:
        int _IDServicioMesa, _IDMozo, _IDPlato, _tiempoPreparacion;
        float _puntajeObtenido, _propina, _importe;
        Fecha _fecha;

    public:
    ServicioMesa();
    ServicioMesa(int IDServicioMesa, int IDMozo, int IDPlato, int tiempoPreparacion, float puntajeObtenido, float propina, float importe, Fecha fecha);

    int getIDServicioMesa();
    int getIDMozo();
    int getIDPlato();
    int getTiempoPreparacion();
    float getPuntajeObtenido();
    float getPropina();
    float getImporte();
    Fecha getFecha();

    void setIDServicioMesa(int IDServicioMesa);
    void setIDMozo(int IDMozo);
    void setIDPlato(int IDPlato);
    void setTiempoPreparacion(int TiempoPreparacion);
    void setPuntajeObtenido(float PuntajeObtenido);
    void setPropina(float Propina);
    void setImporte(float Importe);
    void setFecha(Fecha fecha);

    std::string toCSV();
    
};