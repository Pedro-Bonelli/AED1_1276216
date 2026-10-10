#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[50];
    int idade;
    struct cel *seg;
} pessoa;

void inserir(char[], int, pessoa**, pessoa**);
void mostrar(pessoa*);

int main(){
    pessoa *inicio;
    pessoa *fim;

    inicio->seg = NULL;
    fim->seg = NULL;

    char nome_temp[50];
    int idade_temp, n;

    printf("Quantas pessoas pra fila: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        printf("\nNome: ");
        fgets(nome_temp, sizeof(nome_temp), stdin);
        nome_temp[strcspn(nome_temp, "\n")] = '\0';

        printf("\nIdade: ");
        scanf("%d", &idade_temp);
        getchar();

        inserir(nome_temp, idade_temp, &inicio, &fim);
    }
}

void inserir(char nome_ins[], int idade_ins, pessoa **inicio, pessoa **fim){
    pessoa *nova;
    nova = malloc(sizeof(pessoa));

    strcpy(nova->nome, nome_ins);
    nova->idade = idade_ins;

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