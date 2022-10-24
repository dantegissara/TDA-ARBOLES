#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#include <string.h>

#define CANTIDAD_ARBOLES 100
#define CADENA_SIN_PARSEAR 30
struct ArbolE{
    char nombre[25];
    int edad;
    float altura;
};

/*---------------
 | Constructores
 ----------------*/

Arbol crearArbol(char nombre[],int edad,float altura){
    Arbol arbol = malloc(sizeof(struct ArbolE));

    strcpy(arbol->nombre,nombre);
    arbol->edad = edad;
    arbol->altura = altura;

    return arbol;


}
Arbol crearArbolPorTeclado(){
    char nombre[25];
    int edad;
    float altura;

    printf("\nIngrese nombre del arbol: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese la edad de \"%s\": ", nombre);
    scanf("%d", &edad);

    printf("\nIngrese la altura para \"%s\": ", nombre);
    scanf("%f", &altura);

    return crearArbol(nombre, edad, altura);


}

/*-----------------------------
 | Procedimientos individuales
 -----------------------------*/

 int buscarPosicionLibre(Arbol arboles[]){
     int posicionLibre = -1;
    for(int i = 0; i<CANTIDAD_ARBOLES;i++){
        if(arboles[i]->edad == -1){
            posicionLibre = i;
            i=CANTIDAD_ARBOLES;
        }
    }
    return posicionLibre;
}

 void mostrarArbol(Arbol arbol){
    //si el arbol es no filtrable
    if(arbol->edad != -1){
        printf("\nArbol:");
        printf("\nNombre: %s",arbol->nombre);
        printf("\nEdad: %d",arbol->edad);
        printf("\nAltura: %.2f",arbol->altura);

    }
 }


 void agregarArbol(Arbol arboles[]){
    int posicionLibre = buscarPosicionLibre(arboles);
    if(posicionLibre != -1){
        arboles[posicionLibre]=crearArbolPorTeclado();
    }

 }


 void modificarArbol(Arbol arboles[],char nombreArbol[]){
    int encontrado = -1;
    printf("\n\nModificando arbol: %s\n",nombreArbol);
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

    for(int i = 0; i<CANTIDAD_ARBOLES;i++){
        if(strcmp(arboles[i]->nombre,nombreArbol)==0){
            strcpy(arboles[i]->nombre,"");
            arboles[i]->edad = -1;
            arboles[i]->altura = -1.00;

            printf("\n\nArbol eliminado: %s",nombreArbol);
        }
    }
 }

 /*---------------------------
 | Procedimientos de arreglo
 ----------------------------*/

void inicializarArboles(Arbol arboles[]){
    for(int i = 0;i<100;i++){
        arboles[i] = crearArbol("",-1,-1.00);
    }
}

void mostrarArboles(Arbol arboles[])
{
    for(int i = 0; i < 100; i++)
    {
        mostrarArbol(arboles[i]);
    }
}

void agregarArboles(Arbol arboles[]){
    for(int i = 0;i<CANTIDAD_ARBOLES;i++){
        agregarArbol(arboles);
    }
}

/*---------------------------
 | Procedimientos de archivo
 ----------------------------*/
void guardarArboles(Arbol arboles[]){

    FILE * archivoArboles = fopen("arboles.txt", "a");

    if(archivoArboles != NULL)
    {
        for(int i = 0; i < CANTIDAD_ARBOLES; i++)
        {
            // Si el arbol es 'no-filtrable'
            if(arboles[i]->edad != -1)
            {
                fprintf(
                    archivoArboles,
                    "%s+%d+%.2f\n",
                    arboles[i]->nombre,
                    arboles[i]->edad,
                    arboles[i]->altura
                );
            }
        }
    }
    fclose(archivoArboles);
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

void cargarArboles(Arbol arboles[])
 {
    FILE * archivoArboles = fopen("arboles.txt", "r");

    char datos[30] = "";

    int i = 0;

    while((fgets(datos, CADENA_SIN_PARSEAR, archivoArboles)) && (i < CANTIDAD_ARBOLES))
    {
        arboles[i] = parsearArboles(datos);
        i++;
    }

    fclose(archivoArboles);

}
