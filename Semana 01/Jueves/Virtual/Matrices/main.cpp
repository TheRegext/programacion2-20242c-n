#include <iostream>
#include <ctime>
using namespace std;

/**
  dada una lista de 10 numeros enteron comprendidos entre 1 y 10,
  mostrar la cantidad de veces que se ingresa cada numero.
  mostrar la cantidad de numeros distintos que se ingresaron


  [0]
  [1] = true
  .
  .
  .
  [9]


*/

void vectores()
{
  int vec[10] {};
  bool numerosIngresados[10] {};
  int num;

  for(int i=0; i<10; i++)
  {
    cout << "Ingrese un numero: ";
    cin >> num;

    vec[num-1]++;
    numerosIngresados[num-1] = true;

  }


  for(int i=0; i<10; i++)
  {
    cout << vec[i] << endl;
  }

  int cantidad = 0;
  for(int i=0; i<10; i++)
  {
    if(numerosIngresados[i])
    {
      cantidad++;
    }
  }

  cout << "La cantidad de numeros distintos ingresados son: " << cantidad << endl;

}
/// parametros por omision
void mostrarMatriz(int m[][5], int filas = 3, string mensaje = "");
void mostrarMatriz(float m[][5], int filas = 3, string mensaje = "");
void mostrarMatriz(int m[][5], string mensaje);
void mostrarMatriz(float m[][5], string mensaje);

int main()
{
  float mat[10][5] {{1,2,3,4,5},{1,2,3,4,5},{},{5,9,1,5,6},{}};
  int contadores[2][5] {};

  int vec[5] {1,2,3,4,5};

  mostrarMatriz(mat, 10, "Datos de usuario:");
  mostrarMatriz(mat, "Datos Usuario:");

  cout << mat[3][1] << endl;

  return 0;
}


void mostrarMatriz(int m[][5], int filas, string mensaje)
{
  cout << mensaje << endl;
  for(int f=0; f<filas; f++)
  {
    for(int c=0; c<5; c++)
    {
      cout << m[f][c] << " ";
    }
    cout << endl;
  }
}

void mostrarMatriz(int m[][5], string mensaje){
  mostrarMatriz(m, 5, mensaje);
}

void mostrarMatriz(float  m[][5], int filas, string mensaje)
{
  cout << mensaje << endl;
  for(int f=0; f<filas; f++)
  {
    for(int c=0; c<5; c++)
    {
      cout << m[f][c] << " ";
    }
    cout << endl;
  }
}

void mostrarMatriz(float m[][5], string mensaje){
  mostrarMatriz(m, 5, mensaje);
}
/*
void mostrarMatriz(int m[][5], string mensaje){
  cout << mensaje << endl;
  for(int f=0; f<5; f++)
  {
    for(int c=0; c<5; c++)
    {
      cout << m[f][c] << " ";
    }
    cout << endl;
  }
}
*/
