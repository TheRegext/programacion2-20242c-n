#include "Producto.h"

Producto::Producto(int stockActual, int stockMinimo, float precio, std::string nombre) {
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
    _nombre = nombre;
}
