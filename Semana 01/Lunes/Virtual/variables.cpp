///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>

///VARIABLE PUNTERO: variable que almacena una dirección de memoria
using namespace std;

///prototiopos de funciones

void cargarVector(int *v,int tam);  ///(int v[],int tam)
void sumarComponentesVector(int *v,int tam, int &refe);
void mostrarVector(int *v,int tam);

int main(){
    int vec[5]={}, *puntV;///siempre que vea al momento de la declaración un * antes del

    int tamanio=5;     /// del nombre de una variable estoy hablando de un puntero
    /*cout<<vec<<endl;
    system("pause");
    puntV=vec;
    cout<<puntV<<endl;
    system("pause");*/
   // cargarVector(vec,tamanio);///llamadas

   // mostrarVector(vec,tamanio);
    cout<<endl;
    int suma;
    cout<<&suma<<endl;
    sumarComponentesVector(vec,tamanio,suma);
	cout<<"SUMA DE COMPONENTES DEL VECTOR "<<suma;
	cout<<endl;
	system("pause");
	return 0;
}


void cargarVector(int v[],int tam){
    //cout<<v<<endl;
    //system("pause");
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESE UN NUMERO ";
        cin>>v[i];
    }
    //tam=10;
}

void mostrarVector(int v[],int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

void sumarComponentesVector(int *v,int tam, int &refe){
    int i;
    cout<<&refe<<endl;
    refe=0;
    for(i=0;i<tam;i++){
        refe+=v[i];
    }
}
