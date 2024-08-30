#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED

///COMPLETAR LOS MÉTODOS SET Y GET FALTANTES.
///AGREGAR DOS MÉTODOS. UNO PARA CARGAR TODAS LAS PROPIE
///DADES Y OTRO PARA MOSTRARLAS.

class Alumno{
    private:
        int legajo;
        int dni;
        char nombre[30];
        char apellido[30];
        int codigoCarrera;
    public:
        Alumno(int l=0, int d=0, const char *n="S/N", const char *a="S/A", int cC=0);
        void setLegajo(int l);
        void setDni(int d);
        void setNombre(const char *n);
        void setApellido(const char *a);
        void setCodigoCarrera(int cC);
        int getLegajo();
        int getDni();
        const char *getNombre();
        const char *getApellido();
        int getCodigoCarrera();
        void Cargar();
        void Mostrar();
        ~Alumno();
};

#endif // CLSALUMNO_H_INCLUDED
