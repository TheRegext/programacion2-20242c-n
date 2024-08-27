///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>


using namespace std;

class Alumno{
    private:///significa que todo lo que se ubique en esta parte será accesible dentro de la clase
        int legajo;
        char nombre[30], apellido[30];
        bool regular;
    public: ///todo lo que pongamos acá será accesible tanto dentro como fuera de la clase.
       /* Alumno(){
            legajo=0;
            strcpy(nombre,"nada");
            strcpy(apellido,"nada");
            regular=true;
        }*/
        Alumno(int leg=5, const char *n="todo", const char *a="nada"){
            legajo=leg;
            strcpy(nombre,n);
            strcpy(apellido,a);
            regular=true;
        }
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
    Alumno reg, obj(1, "ANA", "PEREZ"), otro(1);
    reg.Mostrar();
	cout<<endl;
	obj.Mostrar();
	cout<<endl;
	otro.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
