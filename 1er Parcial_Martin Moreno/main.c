#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "biblioteca.h"
#include "dataWarehouse.h"
#include "destino.h"
#include "empresa.h"
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "viaje.h"
#define TAM 10
#define TAM_V 10
#define TAM_E 4
#define TAM_T 4
#define TAM_D 4

int main()
{
    char seguir = 's';
    int nextId = 2000;
    int nextIdViaje = 4000;

    eMicro micros[TAM];
    eViaje viajes[TAM_V];


    eEmpresa empresas[TAM_E]=
    {
       {1000, "Plusmar"},
       {1001, "Flecha Bus"},
       {1002, "Tas"},
       {1003, "El Rapido"}
    };

    eTipo tipos[TAM_T]=
    {
       {5000, "Comun",},
       {5001, "CocheCama",},
       {5002, "Doble",},
       {5003, "Vip"}
    };

    eDestino destinos[TAM_D]=
    {
       {20000, "Calafate", 22250},
       {20001, "Bariloche", 103000},
       {20002, "Iguazu", 84400},
       {20003, "Mendoza", 95600}
    };

    if(!inicializarMicros(micros, TAM))
    {
        printf("problema al inicializar los micros\n");
    };

    if(!inicializarViajes(viajes, TAM_V))
    {
        printf("problema al inicializar los Viajes\n");
    };

    hardcodearMicro(micros, TAM, 5, &nextId);

    do{
        switch(toupper(menu()))
        {
        case 'A':
            if(!altaMicro(micros, TAM, &nextId, empresas, TAM_E, tipos, TAM_T))
            {
                printf("No se pudo realizar el alta\n");
            }
            else
            {
                printf("Alta exitosa\n");
            }
            break;

        case 'B':
            if(modificarMicro(micros, TAM, empresas, TAM_E, tipos, TAM_T))
            {
                printf("modificacion exitosa\n");
            }
            else
            {
               printf("No se pudo realizar la modificacion\n");
            }
            break;

        case 'C':
            if(!bajaMicro(micros, TAM, tipos, TAM_T, empresas, TAM_E))
            {
                printf("No se pudo realizar la baja\n");
            }
            else
            {
                printf("Baja exitosa\n");
            }
            break;

        case 'D':
            system("cls");
            ordenarMicros(micros, TAM);
            mostrarMicros(micros, TAM, tipos, TAM_T, empresas, TAM_E);
            break;

        case 'E':
            system("cls");
            mostrarEmpresas(empresas, TAM_E);
            break;

        case 'F':
            system("cls");
            mostrarTipos(tipos, TAM_T);
            break;

        case 'G':
            system("cls");
            mostrarDestinos(destinos, TAM_D);
            break;

        case 'H':
            printf("alta\n");
            break;

        case 'I':
            system("cls");

            break;

        case 'X':
            printf("Ha seleccionado salir\n");
            seguir = 'n';
            break;

        default:
            printf("opcion invalida\n");
            break;
        }
        system("pause");
    }while(seguir == 's');

    return 0;
}
