#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int x;
    struct cel *seg;
} fila;

void push(int, fila**);
void pop(fila *, fila **fim);

int main(){
    fila *inicio = malloc(sizeof(fila));
    inicio->seg = NULL;

    fila *fim = inicio;

    push(valor, &fim);
    pop(inicio, &fim);
}

void push(int x_valor, fila **fim){
    fila *novo;
    novo = malloc(sizeof(fila));

    novo->x = x_valor;
    novo->seg = NULL;

    (*fim)->seg = novo;
    *fim = novo;
}

void pop(fila *inicio, fila **fim){
    if(inicio->seg == NULL){
        printf("Vazia");
        return;
    }

    fila *remover;
    remover = inicio->seg;
    inicio->seg = remover->seg;

    if(inicio->seg = NULL){
        *fim = inicio;
    }

    free(remover);
}
