#include <iostream>
#include "Fecha.h"
#include "Alumno.h"

using namespace std;

int main()
{
    Fecha f(12,10,2024);
    Alumno alumno;
    
    // alumno.setFechaNacimiento(f); /// envia una copia
    
    alumno.setFechaNacimiento(Fecha(2,3,2024));
    
    cout <<"Alumno fecha nacimiento: " << alumno.getFechaNacimiento().toString() << endl;
    
    Fecha fechaNac = alumno.getFechaNacimiento();
    
    fechaNac.AgregarDias(2);
    
    alumno.setFechaNacimiento(fechaNac);
    
       
    cout <<"Variable fecha: " <<f.toString() << endl;
    cout <<"Alumno fecha nacimiento: " << alumno.getFechaNacimiento().toString() << endl;
    
    
    
    return 0;
}
