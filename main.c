#include "stdio.h"
#include "grafo.h"

int main(){
    
    /* 

    // EJEMPLOS 
    grafo *g3 = crearGrafo(5);
    printf("primero \n");
    agregarArista(g3, 1, 0);
    agregarArista(g3,0, 2);
    agregarArista(g3,2, 1);
    agregarArista(g3,0, 3);
    agregarArista(g3,3, 4);
    puntoCritico(g3);
    printf("segundo \n");
    grafo *g4 = crearGrafo(4); 
    agregarArista(g4, 0, 1);
    agregarArista(g4, 1, 2);
    agregarArista(g4, 2, 3);
    puntoCritico(g4);
    printf("tercero \n");
    grafo *g2 = crearGrafo(7);
    agregarArista(g2, 0, 1);
    agregarArista(g2, 1, 2);
    agregarArista(g2, 2, 0);
    agregarArista(g2, 1, 3); 
    agregarArista(g2, 1, 4);
    agregarArista(g2, 1, 6);
    agregarArista(g2, 3, 5);
    agregarArista(g2, 4, 5);
    puntoCritico(g2);
    printf("cuarto \n"); */
    grafo *g1 = rellenarGrafo();
    puntoCritico(g1);
    printf("--------------------- \n");
    return 0;
}