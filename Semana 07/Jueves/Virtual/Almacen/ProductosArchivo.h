#pragma once
#include <string>
#include "Producto.h"

class ProductosArchivo{
public:
  ProductosArchivo();
  bool guardar(const Producto &registro);
  bool guardar(int pos, const Producto &registro);
  int buscar(int codigo);
  
  Producto leer(int pos);
  bool leerTodos(Producto registros[], int cantidad);
  int getCantidad();
private:
  std::string _fileName;
};
