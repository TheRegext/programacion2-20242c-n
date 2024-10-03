#include "Fecha.h"
#include "ArchivoServicioMesa.h"

ArchivoServicioMesa::ArchivoServicioMesa(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoServicioMesa::Guardar(ServicioMesa servicioMesa){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&servicioMesa, sizeof(ServicioMesa), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoServicioMesa::Guardar(ServicioMesa servicioMesa, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(ServicioMesa) * posicion, SEEK_SET);
    bool ok = fwrite(&servicioMesa, sizeof(ServicioMesa), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoServicioMesa::Buscar(int IDServicioMesa){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    ServicioMesa servicioMesa;
    int i = 0;
    while(fread(&servicioMesa, sizeof(ServicioMesa), 1, pArchivo)){
        if(servicioMesa.getIDServicioMesa() == IDServicioMesa){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

ServicioMesa ArchivoServicioMesa::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return ServicioMesa();
    }
    ServicioMesa servicioMesa;
    fseek(pArchivo, sizeof(ServicioMesa) * posicion, SEEK_SET);
    fread(&servicioMesa, sizeof(ServicioMesa), 1, pArchivo);
    fclose(pArchivo);
    return servicioMesa;
}

int ArchivoServicioMesa::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(ServicioMesa);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoServicioMesa::Leer(int cantidadRegistros, ServicioMesa *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(ServicioMesa), 1, pArchivo);
    }
    fclose(pArchivo);
}