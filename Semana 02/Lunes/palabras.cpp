///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarPalabrasMatrizChar(char cadenas[3][20]){
    int i;
    for(i=0;i<3;i++){
        cout<<"INGRESE PALABRA ";
        cin>>cadenas[i];
    }

}

void cargarPalabrasVectorString(string cadenas[3]){
    int i;
    for(i=0;i<3;i++){
        cout<<"INGRESE PALABRA ";
        cin>>cadenas[i];
    }
}

void mostrarMat(char cadenas[3][20]){
    int i;
    for(i=0;i<3;i++){
        cout<<cadenas[i]<<endl;
    }

}

void mostrarVec(string cadenas[3]){
    int i;
    for(i=0;i<3;i++){
        cout<<cadenas[i]<<endl;
    }
}

int main(){
    char matPal[3][20];
    string  vec[3];
    /*cin>>vecPal;
    int i=0;
    vecPal[4]='j';
    while(vecPal[i]!='\0'){
        cout<<vecPal[i];
        i++;
    } */
    cargarPalabrasMatrizChar(matPal);
    cargarPalabrasVectorString(vec);
    mostrarMat(matPal);
    cout<<endl;
    mostrarVec(vec);
	cout<<endl;
	system("pause");
	return 0;
}
