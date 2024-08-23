#include <iostream>
using namespace std;

class Incrementador{
    private:
      int _valorIncremento;
      int _valorActual;
      int _cantidadIncrementos;

    public:
        Incrementador();
        Incrementador(int valorInicial, int valorIncremento);
        ~Incrementador();
        void aumentar();
        int getValorActual() const;
        int getCantidadIncrementos() const;
};

Incrementador::~Incrementador(){
    cout << endl << "QEPD logro " << _cantidadIncrementos << " incrementos" << endl << endl;
}

Incrementador::Incrementador(){
    _valorActual = 0;
    _valorIncremento = 1;
    _cantidadIncrementos = 0;
}

Incrementador::Incrementador(int valorInicial, int valorIncremento){
    _valorActual = valorInicial;
    _valorIncremento = valorIncremento;
    _cantidadIncrementos = 0;
}

/**
@desc Aumenta el valor actual del incrementador a partir del valor de _valorIncremento.
*/
void Incrementador::aumentar(){
    _valorActual += _valorIncremento;
    _cantidadIncrementos++;
}

int Incrementador::getValorActual() const{
    return _valorActual;
}

int Incrementador::getCantidadIncrementos() const{
    return _cantidadIncrementos;
}

/// Funciones globales
void mostrarEstadoIncrementador(const Incrementador &incrementador){
    cout << "Valor del incrementador :" << incrementador.getValorActual() << endl;
    cout << "Cantidad de incrementos :" << incrementador.getCantidadIncrementos() << endl;
}


int main(){
    Incrementador obj(0, 50), obj2(900, 900), obj3;
    obj.aumentar();
    obj.aumentar();
    obj.aumentar();

    mostrarEstadoIncrementador(obj);

    obj2.aumentar();

    mostrarEstadoIncrementador(obj2);

    obj3.aumentar();
    obj3.aumentar();
    obj3.aumentar();
    obj3.aumentar();

    mostrarEstadoIncrementador(obj3);

    return 0;
}
