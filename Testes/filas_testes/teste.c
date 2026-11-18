#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *seg;
} fila;

void push(int, fila**, fila**);
void pop(fila**, fila**);

int main(){
    fila *inicio = NULL;
    fila *fim = NULL;

    ...
    push(x_temp, &inicio, &fim);
    pop(&inicio, &fim);
}

void push(int x, fila **inicio, fila **fim){
    fila *novo;
    novo = malloc(sizeof(fila));

    novo->valor = x;
    novo->seg = NULL;

    if(*inicio == NULL){
        *inicio = novo;
        *fim = novo;
    }
    else{
        (*fim)->seg = novo;
        *fim = novo;
    }
}

void pop(fila **inicio, fila **fim){
    fila *remover;
    if(*inicio == NULL){
        printf("Vazia");
        return;
    }

    remover = *inicio;
    *inicio = remover->seg;
    free(remover);

    if(*inicio == NULL){
        *fim = NULL;
    }
}