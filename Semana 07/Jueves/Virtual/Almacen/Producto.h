#pragma once
#include <string>

class Producto {
public:
    Producto();
    Producto(int codigo, int stockActual, int stockMinimo, float precio, std::string nombre);

    int getCodigo() const;
    int getStockActual() const;
    int getStockMinimo() const;
    float getPrecio() const;
    std::string getNombre() const;
    
    bool getEliminado() const;

    void setCodigo(int codigo);
    void setStockActual(int stockActual);
    void setStockMinimo(int stockMinimo);
    void setPrecio(float precio);
    void setNombre(std::string nombre);
    
    void setEliminado(bool eliminado);
    
private:
    int _codigo;
    int _stockActual;
    int _stockMinimo;
    float _precio;
    // std::string _nombre;/// como es dinamico no lo puedo guardar en archivos
    char _nombre[100];
    bool _eliminado;

};
