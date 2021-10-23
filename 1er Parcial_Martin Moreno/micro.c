#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "micro.h"

int menu()
{
    char opcion;
    system("cls");
    printf("A. Alta Micro\n");
    printf("B. Modificar Micro\n");
    printf("C. Baja Micro\n");
    printf("D. Listar Micros\n");
    printf("E. Listar Empresas\n");
    printf("F. Listar Tipos\n");
    printf("G. Listar Destinos\n");
    printf("H. Alta Viaje\n");
    printf("I. Listar Viajes\n");
    printf("X. Salir\n");
    printf("ingrese opcion: ");
    scanf("%c",&opcion);

    return opcion;

}

int menuModificacionMicro()
{
    int opcion;

    printf("1- Tipo \n");
    printf("2- Capacidad\n");
    printf("3- cancelar \n");

    printf("ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int inicializarMicros(eMicro micros[], int tam)
{
    int todoOk = 0;
    if( micros != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            micros[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eMicro micros[], int tam)
{

    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(micros[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMicro(eMicro micros[], int tam, int* nextId, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    eMicro auxMicro;

    if( micros != NULL && tam>0)
    {
        system("cls");
        printf("     *** Alta Micro ***\n\n");

        indice = buscarLibre(micros, tam);
        if(indice == -1)
        {
            printf("no hay lugar \n");
        }
        else
        {
            auxMicro.id = *nextId;
            (*nextId)++;

            mostrarEmpresas(empresas, tamE);
            printf("ingrese id de Empresa: ");
            scanf("%d", &auxMicro.idEmpresa);
            while(!validarEmpresas(auxMicro.idEmpresa, empresas, tamE))
            {
                mostrarEmpresas(empresas, tamE);
                printf("id invalido, ingrese id de Empresa VALIDO: ");
                scanf("%d", &auxMicro.idEmpresa);
            }

            mostrarTipos(tipos, tamT);
            printf("ingrese id de Tipos: ");
            scanf("%d", &auxMicro.idTipo);
            while(!validarTipos(auxMicro.idTipo, tipos, tamT))
            {
                mostrarTipos(tipos, tamT);
                printf("id invalido, ingrese id de Tipo VALIDO: ");
                scanf("%d", &auxMicro.idTipo);
            }

            printf("ingrese capacidad: ");
            scanf("%d", &auxMicro.capacidad);
            while(auxMicro.capacidad > 50 || auxMicro.capacidad < 1)
            {
                printf("valor invalido, debe ser un numero entre 1 y 50. ingrese capacidad valida: ");
                scanf("%d", &auxMicro.capacidad);
            }

            auxMicro.isEmpty = 0;

            micros[indice] = auxMicro;

            todoOk = 1;
        }


    }
    return todoOk;
}

int buscarMicroId(eMicro micros[], int tam, int id)
{
    int indice = -1;
    if(micros != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty && micros[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarMicro(eMicro micro, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{
    char descTipo[20];
    char descEmpresa[20];

    if(cargarDescripcionTipo(tipos, tamT, micro.idTipo, descTipo) == 1
       && cargarDescripcionEmpresa(empresas, tamE, micro.idEmpresa, descEmpresa) == 1)
    {
        printf("    %d     %10s     %10s   %d\n",
        micro.id,
        descTipo,
        descEmpresa,
        micro.capacidad
        );
    }
}

int mostrarMicros(eMicro micros[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{
    int todoOk =0;
    int flag = 1;
    if(micros != NULL && tam > 0)
    {
        printf("          *** Lista de Micros ***\n");
        printf("----------------------------------------------------------\n");
        printf("    id      Empresa       Tipo         Capacidad\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!micros[i].isEmpty)
            {
                mostrarMicro(micros[i], tipos, tamT, empresas, tamE);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay micros para mostrar\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int modificarMicro(eMicro micros[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    int auxCapacidad;
    eMicro auxMicro;


    if(micros != NULL && tam>0)
    {
        system("cls");
        printf("      *** Modificar Micro ***\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(micros, tam, id);

        if(indice == -1)
        {
            printf("El id; %d no esta registrado\n", id);
        }
        else
        {
            mostrarMicro(micros[indice], tipos, tamT, empresas, tamE);
            printf("Confirma Modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                switch(menuModificacionMicro())
                {
                case 1:
                    mostrarTipos(tipos, tamT);
                    printf("ingrese id de tipos: ");
                    scanf("%d", &auxMicro.idTipo);
                    while(buscarTipoId(tipos, tam, auxMicro.idTipo) == -1)
                    {
                        mostrarTipos(tipos, tamT);
                        printf("id invalido, ingrese id de tipo VALIDO: ");
                        scanf("%d", &auxMicro.idTipo);
                    }
                    break;

                case 2:

                    printf("Ingrese nueva Capacidad: ");
                    fflush(stdin);
                    scanf("%d", &auxCapacidad);
                    while(auxCapacidad<1 || auxCapacidad>50)
                    {
                        printf("ingrese valor valido de capacidad, deve ser entr 1 y 50: ");
                        fflush(stdin);
                        scanf("%d", &auxCapacidad);
                    }
                    micros[indice].capacidad=auxCapacidad;
                    break;

                case 3:
                    break;

                default:
                    printf("Opcion invalida!!\n");
                }

                todoOk = 1;
            }
            else
            {
                printf("Modificacion cancelada\n");
            }
        }
    }
    return todoOk;
}

int bajaMicro(eMicro micros[], int tam, eTipo tipos[],int tamT, eEmpresa empresas[], int tamE)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(micros != NULL && tam>0)
    {
        system("cls");
        printf("      *** Baja Micro ***\n\n");
        mostrarMicros(micros, tam, tipos, tamT, empresas, tamE);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = buscarMicroId(micros, tam, id);

        if(indice == -1)
        {
            printf("El id; %d no esta registrado\n", id);
        }
        else
        {
            mostrarMicro(micros[indice], tipos, tamT, empresas, tamE);
            printf("Confirma Baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                micros[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada\n");
            }
        }
    }
    return todoOk;
}

int ordenarMicros(eMicro micros[], int tam)
{
    int todoOk = 0;
    eMicro auxMicro;

    if(micros != NULL && tam > 0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if( (micros[i].idTipo > micros[j].idTipo) ||
                    (micros[i].idTipo == micros[j].idTipo &&
                     (micros[i].capacidad > micros[j].capacidad)))
                {
                    auxMicro = micros[i];
                    micros[i] = micros[j];
                    micros[j] = auxMicro;
                }
            }
        }

        todoOk=1;
    }

    return todoOk;
}

int cargarEmpresaMicro(eMicro micros[],int tam, int id, char empresaDesc[], eEmpresa empresa[], int tamE)
{
    int todoOk = 0;
    int flag = 1;
    if(micros != NULL && tam > 0 && empresaDesc != NULL)
    {
        todoOk = 1;
        for(int i=0; i<tam; i++)
        {
            if(micros[i].id == id)
            {
                cargarDescripcionEmpresa(empresa, tamE, micros[i].idEmpresa, empresaDesc);
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
