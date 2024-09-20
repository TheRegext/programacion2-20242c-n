///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

///Hacer un proyecto con un menú
        ///para agregar registros,
        ///listar todos los registros y
        ///listar 1 registro (se pide el ingreso de un legajo y se los muestra)

using namespace std;


class Fecha{
    private:
        int dia, mes, anio;
    public:
         Fecha(int d=0, int m=0, int a=0);

         void Cargar();
         void Mostrar(void);
        ///setter
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(const int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};
 ///fin de la definición de la clase
///desarrollo de los métodos
void Fecha::Cargar(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }

void Fecha::Mostrar(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}
///fin de clase Fecha
///desarrollo de clase Alumno
class Alumno{
private:
    int legajo;
    char nombre[30];
    char apellido[30];
    Fecha fechaNacimiento;
    char email[50];
    int codigoCarrera;
public:
    int getLegajo(){return legajo;}
    void setLegajo(int l){legajo=l;}
    void Cargar();
    void Mostrar();
};
///Métodos de alumno
void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"EMAIL ";
    cin>>email;
    cout<<"CARRERA ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO ";
    cout<<legajo<<endl;
    cout<<"NOMBRE ";
    cout<<nombre<<endl;
    cout<<"APELLIDO ";
    cout<<apellido<<endl;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Mostrar();
    cout<<"EMAIL ";
    cout<<email<<endl;
    cout<<"CARRERA ";
    cout<<codigoCarrera<<endl;


}

class ArchivoAlumnos{
private:
    char nombre[50];
public:
    ArchivoAlumnos(const char *n="alumnos.dat"){
        strcpy(nombre, n);
    }
    bool grabarRegistroAlumno(Alumno reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"ab" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int escribio=fwrite(&reg,sizeof(Alumno),1,pAlumno);
        fclose(pAlumno);
        return escribio;

    }

    bool leerRegistroAlumno(Alumno &reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"rb" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
        fclose(pAlumno);
        return leyo;
    }

    bool listarRegistros(){
        FILE *pAlu;
        Alumno reg;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        while(fread(&reg,sizeof(Alumno),1,pAlu)==1){
            reg.Mostrar();
            cout<<endl;
        }

        fclose(pAlu);
        return true;
    }

    int buscarRegistro(int leg){
        FILE *pAlu;
        Alumno reg;
        int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }
        while(fread(&reg,sizeof(Alumno),1,pAlu)==1){
            if(reg.getLegajo()==leg){
                fclose(pAlu);
                return pos;
            }
            pos++;
        }
        fclose(pAlu);
        return -1;
    }
    Alumno leerRegistro(int ubicacion){
        FILE *pAlu;
        Alumno reg;
        reg.setLegajo(-1);
        ///int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return reg;
        }
        /*while(fread(&reg,sizeof(Alumno),1,pAlu)==1){
            if(pos==ubicacion){
              fclose(pAlu);
              return reg;
            }
            pos++;
        }*/
        int cuanto=ubicacion*sizeof(Alumno);
        int desde_donde=0;
        fseek(pAlu,cuanto, desde_donde);
        fread(&reg, sizeof(Alumno),1, pAlu);
        fclose(pAlu);
        return reg;

    }

};

int main(){
    int legajo;
    Alumno reg;
    ArchivoAlumnos archiAlu;
    /*reg.Cargar();
    archiAlu.grabarRegistroAlumno(reg);
    archiAlu.listarRegistros();*/
    cout<<"INGRESE EL LEGAJO DEL ALUMNO QUE SE QUIERE BUSCAR ";
    cin>>legajo;
    int pos=archiAlu.buscarRegistro(legajo);
    if(pos==-1){
          cout<<"NO EXISTE UN ALUMNO CON ESE LEGAJO";

    }
    else{
        reg=archiAlu.leerRegistro(pos);
        if(reg.getLegajo()==-1){
            cout<<"ERROR DE LECTURA";
        }
        else{
            reg.Mostrar();
        }
    }
    cout<<endl;
    system("pause");
	return 0;
}











































