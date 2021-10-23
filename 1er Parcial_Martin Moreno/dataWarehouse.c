#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "micro.h"

int idEmpresa[5]={1000, 1001, 1000, 1002, 1003};

int idTipo[5]={5000, 5002, 5001, 5003, 5002};

int capacidad[5]={35, 40, 10, 25, 20};

int hardcodearMicro(eMicro micros[], int tam, int cant, int* pId)
{
    int contador = -1;

    if(micros !=NULL && tam>0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i=0; i<cant; i++)
        {
            micros[i].id= *pId;
            (*pId)++;
            micros[i].idEmpresa = idEmpresa[i];
            micros[i].idTipo = idTipo[i];
            micros[i].capacidad= capacidad[i];
            micros[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}
