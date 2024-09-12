#include "Producto.h"
#include <cstring>

Producto::Producto(){
    setCodigo(0);
    setStockActual(0);
    setStockMinimo(0);
    setPrecio(0);
    setNombre("Producto sin nombre");
}

Producto::Producto(int codigo, int stockActual, int stockMinimo, float precio, std::string nombre) {
    setCodigo(codigo);
    setStockActual(stockActual);
    setStockMinimo(stockMinimo);
    setPrecio(precio);
    setNombre(nombre);
}

int Producto::getStockActual() {
    return _stockActual;
}

int Producto::getStockMinimo() {
    return _stockMinimo;
}

float Producto::getPrecio() {
    return _precio;
}

int Producto::getCodigo(){
    return _codigo;
}

std::string Producto::getNombre() {
    return _nombre;
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

void Producto::setNombre(std::string nombre) {
    strcpy(_nombre, nombre.c_str());
}

void Producto::setCodigo(int codigo){
    _codigo = codigo;
}

bool Producto::getNecesitaReposicion(){
    if (_stockActual < _stockMinimo){
        return true;
    }
    return false;
}

std::string Producto::toString(){

    //std::string nombreAux = _nombre;
    std::string linea = "Codigo: " + std::to_string(_codigo);
    linea += " | Producto: " + std::string(_nombre);
    linea += " | Stock actual: " + std::to_string(_stockActual);
    linea += " | Stock minimo: " + std::to_string(_stockMinimo);
    linea += " | Precio: " + std::to_string(_precio);

    return linea;
}
