#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel{
    char titulo[50];
    int ano;
    float preco;
    struct cel *seg;
} Jogo;

void push(char[], int, float, Jogo*);

int main(){
    Jogo cabeca;
    cabeca.seg = NULL;

    char titulo_temp[50];
    int ano_temp;
    float preco_temp;

    int n;

    printf("\nQuantos jogos serao cadastrados: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        printf("\n--Cadastro--\n");

        printf("\nDigite o titulo do jogo: ");
        fgets(titulo_temp, sizeof(titulo_temp), stdin);
        titulo_temp[strcspn(titulo_temp, "\n")] = '\0';

        printf("\nDigite o ano de lancamento: ");
        scanf("%d", &ano_temp);
        getchar();

        printf("\nDigite o preco do jogo: ");
        scanf("%f", &preco_temp);

        push(titulo_temp, ano_temp, preco_temp, &cabeca);
    }
}

void push(char titulo_ins[], int ano_ins, float preco_ins, Jogo *cabeca){
    Jogo *novo;
    novo = malloc(sizeof(Jogo));

    strcpy(novo->titulo, titulo_ins);
    novo->ano = ano_ins;
    novo->preco = preco_ins;

    novo->seg = cabeca->seg;
    cabeca->seg = novo;
}