#include <iostream>

using namespace std;

int main()
{
  int codVenta, dia, mes, cantidadMeses = 0;
  float ventaMonto;

  float recaudacion[12][31] {};

  cout << "Ingrese codigo de venta: ";
  cin >> codVenta;

  while(codVenta != 0)
  {
    cout << "Ingrese mes de venta: ";
    cin >> mes;

    cout << "Ingrese dia de venta: ";
    cin >> dia;

    cout << "Ingrese monto de venta: ";
    cin >> ventaMonto;


    /// acumulo los montos
    recaudacion[mes-1][dia-1] += ventaMonto;


    cout << "Ingrese codigo de venta: ";
    cin >> codVenta;
  }

  for(int m=0; m<12; m++)
  {
    cout << "----   Mes #" << m+1 << endl;
    bool hayVenta = false;
    for(int d=0; d<31; d++)
    {
      if(recaudacion[m][d] != 0)
      {
        cout << "Dia #"<< d+1 << ": " << recaudacion[m][d] << endl;
        hayVenta = true;
      }
    }

    if(!hayVenta)
    {
      cantidadMeses++;
    }
  }


  
  cout << "La cantidad de mese sin venta son: " << cantidadMeses << endl;
  cout << "La recaudacion del dia 5 del mes de junio es: " << recaudacion[5][4] << endl;


  return 0;
}
