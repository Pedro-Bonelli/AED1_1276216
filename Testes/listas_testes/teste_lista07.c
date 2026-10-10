#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char acao[60];
    struct cel *seg;
} acao;

void push(char[], acao*);
void pop(acao*);
void show(acao*);

int main(){
    acao cabeca;
    cabeca.seg = NULL;

    char acao_temp[60];
    int n, n2;

    printf("\nQuantas acoes serao feitas: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        printf("\nAcao: ");
        fgets(acao_temp, sizeof(acao_temp), stdin);
        acao_temp[strcspn(acao_temp, "\n")] = '\0';

        push(acao_temp, &cabeca);
    }

    printf("\nQuer retirar quantas acoes: ");
    scanf("%d", &n2);
    while(n2 > n){
        printf("\nQuer retirar quantas acoes: ");
        scanf("%d", n2);
        getchar();
    }

    for(int i = 0; i < n2; i++){
        pop(&cabeca);
    }

    show(&cabeca);
}

void push(char acao_ins[], acao *cabeca){
    acao *nova;
    nova = malloc(sizeof(acao));

    strcpy(nova->acao, acao_ins);

    nova->seg = cabeca->seg;
    cabeca->seg = nova;
}

void pop(acao *cabeca){
    acao *remover;
    if(cabeca->seg != NULL){
        printf("Lista vazia");
        return;
    }

    remover = cabeca->seg;
    cabeca->seg = remover->seg;
    free(remover);
}

void show(acao *cabeca){
    acao *atual;
    atual = cabeca->seg;

    while(atual != NULL){
        printf("\nAcao: %s", atual->acao);
        atual = atual->seg;
    }
}