#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"
#define CANTIDAD_ARBOLES 100

struct ArbolE{
    char nombre[20];
    int edad;
    float altura;
};

Arbol crearArbol(char nombre[],int edad, float altura){
    Arbol arbol = malloc(sizeof(struct ArbolE));

    strcpy(arbol->nombre,nombre);
    arbol->edad = edad;
    arbol->altura = altura;

    return arbol;

}

void mostrarArbol(Arbol arbol){
    if(arbol->edad != -1){
        printf("\nNombre del arbol: %s",arbol->nombre);
        printf("\nEdad del arbol: %d",arbol->edad);
        printf("\nAltura del arbol: %.2f",arbol->altura);
    }
}

void cargarArboles(Arbol arboles[]){
        FILE * archivoArboles = fopen("arboles.txt","r");

        char datos[30] = "";

        int i=0;

        while((fgets(datos,30,archivoArboles)) && (i<CANTIDAD_ARBOLES)){

            arboles[i] = parsearArboles(datos);

            i++;

        }
}

Arbol parsearArboles(char datosSinParsear[30]){

    int posDelimitador = -1;
    int posDeSeglimitador = -1;
    char  nombreArbol[20] = "";
    char  edadArbol[5] = "";
    char  alturaArbol[5] = "";



    ///busca primer delimitador
    for(int i=0;i<30;i++){
        if(datosSinParsear[i] == '+'){
            posDelimitador = i;
            i=30;
        }
    }
    ///busca seg delimitador
    for(int i=posDelimitador+1;i<30;i++){
         if(datosSinParsear[i] == '+'){
            posDeSeglimitador = i;
            i=30;
    }
    for(int i=0;i<posDelimitador;i++){
        nombreArbol[i] = datosSinParsear[i];
    }
    for(int i=posDelimitador+1;i<posDeSeglimitador;i++){
        edadArbol[i-posDelimitador-1] = datosSinParsear[i];
    }
    for(int i=posDeSeglimitador+1;i<strlen(datosSinParsear);i++){
        alturaArbol[i-posDeSeglimitador-1] = datosSinParsear[i];
    }
}
return crearArbol(nombreArbol, atoi(edadArbol), atof(alturaArbol));

}

void inicializarArboles(Arbol arboles[]){
    for(int i=0;i<CANTIDAD_ARBOLES;i++){
        arboles[i] = crearArbol("",-1,-1);
    }
}
int buscarPosLibre(Arbol arboles[]){
    int posicion = -1;
    for(int i = 0;i<CANTIDAD_ARBOLES;i++){
        if(arboles[i]->edad == -1){
            posicion = i;

        }
    }return posicion;
}

void agregarArbol(Arbol arboles[]){
    int posLibre = buscarPosLibre(arboles);
    if(posLibre >0){
        arboles[posLibre] = crearArbolPorTeclado();
    }
}

Arbol crearArbolPorTeclado(){
    char nombre[25];
    int edad;
    float altura;

    printf("\nIngrese nombre del arbol: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese la edad del arbol: ");
    scanf("%d",&edad);

    printf("\nIngrese la altura del arbol: ");
    scanf("%f",&altura);

    return crearArbol(nombre,edad,altura);
}

void mostrarArboles(Arbol arboles[]){
    printf("\n\nMOSTRANDO ARBOLES ");
    for(int i=0;i<CANTIDAD_ARBOLES;i++){
        mostrarArbol(arboles[i]);
    }
}

void modificarArbol(Arbol arboles[], char nombreArbol[]){
    int encontrado = -1;
    printf("\n\nModificando arbol: \n");
    for(int i=0;i<CANTIDAD_ARBOLES;i++){
        if(strcmp(arboles[i]->nombre, nombreArbol)== 0){
            printf("\nIngrese edad: ");
            scanf("%d",&arboles[i]->edad);
            printf("\nIngrese altura: ");
            scanf("%f",&arboles[i]->altura);
            encontrado = 1;
            i=CANTIDAD_ARBOLES;

        }
    }
    if(encontrado == -1){
        printf("\nNO SE ENCONTRO ARBOL");
    }
}


void eliminarArbol(Arbol arboles[],char nombreArbol[]){
    for(int i=0;i<CANTIDAD_ARBOLES;i++){
        if(strcmp(arboles[i]->nombre, nombreArbol)==0){
            strcpy(arboles[i]->nombre,"");
            arboles[i]->edad = -1;
            arboles[i]->altura = -1.00;

            printf("\n\nArbol eliminado: %s",nombreArbol);
           }
    }
}

