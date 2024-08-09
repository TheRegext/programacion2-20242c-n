#include <iostream>
using namespace std;

void cargarEdadAlumno(int &edad){
    cout << "Direccion de edad: " << &edad << endl;
    cout << "Edad: ";
    cin >> edad;
}

void cargarEdadAlumno(int *ptrEdad){
    cout << "Direccion de ptrEdad: " << &ptrEdad << endl;
    cout << "Edad: ";
    cin >> *ptrEdad;
}

void mostrarDatosAlumno(int edad){
    cout << "El alumno tiene " << edad << " anios" << endl;
}

void mostrarDatosAlumno(string nombre, int edad){
    cout << nombre << " tiene " << edad << " anios" << endl;
}

int main(){
    int edadAlumno = 20;
    string nombreAlumno = "Franco";

    mostrarDatosAlumno(edadAlumno);
    mostrarDatosAlumno(nombreAlumno, edadAlumno);

//    cout << "Direccion de edad alumno: " << &edadAlumno << endl;
//    cargarEdadAlumno(edadAlumno);
//
//    cout << "La edad del alumno es: " << edadAlumno;


    return 0;
}
