#include <iostream>
using namespace std;
// side effect

void cargar(int vec[], int cant);
int *pedirMemoria(int cant);

void pedirMemoria(int *&vec, int cant);

void cambiar(int &numero){
   numero  = 5;
}

   /***
   NULL ==> 0x00 => 0 --> C
   nullptr ==> 0x00 => 0 --> C++ 11
   */
   
void funcion(){
   int *vec = nullptr;
   
   vec = pedirMemoria(10); /// memory leak  
   vec = pedirMemoria(10);  
   
   for(int i = 0; i < 10; i++){
      cout << vec[i] << endl;
   }
   
   delete [] vec;
   
   
}
int main() {
   funcion();
   funcion();
   funcion();
   
	return 0;
}

int *pedirMemoria(int cant){
   int *vec = new int[cant];
   //int vec[10];
   cargar(vec, cant);
   return vec;
}
   
void pedirMemoria(int *&vec, int cant){
   
   if(vec != nullptr){
      delete [] vec;
   }
   
   vec = new int[cant];
   
   if(vec == nullptr){
      cout << "No se pudo asignar memoria :(" << endl;
      exit(-1);
   }
   
   cargar(vec, cant);   
}


void cargar(int vec[], int cant){
   
   for(int i = 0; i < cant; i++){
      vec[i] = rand() % 10;
   }
}
