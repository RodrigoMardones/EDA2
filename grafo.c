#include "stdio.h"
#include "stdlib.h"

typedef struct Nodo {
    int destination;
    struct Nodo *next;
} nodo;

typedef struct ListNodo {
    struct Nodo *cabeza;
} listNodo;

typedef struct Grafo {
    int v;
    listNodo *array;
} grafo;

nodo* crearNodo(int destino){
    nodo* n = malloc(sizeof(nodo));
    n->destination = destino;
    n->next = NULL;
    return n;
}

grafo* crearGrafo(int v){
    grafo *g = malloc(sizeof(grafo));
    g->v = v;
    g->array = malloc(v * sizeof(listNodo));
    for(int i = 0; i < v; i++){
        g->array[i].cabeza = NULL;
    };
    return g;
}

void agregarArista(grafo *g, int fuente, int destino){
    nodo *nuevoNodo = crearNodo(destino);
    nuevoNodo->next = g->array[fuente].cabeza;
    g->array[fuente].cabeza = nuevoNodo;

    //como es indirecto apuntamos uno hacia el mismo
    nuevoNodo = crearNodo(fuente); 
    nuevoNodo->next = g->array[destino].cabeza; 
    g->array[destino].cabeza = nuevoNodo;
};


void mostrarGrafo(grafo *g){
    int v = g->v;
    for(int i = 0; i<v ; i++){
        nodo *actualNodo = g->array[i].cabeza;
        printf("lista de adjacencia de nodo %d ", i + 1);
        while(actualNodo){
            printf("-> %d ", actualNodo->destination + 1);
            actualNodo = actualNodo->next;
        }
        printf("\n");
    }
}

grafo *rellenarGrafo(){
    FILE *fptr;
    int v = 0;
    fptr = fopen("matriz.in", "r");  
    fscanf(fptr, "%i", &v);
    grafo *g = crearGrafo(v);
    int i,j;
    for(i = 0; i<v ; i++){
        for(j = 0;j<v;j++){
            int val = 0;
            fscanf(fptr, "%d", &val);
            if(i>j){
                if(val == 1){
                    agregarArista(g,i,j);
                }
            }
        }
    }
    fclose(fptr);
    return g;
}

int min(int a, int b){
    if (a >= b){
        return b;
    }
    return a;
};

void criticoProfundidad(int u, int *visitados, int *descubiertos, int *padre, int *pc, int *low, grafo *g, int *tiempo){
    
    nodo *adj = g->array[u].cabeza;

    int hijos = 0;
    visitados[u] = 1;
    descubiertos[u] = *tiempo;
    low[u] = *tiempo;
    *tiempo+=1;
    
    while(adj){
        int v = adj->destination;
        if(!visitados[v]){
    
            padre[v] = u;
            hijos+=1;
            criticoProfundidad(v, visitados, descubiertos, padre, pc, low, g, tiempo);
            
            low[u] = min(low[u], low[v]);
            // printf("valor más bajo de  %d \n", low[u]);
            
            if(padre[u] == -1 && hijos > 1){
                pc[u] = 1;
            }
            if(padre[u] != -1 && low[v] >= descubiertos[u]){
                pc[u] = 1;
            }
        }
        else{
            if(v != padre[u]){
                low[u] = min(low[u], descubiertos[v]);
            }
        }
        adj = adj->next;
    }
}

void puntoCritico(grafo *g){
    
    // se inicializan todos los elementos a usar
   
    int tiempo, *visitados, *descubiertos, *low, *padre, *pc;
    tiempo = 0;
    visitados = (int*)malloc(g->v * sizeof(int));
    descubiertos = (int*)malloc(g->v * sizeof(int));
    low = (int*)malloc(g->v * sizeof(int));
    padre = (int*)malloc(g->v * sizeof(int));
    pc = (int*)malloc(g->v * sizeof(int));
    
    // se llenan para limpiarlos de datos basura
    for(int i = 0; i < g->v; i++){
        padre[i] = -1;
        visitados[i] = 0;
        pc[i] = 0;
    }

    for(int j = 0;j < g->v;j++){
        if(visitados[j] == 0){
            criticoProfundidad(j, visitados, descubiertos, padre, pc, low, g, &tiempo);        
        }
    }
    
    for(int k = 0; k< g->v ; k++){
        if(pc[k]){
            printf("nodo critico: %d \n", k + 1);
        }
    }
}



