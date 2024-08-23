#include "Incrementador.h"
/// implementcion de los metodos de las clases
Incrementador::Incrementador(int valorInicial, int valorIncremento){ /// constructor
    _cantidadIncrementos = 0;
    _valorActual = valorInicial;
    _valorIncremento = valorIncremento;
}

void Incrementador::incrementar(){
  _valorActual += _valorIncremento;
  _cantidadIncrementos++;
}

int Incrementador::getValor(){
  return _valorActual;
}

int Incrementador::getCantidadIncrementos(){
  return _cantidadIncrementos;
}
