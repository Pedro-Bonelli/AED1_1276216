/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Henrique Bonelli Silva
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 24/08/2026
Objetivo    : Organizar as cartas
Dificuldade : 
Uso de IA   : Para ajudar a montar a lógica de pushs e pops
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int carta;
    struct cel *seg;
} baralho;

void push(int, baralho **, baralho **);
int pop(baralho **, baralho **);

int main(){
    baralho *inicio = NULL;
    baralho *fim = NULL;

    int n, m, carta_temp, *descarte, remansc;
    printf("\nN: ");
    scanf("%d", &n);

    m = n;

    for(int i = 0; i < n; i++){
        printf("\nCarta: ");
        scanf("%d", &carta_temp);

        push(carta_temp, &inicio, &fim);
    }

    descarte = (int *) malloc((n-1)*sizeof(int));

    while(n > 1){
        descarte[n-2] = pop(&inicio, &fim);
        remansc = pop(&inicio, &fim);
        push(remansc, &inicio, &fim);

        n = n-1;
    }

    printf("\n\n");
    for(int i = m - 2; i >= 0; i--){
        printf("Descartes: %d\t", descarte[i]);
    }

    printf("\nRestante: %d", remansc);

}

void push(int carta_ins, baralho **inicio, baralho **fim){
    baralho *nova;
    nova = malloc(sizeof(baralho));

    nova->carta = carta_ins;
    nova->seg = NULL;

    if(*inicio == NULL){
        *inicio = nova;
        *fim = nova;
    }
    else{
        (*fim)->seg = nova;
        *fim = nova;
    }
}

int pop(baralho **inicio, baralho **fim){
    baralho *remover;
    int aux;
    remover = *inicio; 

    aux = remover->carta;
    *inicio = remover->seg;
    free(remover);

    if(*inicio == NULL){
        *fim = NULL;
    }
    return aux;
}
