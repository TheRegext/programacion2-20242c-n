#include <iostream>
#include "Producto.h"
#include "ProductosArchivo.h"

using namespace std;

/// PascalCase -> normalmente se utiliza para los identificadores de clases

Producto cargarProducto(){
  int codigo, stockMinimo, stockActual;
  float precio;
  string nombre;
  
  cout << "Ingrese codigo: ";
  cin >> codigo;
  
  cout << "Ingrese stock minimo: ";
  cin >> stockMinimo;
  
  cout << "Ingrese stock actual: ";
  cin >> stockActual;
  
  cout << "Ingrese precio: ";
  cin >> precio;
  
  cout << "Ingrese nombre: ";
  cin.ignore();
  getline(cin, nombre);
  
  return Producto(codigo, stockActual, stockMinimo, precio, nombre );
}

void mostrarProducto(Producto producto){
  cout << "---------------------------" << endl;
  cout << "Codigo: " << producto.getCodigo() << endl;
  cout << "Nombre: " << producto.getNombre() << endl;
  cout << "Precio: " << producto.getPrecio() << endl;
  cout << "Stock Actual: " << producto.getStockActual() << endl;
  cout << "Stock Minimo: " << producto.getStockMinimo() << endl;
}

void mostrarTodos(){
  ProductosArchivo pa;
  Producto *productos;
  
  int cantidad = pa.getCantidad();
  
  productos = new Producto[cantidad];
  
  pa.leerTodos(productos, cantidad);
  
  for(int i=0; i < cantidad ; i++){
    mostrarProducto(productos[i]);    
  }
  
  delete [] productos;
}

void guardarProducto(){
  Producto p;
  ProductosArchivo pa;

  p = cargarProducto();
  
  if(pa.guardar(p)){
    cout << "Producto guardado con exito!"<<endl;  
  }
  else{
    cout << "No se pudo guardar el producto" << endl;  
  }
}


void modificarProducto(){
  Producto p;
  ProductosArchivo pa;
  int codigo;
  
  cout << "Ingrese codigo a modificar: ";
  cin >> codigo;
  
  int pos = pa.buscar(codigo);
  
  if(pos != -1){
    p = pa.leer(pos);
    
    cout << "Datos del producto: "<< endl;
    mostrarProducto(p);
    
    cout << "MODIFICAR: " << endl;

    p = cargarProducto();
    
    pa.guardar(pos, p);
  }
  else{
    cout << "El producto no se encuentra en el sistema." << endl;  
  }
  
}

int main(){
  int numero;
  
  numero = 7;
  
  numero = numero + 2;
  
  cout << numero;
  
  
  
   //guardarProducto();
   
  //modificarProducto();
  //cout << "-------------------" << endl;
  // mostrarTodos(); 
  return 0;
}

/****

  Menu:
    1- Cargar Producto (codigo sea autonumerico)
    2- Mostrar todos los productos
    3- Modificar un producto por Codigo
    4- Eliminar un producto por Codigo
    5- Mostrar los productos ordenados por nombre
    6- Bucar producto por Codigo
    7- Restaurar producto por codigo
    0- Salir


*/


