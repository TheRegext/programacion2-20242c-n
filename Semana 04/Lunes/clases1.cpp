///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

///Clase: molde donde se definen las propiedades y el comportamiento que tendrán los objetos de esa clase
///Al crear una clase agregamos un tipo de datos
///
///en private: ponemos las variables de la clase, o propiedades. ?????
/// en public ponemos las funciones de la clase (métodos). Los métodos definen el comportamiento de los objetos de esa clase

using namespace std;
/*
struct alumno{
    int legajo;
    char nombre[30], apellido[30];
    bool regular;
};*/

class Alumno{
    private:///significa que todo lo que se ubique en esta parte será accesible dentro de la clase
        int legajo;
        char nombre[30], apellido[30];
        bool regular;
    public: ///todo lo que pongamos acá será accesible tanto dentro como fuera de la clase.
        void Cargar();
        void Mostrar();
        ///ASIGNAR VALOR A CADA UNA DE LAS PROPIEDADES-> SET
        void setLegajo(int l){
            if(l>=1000)legajo=l;
            else    l=-1;
        }

        void setNombre(const char *n){
            strcpy(nombre, n);
        }

        void setApellido(const char *n){
            strcpy(apellido, n);
        }
        ///comunicar al mundo externo el valor de las propiedades->GET
        int getLegajo(){return legajo;}

        const char *getNombre(){return nombre;}

        const char  *getApellido(){return apellido;}

        bool getRegular(){return regular;}

};

void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;

    regular=true;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO ";
    cout<<legajo<<endl;
    cout<<"NOMBRE ";
    cout<<nombre<<endl;
    cout<<"APELLIDO ";
    cout<<apellido<<endl;

}

int main(){
    int a;
    Alumno obj, aux;

    obj.Cargar();
    obj.Mostrar();


    aux=obj;
    aux.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
