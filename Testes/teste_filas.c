#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[50];
    int idade;
    struct cel *seg;
} pessoa;

void push(char[], int, pessoa*);
void imprimir(pessoa*);

int main(){
    pessoa cabeca;
    cabeca.seg = NULL;

    int n, idade_temp;
    char nome_temp[50];
    int opc;
    
    printf("Quantas pessoas quer cadastrar: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        printf("\n----- Cadastro %d -----\n", i+1);

        printf("\nDigite o nome: ", i+1);
        fgets(nome_temp, sizeof(nome_temp), stdin);
        nome_temp[strcspn(nome_temp, "\n")] = '\0';

        printf("\nDigite a idade: ");
        scanf("%d", &idade_temp);

        push(nome_temp, idade_temp, &cabeca);
    }

    printf("\nQuer visualizar os cadastros: ");
    scanf("%d", &opc);
    while (opc == 1)
    {
        imprimir(&cabeca);
    }
    

}

void push(char nome_cad[], int idade_cad, pessoa *cabeca){
    pessoa *nova;
    nova = malloc(sizeof(pessoa));

    strcpy(nova->nome, nome_cad);
    nova->idade = idade_cad;

    nova->seg = cabeca->seg;
    cabeca->seg = nova;

}