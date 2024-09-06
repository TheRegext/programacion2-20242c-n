#include<iostream>
using namespace std;
#include "Herramientas.h"

Herramienta::Herramienta(){
   cout << "Creando una herramienta vacía" << endl;
}

Herramienta::Herramienta(float p, float l)
{
    setPeso(p);
    setLongitud(l);
    _nombre="";
    cout << "Construyendo herramienta con peso " << p << " y longitud " << l << endl;
}

void Herramienta::setPrecio(float precio)
{
    if(precio>0)
    {
        _precio=precio;
    }
}

void Herramienta::setPeso(float p)
{
    if(p>0)
    {
        _peso=p;
    }
}

void Herramienta::setLongitud(float l)
{
    if(l>0)
    {
        _longitud=l;
    }
}

float Herramienta::getPeso()
{
    return _peso;
}

float Herramienta::getLongitud()
{
    return _longitud;
}

void Herramienta::mostrarInformacion()
{
    cout<<"NOMBRE DE LA HERRAMIENTA: "<<endl;
    cout<<"--------------------------" << endl;
    cout<<"PESO    :"<<getPeso()<<endl;
    cout<<"LONGITUD:"<<getLongitud()<<endl;
    cout<<"NOMBRE  :"<<_nombre<<endl;
}
