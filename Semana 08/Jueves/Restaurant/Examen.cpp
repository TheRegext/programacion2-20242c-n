#include <iostream>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"

void Examen::EjemploDeListado(){
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}

void Examen::Punto1ConMemoriaDinamica(){
   float sumaPuntaje = 0, promedio, *vecPuntajes = nullptr;
   int cantidad = 0, cantidadRegistros, i;

   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa aux;

   cantidadRegistros = archivo.CantidadRegistros();

   vecPuntajes = new float[cantidadRegistros];

   if (vecPuntajes == nullptr){
      return;
   }

   for(i=0; i < cantidadRegistros; i++){
      aux = archivo.Leer(i);
      sumaPuntaje += aux.getPuntajeObtenido();
      vecPuntajes[i] = aux.getPuntajeObtenido();
   }
   promedio = sumaPuntaje / cantidadRegistros;

   for(i = 0; i < cantidadRegistros; i++){
      if (vecPuntajes[i] > promedio){
         cantidad++;
      }
   }

   cout << cantidad << endl;

   delete []vecPuntajes;
}

void Examen::Punto1(){
   Punto1ConMemoriaDinamica();
//   float sumaPuntaje = 0, promedio;
//   int cantidad = 0;
//
//   ArchivoServicioMesa archivo("restaurant.dat");
//   ServicioMesa aux;
//
//   int i, cantidadRegistros = archivo.CantidadRegistros();
//   for(i = 0; i < cantidadRegistros; i++){
//      aux = archivo.Leer(i);
//      sumaPuntaje += aux.getPuntajeObtenido();
//   }
//
//   promedio = sumaPuntaje / cantidadRegistros;
//
//   for(i = 0; i < cantidadRegistros; i++){
//      aux = archivo.Leer(i);
//      if (aux.getPuntajeObtenido() > promedio){
//         cantidad++;
//      }
//   }
//
//   cout << cantidad;

}

void Examen::Punto2(){
   float recaudacionxPlato[70] = {};
   ServicioMesa *vec = nullptr;
   ArchivoServicioMesa archivo("restaurant.dat");
   int i, cantidadRegistros = archivo.CantidadRegistros(), posicionPlatoMaximo = 0;

   vec = new ServicioMesa[cantidadRegistros];
   if (vec == nullptr){
      return;
   }

   archivo.Leer(cantidadRegistros, vec);

   for(i = 0; i < cantidadRegistros; i++){
      int numeroPlato = vec[i].getIDPlato();
      recaudacionxPlato[numeroPlato - 1] += vec[i].getImporte();
   }

   for(i = 0; i< 70; i++){
      if (recaudacionxPlato[i] > recaudacionxPlato[posicionPlatoMaximo]){
         posicionPlatoMaximo = i;
      }
   }

   cout << posicionPlatoMaximo + 1 << endl;

   delete [] vec;
}

void Examen::Punto3(){

   int propinasxMozoEn2024[20] = {}, i, cantidadRegistros, posicionMozoMaximo = 0;
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa aux;

   cantidadRegistros = archivo.CantidadRegistros();

   for(i = 0; i < cantidadRegistros; i++){
      aux = archivo.Leer(i);
      int nroMozo = aux.getIDMozo();

      if (aux.getPropina() > 0 && aux.getFecha().getAnio() == 2024){
         propinasxMozoEn2024[nroMozo-1]++;
      }
   }

   for(i = 0; i < 20; i++){
      if (propinasxMozoEn2024[i] > propinasxMozoEn2024[posicionMozoMaximo]){
         posicionMozoMaximo = i;
      }
   }

   cout << posicionMozoMaximo + 1 << endl;


}
