#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[50];
    struct cel *seg;
} pessoa;

void entrar(char[], pessoa **inicio, pessoa **fim);
void mostrar(pessoa *inicio);

int main(){
    pessoa *inicio = NULL;
    pessoa *fim = NULL;

    char nome_temp[50];
    int n;

    printf("Quantas pessoas vao entrar na fila: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        printf("\nNome: ");
        fgets(nome_temp, sizeof(nome_temp), stdin);
        nome_temp[strcspn(nome_temp, "\n")] = '\0';

        entrar(nome_temp, &inicio, &fim);
    }

    mostrar(inicio);

    return 0;
}

void entrar(char nome_ins[], pessoa **inicio, pessoa **fim){
    pessoa *novo;

    novo = malloc(sizeof(pessoa));

    strcpy(novo->nome, nome_ins);
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

void mostrar(pessoa *inicio){
    pessoa *atual;
    atual = inicio;

    while(atual != NULL){
        printf("\n%s", atual->nome);
        atual = atual->seg;
    }
}