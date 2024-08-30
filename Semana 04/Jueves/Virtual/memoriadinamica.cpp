#include <iostream>
#include <ctime>
using namespace std;

int *generarVector(int cant = 10){
   int *vec = new int[cant];
   
   if(vec == nullptr){
      cout << "Me quede sin memoria :(" << endl;
      exit(-1);
   }
   
   for(int i=0; i < cant; i++){
      vec[i] = rand() % 10;
   }
   
   for(int i=0; i<cant; i++){
      cout << vec[i] << endl;
   }
   
   int * ret = vec;
   return ret;
}

int main() {
   srand(time(0));
   int *vNumeros;
   
   vNumeros = generarVector(1000000);
   cout << "-----" << endl;
   for(int i=0; i<20; i++){
      cout << vNumeros[i] << endl;
   }
	delete [] vNumeros;
	return 0;
}

