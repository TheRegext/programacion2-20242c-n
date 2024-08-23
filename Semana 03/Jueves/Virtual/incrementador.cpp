#include <iostream>

using namespace std;

int main()
{
  bool continuar;
  int valorFinal, valorIncremento, cantidadIncrementos;

  valorFinal = 10;
  valorIncremento = 5;
  cantidadIncrementos = 0;

  cout << "Desea incrementar? 1-Si 0-No"<<endl;
  cin >> continuar;

   while(continuar)
  {
    valorFinal += valorIncremento;
    cantidadIncrementos++;

    cout << "Desea incrementar? 1-Si 0-No"<<endl;
    cin >> continuar;
  }

  valorIncremento = 30;
  
  valorFinal -= valorIncremento;
  cantidadIncrementos++;
  
  cout << "Valor final: " << valorFinal << endl;
  cout << "Cantidad de incrementos: " << cantidadIncrementos << endl;

  return 0;
}
