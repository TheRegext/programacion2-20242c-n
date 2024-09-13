#include <iostream>
using namespace std;
#include "Producto.h"

Producto cargarProducto(){
    int codigo, stockMinimo, stockActual;
    float precio;
    string nombre;

    cout << "Codigo: ";
    cin >> codigo;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Stock minimo: ";
    cin >> stockMinimo;
    cout << "Stock actual: ";
    cin >> stockActual;
    cout << "Precio: $";
    cin >> precio;

    /// Deberían acá las validaciones de cada atributo según corresponda

    Producto aux(codigo, stockActual, stockMinimo, precio, nombre);
    return aux;
}

bool guardarProducto(Producto reg){

    FILE *p = fopen("productos.dat", "ab");
    if (p == NULL){
        return false;
    }
    fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return true;
}

void mostrarProductos(){
    Producto reg;
    FILE *p = fopen("productos.dat", "rb");
    if (p == NULL){
        cout << "No existe el archivo";
        return;
    }
    while (fread(&reg, sizeof(Producto), 1, p) == 1){
        cout << reg.toString() << endl;
    }

    fclose(p);
}

void mostrarProductoPorCodigo(){
    int codigoABuscar;
    cout << "Codigo del producto a buscar: ";
    cin >> codigoABuscar;

    Producto reg;
    FILE *p = fopen("productos.dat", "rb");
    if (p == NULL){
        cout << "No existe el archivo";
        return;
    }
    while (fread(&reg, sizeof(Producto), 1, p) == 1){
        if (codigoABuscar == reg.getCodigo()){
            cout << reg.toString();
            fclose(p);
            return;
        }
    }
    cout << "El producto buscado no existe";
    fclose(p);
}

int main()
{
    int opcion;
    do{
        cout << "Menu" << endl;        cout << "--------------------------------" << endl;
        cout << "1 - Cargar producto" << endl;
        cout << "2 - Mostrar producto x codigo" << endl;
        cout << "3 - Mostrar todos los productos" << endl;
        cout << "--------------------------------" << endl;
        cout << "0 - Salir del programa" << endl;

        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                {
                    Producto aux = cargarProducto();
                    guardarProducto(aux);
                }
                break;
            case 2:
                mostrarProductoPorCodigo();
                break;
            case 3:
                mostrarProductos();
                break;
        }

        cout << endl << endl << endl;

    }while(opcion != 0);


    return 0;
}
