#include <iostream>
#include "Incrementador.h"
/**
  private -- se puede acceder a ellos unicamente desde la clase
  public -- se puede acceder desde cualquier lado (desde el objeto)
  protected -- herencia 
*/


/***

Incrementador
  Propiedades: (atributos)
    valorActual
    valorIncremento
    cantidadIncrementos
  acciones: (metodos o funciones)
    incrementar
    getValor
    getCantidadIncrementos
*/

using namespace std;


void mostrarIncrementador(Incrementador obj){
  cout << "Valor final: " << obj.getValor() << endl;
  cout << "Cantidad de incrementos: " << obj.getCantidadIncrementos() << endl;

}


int main()
{
  bool continuar;
  //int valorIncial = 0, valorIncremento = 10;
  Incrementador objInc(0, 10);/// crea el objeto (se instancia la clase)
  Incrementador obj2(10,100);
  cout << "Desea incrementar? 1-Si 0-No"<<endl;
  cin >> continuar;

   while(continuar)
  {
    objInc.incrementar();

    cout << "Desea incrementar? 1-Si 0-No"<<endl;
    cin >> continuar;
  }

  objInc.incrementar();
  obj2.incrementar();
  
  
  mostrarIncrementador(objInc);
  
  mostrarIncrementador(obj2);

  return 0;
}
