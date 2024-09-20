
#include "ProductosArchivo.h"

ProductosArchivo::ProductosArchivo(){
  _fileName = "productos.dat";
}

bool ProductosArchivo::guardar(const Producto &registro){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_fileName.c_str(), "ab");
  
  if(pFile == nullptr){
    return false;  
  }
  
  result = fwrite(&registro, sizeof(Producto), 1, pFile) == 1;
  
  fclose(pFile);

  return result;
}

Producto ProductosArchivo::leer(int pos){
  FILE *pFile;
  Producto registro;
  
  pFile = fopen(_fileName.c_str(), "rb");
  
  if(pFile == nullptr){
      return registro;
  }
  
  fseek(pFile, sizeof(Producto) * pos, SEEK_SET);
  
  fread(&registro, sizeof(Producto), 1, pFile);
  
  fclose(pFile);
  
  return registro;  
}


int ProductosArchivo::getCantidad(){
  int total, cantidad;
  FILE *pFile;
  pFile = fopen(_fileName.c_str(), "rb");
  
  if(pFile == nullptr){
      return 0;
  }
  
  fseek(pFile, 0, SEEK_END);
  total = ftell(pFile);
    
  fclose(pFile);
  
  return total / sizeof(Producto);
}


bool ProductosArchivo::leerTodos(Producto registros[], int cantidad){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_fileName.c_str(), "rb");
  
  if(pFile == nullptr){
      return false;
  }
  
  result = fread(registros, sizeof(Producto), cantidad, pFile) == cantidad;
  
  fclose(pFile);
  
  return result;  
}


bool ProductosArchivo::guardar(int pos, const Producto &registro){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_fileName.c_str(), "rb+");
  
  if(pFile == nullptr){
    return false;  
  }
  
  fseek(pFile, sizeof(Producto) * pos, SEEK_SET);
  
  result = fwrite(&registro, sizeof(Producto), 1, pFile) == 1;
  
  fclose(pFile);

  return result;
}

int ProductosArchivo::buscar(int codigo){
  FILE *pFile;
  bool result;
  Producto registro;
  int pos = 0;
  
  pFile = fopen(_fileName.c_str(), "rb");
  
  if(pFile == nullptr){
      return false;
  }
  
  while(fread(&registro, sizeof(Producto), 1, pFile)==1){
    if(registro.getCodigo() == codigo){
        break;
    }    
    pos++;
  }

  fclose(pFile);
  
  if(registro.getCodigo() == codigo){
    return pos;    
  }  
  else{
    return -1;  
  }
  
}
