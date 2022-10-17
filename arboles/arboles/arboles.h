#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED


struct ArbolE;
typedef struct ArbolE * Arbol;

Arbol crearArbol(char nombre[],int edad, float altura);

void cargarArboles(Arbol arboles[]);

Arbol parsearArboles(char datosSinParsear[30]);

void mostrarArbol(Arbol arbol);

void inicializarArboles(Arbol arboles[]);

int buscarPosLibre(Arbol arboles[]);

void agregarArbol(Arbol arboles[]);

Arbol crearArbolPorTeclado();

void mostrarArboles(Arbol arboles[]);

void modificarArbol(Arbol arboles[], char nombreArbol[]);

void eliminarArbol(Arbol arboles[],char nombreArbol[]);
#endif // ARBOLES_H_INCLUDED
