#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char comando[60];
    int codigo;
    struct cel *seg;
} comando;

void push(char[], int, comando*);
void pop(comando*);

int main(){
    comando cabeca;
    cabeca.seg = NULL;

    char comando_temp[60];
    int codigo_temp;
    int n;

    printf("N: ");
    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++){
        printf("\nCadastro");

        printf("\nComando: ");
        fgets(comando_temp, sizeof(comando_temp), stdin);
        comando_temp[strcspn(comando_temp, "\n")] = '\0';

        printf("\nCodigo: ");
        scanf("%d", &codigo_temp);

        push(comando_temp, codigo_temp, &cabeca);
    }
}

void push(char comando_ins[], int codigo_ins, comando *cabeca){
    comando *novo;
    novo = malloc(sizeof(comando));

    strcpy(novo->comando, comando_ins);
    novo->codigo = codigo_ins;

    novo->seg = cabeca->seg;
    cabeca->seg = novo;
}

void pop(comando *cabeca){
    comando *remover;
    if(cabeca->seg == NULL){
        printf("\nLista vazia");
        return;
    }
    remover = cabeca->seg;

    cabeca->seg = remover->seg;
    free(remover);
}