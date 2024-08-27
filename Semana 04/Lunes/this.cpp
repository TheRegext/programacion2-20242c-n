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
        ~Alumno(){
            //cout<<"SE MURIO EL OBJETO :-("<<endl;
         }
         void MostrarDireccion(){
            cout<<" VALOR DE this "<<this<<endl;
         }

         ///this es un puntero que contiene la dirección del objeto que llama al método.Por medio de él el método puede leer o
         ///escribir en la propiedad. Se dice que es un puntero oculto, pero si es necesario se puede hacer visible
};

void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>(*this).legajo;
    cout<<"NOMBRE ";
    cin>>this->nombre;
    cout<<"APELLIDO ";
    cin>>apellido;

    regular=true;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO ";
    cout<<this->legajo<<endl;
    cout<<"NOMBRE ";
    cout<<nombre<<endl;
    cout<<"APELLIDO ";
    cout<<apellido<<endl;

}



int main(){

    Alumno alu2, alu1, *pA;

    pA=&alu2;

   /* cout<<"DIRECCION DE alu2 "<<&alu2<<endl;
    alu2.MostrarDireccion();

    cout<<endl<<"DIRECCION DE alu1 "<<&alu1<<endl;
    alu1.MostrarDireccion();*/
    pA->Cargar();
    alu2.Mostrar();
	cout<<endl;
	system("pause");
	return 0;
}
