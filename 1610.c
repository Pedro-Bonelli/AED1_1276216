
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    int destino;
    struct cel *seg;
} aresta;

void push(int, aresta*);
int dfs(int, aresta**, int*);
void liberar(aresta*);

int main(){
    int t, n, m;
    int a, b;
    
    scanf("%d", &t);

    for (int caso = 0; caso < t; caso++){

        scanf("%d %d", &n, &m);

        aresta **grafo;
        grafo = malloc((n+1) * sizeof(aresta*));

        int *visitado;
        visitado = calloc(n+1, sizeof(int));

        for (int i = 1; i <= n; i++){
            grafo[i] = NULL;
        }

        for (int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);

            push(b, &grafo[a]);
        }

        int ciclo = 0;

        for (int i = 1; i <= n; i++){

            if (visitado[i] == 0){

                if (dfs(i, grafo, visitado) == 1){
                    ciclo = 1;
                    break;
                }

            }
        }

        if (ciclo == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

        for (int i = 1; i <= n; i++){
            liberar(grafo[i]);
        }

        free(grafo);
        free(visitado);
    }

    return 0;
}

void push(int destino_cad, aresta *cabeca){

    aresta *nova;
    nova = malloc(sizeof(aresta));

    nova->destino = destino_cad;

    nova->seg = cabeca->seg;
    cabeca->seg = nova;

}

int dfs(int atual, aresta **grafo, int *visitado){

    visitado[atual] = 1;

    aresta *aux;
    aux = grafo[atual];

    while (aux != NULL){

        int prox = aux->destino;

        if (visitado[prox] == 1){
            return 1;
        }

        if (visitado[prox] == 0){

            if (dfs(prox, grafo, visitado) == 1){
                return 1;
            }

        }

        aux = aux->seg;
    }

    visitado[atual] = 2;

    return 0;
}

void liberar(aresta *cabeca){

    aresta *aux;

    while (cabeca != NULL){

        aux = cabeca;
        cabeca = cabeca->seg;

    }

}
