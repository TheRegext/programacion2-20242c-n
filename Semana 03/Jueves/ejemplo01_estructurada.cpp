#include <iostream>
using namespace std;

int main(){
    const int VALOR_INCREMENTO = 50;
    int incrementador = 0;
    int cant_incrementos = 0;

    cout << incrementador << endl;
    incrementador += VALOR_INCREMENTO;
    cant_incrementos++;

    cout << incrementador << endl;
    incrementador += VALOR_INCREMENTO;
    cant_incrementos++;

    cout << incrementador << endl;
    incrementador += VALOR_INCREMENTO;
    cant_incrementos++;


    cout << "INCREMENTADOR: " << incrementador << endl;
    cout << "CANT INCREMENTOS: " << cant_incrementos << endl;


    return 0;
}
