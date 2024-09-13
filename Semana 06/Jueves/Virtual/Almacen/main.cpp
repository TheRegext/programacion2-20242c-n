#include <iostream>
#include "Producto.h"

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

void guardarEnDisco(Producto &producto){
  FILE *pFile;
  pFile = fopen("productos.dat", "ab");
  ///    inicio,    tam reg,      cant reg,  enlace
  fwrite(&producto, sizeof(Producto), 1, pFile);
  
  fclose(pFile);
}

void mostrarTodos(){
 Producto producto;
  FILE *pFile;
  pFile = fopen("productos.dat", "rb");
  
  while(fread(&producto, sizeof(Producto),1, pFile) == 1){
    mostrarProducto(producto);  
  }
  
  fclose(pFile);
}

/***
  - Datos binarios
  - Estructurados (registro)
  - Cada registro es de un tama¤o constante (uniforme)
*/
int main(){
  
  //cout << sizeof (Producto) << endl;
  /*
  string nombre;
  
  cout << sizeof(nombre) << endl;
  
  nombre = "Hola Mundo";
  
  cout << sizeof(nombre) << endl;
  
  */
  
  /**
    fopen() - Abrir un archivo (crea un enlace)
      ab -- Append agregar
      rb -- read leer
      wb -- sobreescribe
      
    
    fwrite() - escribe
    
    fread() - leer
    
    fclose() - Cierra el archivo
  */
  /***
    Menu 
      1- Cargar producto
      2- Ver todos los productos
      3- Ver los prodcutos con stock faltante
  */
  
  
  /**
    Crar un registro en el archivo
  **/
  
  Producto producto;
  producto = cargarProducto();
  
  guardarEnDisco(producto);
  
  mostrarTodos();  
  
  
  /*
  
  Producto productos[5];
  
  /// cargar productos
  for(int i=0; i < 1; i++){
    productos[i] = cargarProducto();  
  }
  
  /// mostrarlos
  for(int i=0; i < 1; i++){
      mostrarProducto(productos[i]);
  }
  
  */
  
  return 0;
}
