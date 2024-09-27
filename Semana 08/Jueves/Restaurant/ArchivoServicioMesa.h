#pragma once
#include <string>
#include "ServicioMesa.h"

class ArchivoServicioMesa{
    private:
        std::string _nombreArchivo;
        
    public:
        ArchivoServicioMesa(std::string nombreArchivo);
        bool Guardar(ServicioMesa servicioMesa);
        bool Guardar(ServicioMesa servicioMesa, int posicion);
        int Buscar(int IDServicioMesa);
        ServicioMesa Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, ServicioMesa *vector);
};