#pragma once
#include "Herramientas.h"

using namespace std;

class Martillo:public Herramienta{
private:
    string _tipoCabeza;
public:
   Martillo();
    Martillo(string tC, float peso, float longitud);

};
