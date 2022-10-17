#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#define CANTIDAD_ARBOLES 100


int main()
{
    Arbol arboles[CANTIDAD_ARBOLES];

    inicializarArboles(arboles);
    cargarArboles(arboles);
    agregarArbol(arboles);
    agregarArbol(arboles);
    agregarArbol(arboles);
    mostrarArboles(arboles);
    modificarArbol(arboles,"Laurel");
    mostrarArboles(arboles);
    eliminarArbol(arboles,"Laurel");
    mostrarArboles(arboles);



    return 0;
}
