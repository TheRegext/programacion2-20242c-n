#pragma once

#include <string>

class Producto {
private:
    int _codigo;
    int _stockActual;
    int _stockMinimo;
    float _precio;
    std::string _nombre;

public:
    Producto();
    Producto(int codigo, int stockActual, int stockMinimo, float precio, std::string nombre);

    bool getNecesitaReposicion();
    int getCodigo();
    int getStockActual();
    int getStockMinimo();
    float getPrecio();
    std::string getNombre();
    std::string toString();

    void setCodigo(int codigo);
    void setStockActual(int stockActual);
    void setStockMinimo(int stockMinimo);
    void setPrecio(float precio);
    void setNombre(std::string nombre);
};
