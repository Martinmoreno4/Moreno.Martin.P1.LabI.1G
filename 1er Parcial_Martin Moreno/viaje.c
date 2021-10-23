#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viaje.h"
#include "destino.h"
#include "micro.h"

int inicializarViajes(eViaje viajes[], int tam)
{
    int todoOk = 0;
    if( viajes != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            viajes[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

void mostrarViaje(eViaje viaje, eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE)
{
    char empresaMicro[20];
    char descDestino[20];

    if(cargarDescripcionDestino(destinos, tamD, viaje.idDestino, descDestino) == 1
       && cargarEmpresaMicro(micros, tam, viaje.idMicro, empresaMicro, empresas, tamE) == 1)
    {
        printf("    %d    %10s    %10s   %d/%d/%d\n",
        viaje.id,
        empresaMicro,
        descDestino,
        viaje.fecha.dia,
        viaje.fecha.mes,
        viaje.fecha.anio
        );
    }


}

int mostrarViajes(eViaje viajes[], eMicro micros[], int tam, eDestino destinos[], int tamD, eEmpresa empresas[], int tamE)
{
    int todoOk =0;
    int flag = 1;
    if(micros != NULL && tam > 0 && destinos != NULL && empresas != NULL)
    {
        printf("          *** Lista de viajes ***\n");
        printf("----------------------------------------------------------\n");
        printf("    id        micro      destino   Fecha\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!viajes[i].isEmpty)
            {
                mostrarViaje(viajes[i], micros, tam, destinos, tamD, empresas, tamE);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay viajes para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}
