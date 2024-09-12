#pragma once

#include <string>

class Producto {
private:
    int _stockActual;
    int _stockMinimo;
    float _precio;
    std::string _nombre;

public:
    Producto(int stockActual, int stockMinimo, float precio, std::string nombre);

    int getStockActual();
    int getStockMinimo();
    float getPrecio();
    std::string getNombre();

    void setStockActual(int stockActual);
    void setStockMinimo(int stockMinimo);
    void setPrecio(float precio);
    void setNombre(std::string nombre);
};
