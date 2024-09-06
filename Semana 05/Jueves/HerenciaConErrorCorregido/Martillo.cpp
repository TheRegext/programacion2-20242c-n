#include<iostream>
#include<cstdlib>
#include "Martillo.h"
using namespace std;

Martillo::Martillo(){
   cout << "Creando un martillo vacío" << endl;
}

Martillo::Martillo(string tC, float peso, float longitud):Herramienta(peso, longitud){
   _tipoCabeza=tC;
   cout << "Creando un martillo con tipo de cabeza " << _tipoCabeza << endl;
}

