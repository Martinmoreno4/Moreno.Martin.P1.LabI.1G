#include"fecha.h"
#include "micro.h"
#include "destino.h"
#include "empresa.h"
#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eViaje;

#endif // VIAJE_H_INCLUDED

int inicializarViajes(eViaje viajes[], int tam);
void mostrarViaje(eViaje viaje, eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE);
int mostrarViajes(eViaje viajes[], eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE);
