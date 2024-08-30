#pragma once
#include "Fecha.h"

class Alumno
{
private:
  int legajo;
  char nombre[30], apellido[30];
  bool regular;
  Fecha _fechaNacimiento;

public:
  void Cargar();
  void Mostrar();

  void setLegajo(int l);
  void setNombre(const char *n);
  void setApellido(const char *n);
  int getLegajo();
  const char *getNombre();
  const char  *getApellido();
  bool getRegular();
  
  void setFechaNacimiento(Fecha fechaNacimiento);
  Fecha getFechaNacimiento();

};
