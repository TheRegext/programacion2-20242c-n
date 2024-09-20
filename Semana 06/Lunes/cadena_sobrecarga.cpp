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
    Cadena(const char *texto="NADA"){
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
    ///sobrecargas
    bool operator==(Cadena cad){
        return !strcmp(p,cad.p);///! NOT INVIERTE EL VALOR LOGICO
                                ///strcmp(cad1, cad2)-> devuelve 0 si las cadenas son iguales
    }
    bool operator==(const char *vec){
        int resultado=strcmp(p,vec);///! NOT INVIERTE EL VALOR LOGICO
        if(resultado==0)return true;
        return false;                        ///strcmp(cad1, cad2)-> devuelve 0 si las cadenas son iguales
    }
    void operator=(Cadena obj){
        delete []p;
        tam=obj.tam;
        p=new char[tam];
        if(p==nullptr)exit(1);
        strcpy(p,obj.p);
    }
    void operator=(const char *cad){
        delete []p;
        tam=strlen(cad)+1;
        p=new char[tam];
        if(p==nullptr)exit(1);
        strcpy(p,cad);
    }
    Cadena operator+(const Cadena &aux){
        Cadena interna;
        interna.tam=tam+aux.tam-1;
        delete []interna.p;
        interna.p=new char[interna.tam];
        if(interna.p==nullptr)exit(1);

        strcpy(interna.p,p);
        strcat(interna.p, aux.p);

        return interna;
    }

    ~Cadena(){
       /// cout<<"SE MURIO EL OBJETO :-("<<endl;
        delete []p;
    }
    friend ostream& operator<<(ostream &salida,Cadena obj);
	friend istream& operator>>(istream &entrada,Cadena &obj);

	friend void soyAmiga(Cadena cad);

};

ostream& operator<<(ostream &salida,Cadena obj){
	cout<<obj.p;
	return salida;
	}

istream& operator>>(istream &entrada,Cadena &obj){
	char palabra[30];
	entrada.getline(palabra, 30);
	delete []obj.p;
	obj.tam=strlen(palabra)+1;
	obj.p=new char[obj.tam];
	if(obj.p==NULL) exit(1);
	strcpy(obj.p,palabra);
	return entrada;
	}

void soyAmiga(Cadena cad){
    cout<<cad.p<<endl;
}

int main(){
    Cadena palabra("HOLA a todos"), otra(" CHAU"), juntas("algo");
    /*cout<<"palabra antes de la asignacion ";
    palabra.Mostrar();
    cout<<endl;
    palabra=otra;
    cout<<"palabra despues de la asignacion ";
    palabra.Mostrar();

    palabra="QUIERO QUE FUNCIONE";
    cout<<"palabra despues de la asignacion ";
    palabra.Mostrar();


    if(palabra=="HOLA"){
        cout<<"LAS PALABRAS SON IGUALES";
    }
    else{
        cout<<"LAS PALABRAS NO SON IGUALES";
    }

    juntas=palabra+otra;
    juntas.Mostrar();*/
    //cin>>palabra;
    //cout<<palabra;
    soyAmiga(palabra);
    cout<<endl;
	system("pause");
	return 0;
}
