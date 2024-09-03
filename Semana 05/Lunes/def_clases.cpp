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
         void Mostrar();
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

void funcion1(){
    int x=3;
    cout<<x<<endl;

}
int main(){
    int n1(5), n2(3), n3(15), z;
    Fecha f1, f2;
    funcion1();
    system("pause");
    cout<<"TAMANIO DE VARIABLE DE TIPO Fecha "<<sizeof(f1)<<endl;
    cout<<"TAMANIO DE VARIABLE DE TIPO int "<<sizeof(int)<<endl;
    f1.Cargar();
    f2.Cargar();
    int dias=f1.cantidadDias(f2);
    cout<<"LA CANTIDAD DE DIAS ENTRE LAS DOS FECHAS ES "<<dias<<endl;
	cout<<endl;
	system("pause");
	return 0;
}



/*Punto p1, p3;


cout<<p1.calcularDistancia(p3);


sqrt((x2 - x1)^2 + (y2 - y1)^2).

sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)).
*/
