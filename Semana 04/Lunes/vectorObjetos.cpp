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

void cargarAlumnos(Alumno *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].Cargar();
        cout<<endl;
    }
}

void mostrarAlumnos(Alumno *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].Mostrar();
        cout<<endl<<endl;
    }
}

int buscarLegajo(Alumno *v, int tam, int legajo){
    int i;
    for(i=0;i<tam;i++){
        if(v[i].getLegajo()==legajo)return i;
    }
    return -1;
}

int main(){
    Alumno vAlumnos[5];

    cargarAlumnos(vAlumnos,3);
    system("cls");
    mostrarAlumnos(vAlumnos, 3);

    int legajo;
    cout<<"INGRESE EL LEGAJO A BUSCAR ";
    cin>>legajo;
    int pos=buscarLegajo(vAlumnos, 3, legajo);
    if(pos!=-1) vAlumnos[pos].Mostrar();
    else cout<<"NO EXISTE NINGUN ALUMNO CON ESE LEGAJO";

	cout<<endl;
	system("pause");
	return 0;
}
