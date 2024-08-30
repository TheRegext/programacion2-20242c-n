#include <iostream>
#include <cstring>
#include "Alumno.h"

using namespace std;

void Alumno::setLegajo(int l)
{
  if(l>=1000)
  {
    legajo=l;
  }
  else
  {
    l=-1;
  }
}

void Alumno::setNombre(const char *n)
{
  strcpy(nombre, n);
}

void Alumno::setApellido(const char *n)
{
  strcpy(apellido, n);
}

int Alumno::getLegajo()
{
  return legajo;
}

const char *Alumno::getNombre()
{
  return nombre;
}

const char  *Alumno::getApellido()
{
  return apellido;
}

bool Alumno::getRegular()
{
  return regular;
}

void Alumno::Cargar()
{
  cout<<"LEGAJO ";
  cin>>legajo;
  cout<<"NOMBRE ";
  cin>>nombre;
  cout<<"APELLIDO ";
  cin>>apellido;

  regular=true;
}

void Alumno::Mostrar()
{
  cout<<"LEGAJO ";
  cout<<legajo<<endl;
  cout<<"NOMBRE ";
  cout<<nombre<<endl;
  cout<<"APELLIDO ";
  cout<<apellido<<endl;

}


void Alumno::setFechaNacimiento(Fecha fechaNacimiento){
  _fechaNacimiento = fechaNacimiento;
}

Fecha Alumno::getFechaNacimiento(){
  return _fechaNacimiento;
}

