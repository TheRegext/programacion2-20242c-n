#include <iostream>
using namespace std;

int buscarMaximo(int *vec, int tam){
    int i, valorMaximo = vec[0];
    for(i=1; i<tam; i++){
        if (vec[i] > valorMaximo){
            valorMaximo = vec[i];
        }
    }
    return valorMaximo;
}

void obtenerIndicesConElementosIgualesA(int *vec, int *vecIndices, int tam, int elementoABuscar){
    for(int i=0; i<tam; i++){
        if (vec[i] == elementoABuscar){
            vecIndices[i] = i+1;
        }
    }
}

int main()
{
   const int MAT = 3;
   int i, j, cantidadInscripciones;
   int maxInscripciones = 0, materiaMaxInscripciones;
   /// A
   int cantInscriptosxMateria[MAT];
   int codigosMateriasMaximo[MAT] = {};

   for(i=1; i<=MAT; i++){
        cout << "Materia #" << i << endl;
        cout << "-----------------------" << endl;
        cout << "Cantidad de inscripciones: ";
        cin >> cantidadInscripciones;
        cantInscriptosxMateria[i-1] = cantidadInscripciones;
   }

   maxInscripciones = buscarMaximo(cantInscriptosxMateria, MAT);
   cout << "La/s materia/s con mayor cantidad de inscripciones" << endl;
   obtenerIndicesConElementosIgualesA(cantInscriptosxMateria, codigosMateriasMaximo, MAT, maxInscripciones);
   for(i=0; i<MAT; i++){
        if(codigosMateriasMaximo[i] != 0){
            cout << codigosMateriasMaximo[i] << endl;
        }
   }
   return 0;
}
