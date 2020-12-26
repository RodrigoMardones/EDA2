#include "grafo.c"

/**
 * description - funcion que crea nodo/ vertice para grafo
 * @param destino entero destino dentro del nodo
 * @return *nodo nodo creado a partir del destino
*/
nodo* crearNodo(int destino);

/**
 * description - funcion que crea grafo vacio solo con vertices sin relaciones
 * @param v numero de vertices
 * @return *grafo grafo creado de manera correcta sin lista de adyacencia
*/
grafo* crearGrafo(int v);

/**
 * description - funcion que rellena un grafo desde un archivo entrada.in
 * @return *grafo grafo con sus respectivos vertices y lista de adyacencia
 */
grafo* rellenarGrafo();

/**
 * description - funcion que agrega una arista a a la matriz de adyacencia de un grafo
 * @param *g grafo a modificar
 * @param fuente entero de fuente 
 * @param destino entero de destino
*/
void agregarArista(grafo *g, int fuente, int destino);
/**
 * description - funcion que tiene como proposito mostrar el grafico
 * @param *g grafo a mostrar
*/
void mostrarGrafo(grafo *g);

/**
 * description - funcion que realiza una busqueda en profundiad de los puntos criticos de un nodo
 * @param u  vertice a buscar dentro del grafo para comprobar su visita y operar
 * @param visitados[v]  lista que almacena los vertices visitados por cantidad 
 * @param descubiertos[v]  lista que almacenas los vertices descubiertos de un vertice en especifico
 * @param padre[v]  lista que contiene los vertices padre de un arbol de busqueda profunda
 * @param bajo[v]  lista que contiene la conexion entre los subarboles generados con v dentro son parte de los ancestro de u
 * @param *g  grafo donde se hace la busqueda 
 * @param *tiempo cantidad de veces que se repite un elemento en la busqueda
*/
void criticoProfundidad(int u, int *visitados, int *descubiertos, int *padre, int *pc, int *low, grafo *g, int *tiempo);

/**
 * description funcion que ejecuta "crititoProfundidad" en toda la lista de adyacencia de un grafo
 * @param *g grafo donde se ejecutará la busqueda de el o los puntos criticos
*/
void puntoCritico(grafo *g);

/**
 * description - pequeña funcion que retorna el valor minimo de dos numeros
 * @param a  entero uno a comparar 
 * @param b  entero dos a comparar
 * @return int  entero minimo comparado
*/
int min(int a, int b);

