///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Fecha{
    private:///sólo es accesible dentro de la clase
        int dia, mes, anio;///propiedades->variables de la clase
    public:///puede ser accedido tanto dentro como fuera de la clase
         Fecha(int d=0, int m=0, int a=0){
            dia=d;
            mes=m;
            anio=a;
         }

         void Cargar(){ ///métodos o funciones de la clase
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }
         void Mostrar(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }
        ///setter
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        ///DESTRUCTOR
        ~Fecha(){

        }
        int cantidadDias(Fecha &aux){
           ///forma simplificada que considera que el mes y el año en ambos objetos es igual.
           if(dia>aux.dia) return dia-aux.getDia();
           else return aux.dia-dia;
        }
};



class Persona{
protected:///funciona como private, pero en la herencia permite que las clases derivadas accedan de manera directa
    int DNI;
    char nombre[25];
    char apellido[25];
    Fecha fechaNacimiento; ///objeto de la clase Fecha que es propiedad de la clase persona. COMPOSICIÓN
    char telefono[15];
public:
    void Cargar();
    void Mostrar();
    int getDNI(){return DNI;}
    void setDNI(int d){DNI=d;}
};

void Persona::Cargar(){
    cout<<"DNI ";
    cin>>DNI;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"TELEFONO ";
    cin>>telefono;
}

void Persona::Mostrar(){
    cout<<"DNI "<<DNI<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Mostrar();
    cout<<endl<<"TELEFONO "<<telefono<<endl;
}

///private: todo lo de la clase base va a parar a la parte privada de la derivada
///public: lo que está en la parte privada de la base pasa a la parte privada de la derivada
        ///lo que está en la parte pública de la base pasa a la parte pública de la derivada



class Alumno:public Persona{
private:
    int legajo;
    Fecha fechaInscripcion;
public:
    void Cargar();
    void Mostrar();
    ///int obtenerDNI(){return getDNI();}
    void otroSetDNI(int d){DNI=d;}
};

void Alumno::Cargar(){
    Persona::Cargar();
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"FECHA DE INSCRIPCION "<<endl;
    fechaInscripcion.Cargar();
}

void Alumno::Mostrar(){
    Persona::Mostrar();
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"FECHA DE INSCRIPCION ";
    fechaInscripcion.Mostrar();
}
 class AlumnoTec:public Alumno{


 };

int main(){
    Alumno prueba;
   // prueba.Cargar();
   // prueba.Mostrar();
    prueba.setDNI(1456);
    cout<<prueba.getDNI();
	cout<<endl;
	prueba.otroSetDNI(6540);
    cout<<prueba.getDNI()<<endl;
	system("pause");
	return 0;
}



























