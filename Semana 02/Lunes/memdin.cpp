///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>v[i];
    }
}

void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}

int main(){
    int tam;
    char *vec;
    cout<<"INGRESE LA CANTIDAD DE ELEMENTOS PARA EL VECTOR ";
    cin>>tam;
    vec=new char[tam];
    if(vec==NULL){
        cout<<"PROBLEMA DE ASIGNACION DE MEMORIA";
        return -1;
    }

    cout<<"INGRESE "<<tam<<" NUMEROS PARA CARGAR EL VECTOR "<<endl;
    cin>>vec;
    cout<<vec<<endl;
    delete []vec;
    return 0;
//    cargarVector(vec, tam);
/*    system("pause");
    system("cls");
    cout<<"EL VECTOR CONTIENE LOS SIGUIENTES VALORES"<<endl;
    mostrarVector(vec, tam);
	cout<<endl;
	system("pause");

	delete []vec;
	return 0;*/
}
