#include "Fecha.h"
using namespace std;
/***
  el constructor sin parametros puede asignar directamente los valores
  el constructor con parametros debe llamar a los set para asignar
*/

Fecha::Fecha(){
  setFechaDefault();
}

Fecha::Fecha(int dia, int mes, int anio)
{
  _dia  = dia;
  _mes = mes;
  _anio = anio;
  
  validar();
}

int Fecha::getDia()
{
  return _dia;
}

int Fecha::getMes()
{
  return _mes;
}

int Fecha::getAnio()
{
  return _anio;
}

bool Fecha::esDiaValido(){
  int diasMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  return _dia >= 1 && _dia <= diasMeses[_mes-1];
}

bool Fecha::esMesValido(){
  return _mes >= 1 && _mes <= 12;
}

bool Fecha::esAnioValido(){
  return _anio > 0;
}

void Fecha::setFechaDefault(){
  _dia = 1;
  _mes = 1;
  _anio = 2023;
}

void Fecha::validar()
{
  if(!esMesValido() || !esDiaValido() || !esAnioValido()){
    setFechaDefault();
  }
}

void Fecha::AgregarDias (int dias){
  _dia += dias; // TODO: falta corregir
}

string Fecha::toString(){
  return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}
