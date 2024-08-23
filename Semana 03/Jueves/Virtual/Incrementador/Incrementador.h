#pragma once
/// declaracion de clase

class Incrementador{
/// Propiedades
private:
  int _valorActual;
  int _valorIncremento;
  int _cantidadIncrementos;
  
public:
///Metodos
/// get se utiliza para obtener el valor de una propiedad
/// set se utiliza para establecer el valor de una propiedad

  Incrementador(int valorInicial, int valorIncremento);
  void incrementar();
  int getValor();
  int getCantidadIncrementos();
};
