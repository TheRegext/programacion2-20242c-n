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

        bool operator==(Fecha aux);
        bool operator==(const char *nombreDia){
            string meses[12]={"ENERO", "FEBRERO","MARZO", "ABRIL"};

            return true;}///para probar la sobrecarga de funciones. La clase no tiene nombres de días
        ///DESTRUCTOR
        ~Fecha(){

        }
       /* int cantidadDias(Fecha &aux){
           ///forma simplificada que considera que el mes y el año en ambos objetos es igual.
           if(dia>aux.dia) return dia-aux.getDia();
           else return aux.dia-dia;
        }*/
};

///SOBRECARGA DE OPERADORES: OPERADORES DEL LENGUAJE TENGAN UN NUEVO COMPORTAMIENTO, ESCRIBIENDO CÓDIGO DENTRO DE LA CLASE
///AGREGAR UNA NUEVA FUNCIONALIDAD A LOS OPERADORES DEL LENGUAJE

bool Fecha::operator==(Fecha aux){
    if(dia!=aux.dia)return false;
    if(mes!=aux.mes)return false;
    if(anio!=aux.anio)return false;
    return true;
}

int main(){
    Fecha var1, obj1;//(15,10,2000);
    ///
    ///
    ///

    ///if(var1.operator==(obj1)==true){
    if(var1==obj1){
            cout<<"LAS FECHAS COINCIDEN";
    }
    else{
        cout<<"LAS FECHAS NO COINCIDEN";
    }
    cout<<endl<<endl;
    if(var1=="Lunes"){
        cout<<"LA FECHA CORRESPONDE A UN DIA LUNES";
    }
	cout<<endl;
	system("pause");
	return 0;
}



