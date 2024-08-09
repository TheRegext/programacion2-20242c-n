/**
Hacer un programa que permita ingresar las ventas del mes
de Julio de un negocio.

Por cada registro de venta se almacena:
- N�mero de venta (entero)
- N�mero de d�a (entero de 1 a 31)
- Importe de la venta (n�mero con decimales)
- Forma de pago (1 - Efectivo, 2 - Tarjeta de Cr�dito, 3 - Pago con QR)

Los datos no se encuentran agrupados ni ordenados.
Se finaliza la carga ingresando un n�mero de venta igual a cero.
Calcular e informar.

A)	La facturaci�n de cada d�a y la facturaci�n mensual.
B)	La cantidad de ventas por cada d�a y forma de pago
C)	El nombre de la forma de pago que mayor dinero haya recaudado.
D)	Los d�as en los que no haya habido ventas.
E)	La cantidad de ventas que no utilizaron un medio electr�nico de pago.

*/
#include <iostream>
using namespace std;

int buscarPosicionMaximoEnVector(float *vec, int tam){
    int posMax = 0;
    for(int i=1; i<tam; i++){
        if (vec[i] > vec[posMax]){
            posMax = i;
        }
    }
    return posMax;
}

int main(){
    int nventa, dia, formaPago;
    float importe;

    // C
    int const CANT_FP = 5;
    float recaudacionFormaPago[CANT_FP] = {};
    string nombresFormaPago[CANT_FP] = {"Efectivo", "Tarj de Credito", "QR", "Cheque", "Transferencia"};

    ///B
    int cantPorDiayFP[31][CANT_FP] = {};



    cout << "Numero de venta: ";
    cin >> nventa;

    while (nventa != 0){
        cout << "Dia: ";
        cin >> dia;
        cout << "Importe: ";
        cin >> importe;
        cout << "Forma de pago: ";
        cin >> formaPago;
        cout << "-----------------------" << endl;

        /// C
        recaudacionFormaPago[formaPago-1] += importe;
        /// B
        cantPorDiayFP[dia-1][formaPago-1]++;

        cout << "Numero de venta: ";
        cin >> nventa;
    }

    int posMax = buscarPosicionMaximoEnVector(recaudacionFormaPago, CANT_FP);
    cout << "La forma de pago que m�s recaud� fue: " << nombresFormaPago[posMax] << endl;


    /// B
    int i, j;
    for(i=0; i<31; i++){
        cout << "DIA " << i+1 << endl;

        for(j=0; j<CANT_FP; j++){

            cout << "\t" << nombresFormaPago[j] << ": " << cantPorDiayFP[i][j] << endl;

        }

    }





    return 0;
}
