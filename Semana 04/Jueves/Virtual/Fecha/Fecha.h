#pragma once
#include <string>

class Fecha
{
  public:
    Fecha(int dia, int mes, int anio);
    Fecha();
    
    int getDia();
    int getMes();
    int getAnio();
    
    void AgregarDias (int dias);

    std::string toString();
    
  private:
    int _dia;
    int _mes;
    int _anio;
    
    void validar();
    bool esDiaValido();
    bool esMesValido();
    bool esAnioValido();
    void setFechaDefault();
    
};
