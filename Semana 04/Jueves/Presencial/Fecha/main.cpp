#include <iostream>
#include <cstring>
#include "Fecha.h"

using namespace std;

int main()
{
    Fecha f;

    cout << f.getDia() << endl;
    cout << f.getMes() << endl;
    cout << f.getAnio() << endl;


    cout << f.toString();

    return 0;
}
