#include <iostream>
#include <cstring>
#include "Alumno.h"

using namespace std;


void Alumno::setLegajo(int l)
{
    if(l>0)legajo=l;
    else legajo=0;
}

int Alumno::getLegajo()
{
    return legajo;
}

void Alumno::setDni(int d)
{
    dni = d;
}

void Alumno::setNombre(const char *n)
{
    strcpy(nombre,n);
}
void Alumno::setApellido(const char *a)
{
    for(int i=0; i<30; i++)
    {
        apellido[i]=a[i];
    }
}
void Alumno::setCodigoCarrera(int cC)
{
    codigoCarrera=cC;
}
int Alumno::getDni()
{
    return dni;
}
const char *Alumno::getNombre()
{
    return nombre;
}
const char *Alumno::getApellido()
{
    return apellido;
}
int Alumno::getCodigoCarrera()
{
    return codigoCarrera;
}

void Alumno::Cargar()
{
    cout<<"LEGAJO: ";
    cin>>legajo;
    cout<<"DNI: ";
    cin>>dni;
    cout<<"NOMBRE: ";
    cin.ignore();
    cin.getline(nombre,30);
    cout<<"APELLIDO: ";
    cin.getline(apellido,30);
    cout<<"CODIGO CARRERA: ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar()
{
    cout<<"LEGAJO: "<<legajo<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"CODIGO CARRERA: "<<codigoCarrera<<endl;
}


Alumno::Alumno(int l, int d, const char *n, const char *a, int cC)
{
    legajo=l;
    dni=d;
    strcpy(nombre, n);
    strcpy(apellido, a);
    codigoCarrera=cC;
}

Alumno::~Alumno()
{
    cout<<"SOY "<<apellido<<", "<<nombre<<" Y ME MORI :("<<endl;
}
