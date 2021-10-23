#include "tipo.h"
#include "empresa.h"
#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;

}eMicro;

#endif // MICRO_H_INCLUDED

int menu();
int menuModificacion();

int inicializarMicros(eMicro micros[], int tam);
int altaMicro(eMicro micros[], int tam, int* nextId, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int buscarLibre(eMicro micros[], int tam);
int buscarMicroId(eMicro micros[], int tam, int id);
void mostrarMicro(eMicro micro, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);
int mostrarMicros(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);
int modificarMicro(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);
int bajaMicro(eMicro micros[], int tam, eTipo tipos[],int tamT, eEmpresa empresas[], int tamE);
int ordenarMicros(eMicro micros[], int tam);
int cargarEmpresaMicro(eMicro micros[],int tam, int id, char empresaDesc[], eEmpresa empresa[], int tamE);
