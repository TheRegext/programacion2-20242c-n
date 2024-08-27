///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>
///Hacer una clase de nombre cadena para almacenar palabras,
///que ajuste su tamaño a la cantidad de caracteres estrictamente necesarios

using namespace std;

class Cadena{
private:
    char *p;
    int tam;
public:
    Cadena(const char *texto){
        tam=strlen(texto)+1;
        p=new char[tam];
        if(p==nullptr)exit(1);
        strcpy(p,texto);
        p[tam-1]='\0';
    }
    void Mostrar(){
        cout<<p<<endl;
    }
    int getTamanio(){return tam;}

    ~Cadena(){
        cout<<"SE MURIO EL OBJETO :-("<<endl;
        delete []p;
    }

};

int main(){
    Cadena palabra("HOLA A TODOS/AS LOS/LAS QUE ESTAN EN LA CLASE DE PROGRAMACION 2");

    palabra.Mostrar();
    {
        Cadena interna("chau");
    }
	cout<<endl;
	system("pause");
	cout<<"TAMANIO "<<palabra.getTamanio()<<endl;
	system("pause");
	return 0;
}
