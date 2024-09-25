///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

# include "alumno.h"/// tiene las clases Alumno y la clase ArchivoAlumno

class AlumnoTup{
private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[50];
    bool estado;
public:
    void Mostrar();
    void operator=(Alumno obj);



};

void AlumnoTup::Mostrar(){
    if(estado){
        cout<<"LEGAJO ";
        cout<<legajo<<endl;
        cout<<"NOMBRE ";
        cout<<nombre<<endl;
        cout<<"APELLIDO ";
        cout<<apellido<<endl;
        cout<<"EMAIL ";
        cout<<email<<endl;
    }
}

void operator=(Alumno obj){
    legajo=obj.getLegajo();
    strcpy(nombre, obj.getNombre());
    strcpy(apellido, obj.getApellido());
    strcpy(email, obj.getEmail());
    estado=obj.getEstado();
}

class ArchivoAlumnosTup{
private:
    char nombre[50];
    int tamanioRegistro;
public:
    ArchivoAlumnosTup(const char *n="alumnosTup.dat"){
        strcpy(nombre, n);
        tamanioRegistro=sizeof(AlumnoTup);
    }
    bool grabarRegistro(AlumnoTup reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"ab" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int escribio=fwrite(&reg,tamanioRegistro,1,pAlumno);
        fclose(pAlumno);
        return escribio;

    }

    bool leerRegistroAlumno(AlumnoTup &reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"rb" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int leyo=fread(&reg,tamanioRegistro,1,pAlumno);
        fclose(pAlumno);
        return leyo;
    }

    bool listarRegistros(){
        FILE *pAlu;
        AlumnoTup reg;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        while(fread(&reg,tamanioRegistro,1,pAlu)==1){
            reg.Mostrar();
            cout<<endl;
        }

        fclose(pAlu);
        return true;
    }

    int buscarRegistro(int leg, bool comoEsta){
        FILE *pAlu;
        AlumnoTup reg;
        int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }
        if(comoEsta==true){
            while(fread(&reg,tamanioRegistro,1,pAlu)==1){
                if(reg.getLegajo()==leg &&reg.getEstado()){
                    fclose(pAlu);
                    return pos;
                }
                pos++;
            }
        }
        else{
            while(fread(&reg,tamanioRegistro,1,pAlu)==1){
                if(reg.getLegajo()==leg){
                    fclose(pAlu);
                    return pos;
                }
                pos++;
            }
        }
        fclose(pAlu);
        return -1;
    }
    AlumnoTup leerRegistro(int ubicacion){
        FILE *pAlu;
        AlumnoTup reg;
        reg.setLegajo(-1);
        ///int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return reg;
        }
        int cuanto=ubicacion*tamanioRegistro;
        int desde_donde=0;
        fseek(pAlu,cuanto, desde_donde);
        fread(&reg, tamanioRegistro,1, pAlu);
        fclose(pAlu);
        return reg;
    }
    int contarRegistros(){
        FILE *pAlu;
        AlumnoTup reg;

        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -1;
        }
        fseek(pAlu,0, 2);///se ubica el puntero al final del archivo
        int cantByte=ftell(pAlu);///ftell() me dice cuántos bytes hay desde el inicio hasta la posición actual
        fclose(pAlu);
        return cantByte/tamanioRegistro;///son los registros totales. No diferencia si están o no borrados los registros
    }
    bool modificarRegistro(AlumnoTup reg, int pos){
        FILE *pAlu;
        pAlu=fopen(nombre, "rb+");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }
        fseek(pAlu,pos*tamanioRegistro, 0);///se ubica el puntero al principio del registro a modificar
        bool escribio=fwrite(&reg, tamanioRegistro,1,pAlu);
        fclose(pAlu);
        return escribio;
    }


};
int main(){
    Alumno reg;
    ArchivoAlumnos archiAlu;

    AlumnoTup aux;
    ArchivoAlumnosTup archiTup;

    int cant=archiAlu.contarRegistros();
    if(cant==0){return -1;}

    for(int i=0;i<cant;i++){
        reg=archiAlu.leerRegistro(i);
        if(reg.getCodigoCarrera()==5){
                aux=reg;
                archiTup.agregarRegistro(aux);
        }
    }

	cout<<endl;
	system("pause");
	return 0;
}
