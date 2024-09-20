#include "Producto.h"
#include <cstring>
using namespace std;

Producto::Producto(){
  _codigo = 0;
  _stockActual = 0;
  _stockMinimo = 0;
  _precio = .0f;
  strcpy(_nombre, "SIN NOMBRE");
  _eliminado = false;
}

Producto::Producto(int codigo, int stockActual, int stockMinimo, float precio, string nombre) {
    setCodigo(codigo);
    setStockActual(stockActual);
    setStockMinimo(stockMinimo);
    setPrecio(precio);
    setNombre(nombre);
    _eliminado = false;
}

int Producto::getCodigo() const{
  return _codigo;
}

int Producto::getStockActual() const{
    return _stockActual;
}

int Producto::getStockMinimo() const{
    return _stockMinimo;
}

float Producto::getPrecio() const{
    return _precio;
}

string Producto::getNombre() const{
    return _nombre;
}

bool Producto::getEliminado() const{
  return _eliminado;
}


void Producto::setCodigo(int codigo){
  if(codigo >= 0){
    _codigo = codigo;  
  }
}

void Producto::setStockActual(int stockActual) {
    _stockActual = stockActual;
}

void Producto::setStockMinimo(int stockMinimo) {
    _stockMinimo = stockMinimo;
}

void Producto::setPrecio(float precio) {
    _precio = precio;
}

void Producto::setNombre(string nombre) {
  if(nombre.size() < 100){
    strcpy(_nombre, nombre.c_str());  
  }
}

void Producto::setEliminado(bool eliminado) {
    _eliminado = eliminado;
}
