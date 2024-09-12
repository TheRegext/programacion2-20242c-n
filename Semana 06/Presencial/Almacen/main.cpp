#include <iostream>
using namespace std;
#include "Producto.h"

void rellenarInventario(Producto *vec){
    vec[0].setCodigo(1000);
    vec[0].setNombre("Tostadora");
    vec[0].setPrecio(30000);
    vec[0].setStockActual(5);
    vec[0].setStockMinimo(10);

    vec[1].setCodigo(1001);
    vec[1].setNombre("Licuadora");
    vec[1].setPrecio(45000);
    vec[1].setStockActual(8);
    vec[1].setStockMinimo(5);

    vec[2].setCodigo(1002);
    vec[2].setNombre("Horno Microondas");
    vec[2].setPrecio(75000);
    vec[2].setStockActual(4);
    vec[2].setStockMinimo(3);

    vec[3].setCodigo(1003);
    vec[3].setNombre("Refrigerador");
    vec[3].setPrecio(350000);
    vec[3].setStockActual(2);
    vec[3].setStockMinimo(10);

    vec[4].setCodigo(1004);
    vec[4].setNombre("Cafetera");
    vec[4].setPrecio(25000);
    vec[4].setStockActual(10);
    vec[4].setStockMinimo(7);

    vec[5].setCodigo(1005);
    vec[5].setNombre("Aspiradora");
    vec[5].setPrecio(60000);
    vec[5].setStockActual(3);
    vec[5].setStockMinimo(4);

    vec[6].setCodigo(1006);
    vec[6].setNombre("Lavarropas");
    vec[6].setPrecio(220000);
    vec[6].setStockActual(1);
    vec[6].setStockMinimo(1);

    vec[7].setCodigo(1007);
    vec[7].setNombre("Secadora");
    vec[7].setPrecio(180000);
    vec[7].setStockActual(2);
    vec[7].setStockMinimo(2);

    vec[8].setCodigo(1008);
    vec[8].setNombre("Plancha");
    vec[8].setPrecio(15000);
    vec[8].setStockActual(12);
    vec[8].setStockMinimo(6);

    vec[9].setCodigo(1009);
    vec[9].setNombre("Ventilador");
    vec[9].setPrecio(20000);
    vec[9].setStockActual(9);
    vec[9].setStockMinimo(5);



}

void mostrarInventario(Producto *inventario, int cantidad){
    int i;
    for(i=0; i<cantidad; i++){
        cout << inventario[i].toString() << endl;
    }
}

void reportarInventarioFaltante(Producto *inventario, int cantidad){
    int i;

    cout << "PRODUCTOS QUE NECESITAN REPOSICION:" << endl << "----------------------------" << endl;
    for(i=0; i<cantidad; i++){
        if (inventario[i].getNecesitaReposicion()){
            cout << "El producto " << inventario[i].getNombre() << " necesita un nuevo pedido." << endl;
        }
    }
}

int main()
{
    int i;
    Producto inventario[10];
    rellenarInventario(inventario);
    mostrarInventario(inventario, 10);
    cout << endl;
    reportarInventarioFaltante(inventario, 10);
    return 0;
}
