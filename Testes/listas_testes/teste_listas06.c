#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char tarefa[20];
    char descricao[100];
    int prioridade;
    struct cel *seg;
} tarefa;

void push(char[], char[], int, tarefa*);
void pop(tarefa*);
void show(tarefa*);

int main(){
    tarefa cabeca;
    cabeca.seg = NULL;

    char tarefa_temp[20];
    char descricao_temp[100];
    int prioridade_temp;
    int n, n2;

    printf("Quantas tarefas quer adicionar: ");
    scanf("%d", &n);
    getchar();

    printf("\nLista de tarefas: ");
    for(int i = 0; i < n; i++){
        printf("\nTarefa: ");
        fgets(tarefa_temp, sizeof(tarefa_temp),stdin);
        tarefa_temp[strcspn(tarefa_temp, "\n")] = '\0';

        printf("\nDescricao: ");
        fgets(descricao_temp, sizeof(descricao_temp), stdin);
        descricao_temp[strcspn(descricao_temp, "\n")] = '\0';
        
        printf("\nPrioridade (0/10): ");
        scanf("%d", &prioridade_temp);
        getchar();

        push(tarefa_temp, descricao_temp, prioridade_temp, &cabeca);
    }

    printf("\nQuantas tarefas deseja remover: ");
    scanf("%d", &n2);

    for(int i = 0; i < n2; i++){
        pop(&cabeca);
    }

    show(&cabeca);
}

void push(char tarefa_ins[], char descricao_ins[], int prioridade_ins, tarefa *cabeca){
    tarefa *nova;
    nova = malloc(sizeof(tarefa));

    strcpy(nova->tarefa, tarefa_ins);
    strcpy(nova->descricao, descricao_ins);
    nova->prioridade = prioridade_ins;

    nova->seg = cabeca->seg;
    cabeca->seg = nova;
}

void pop(tarefa *cabeca){
    tarefa *remover;
    if(cabeca->seg == NULL){
        printf("\nLista vazia");
        return;
    }

    remover = cabeca->seg;
    cabeca->seg = remover->seg;

    free(remover);
}

void show(tarefa *cabeca){
    tarefa *atual;
    atual = cabeca->seg;

    while(atual != NULL){
        printf("\nTarefa: %s", atual->tarefa);
        printf("\nDescricao: %s", atual->descricao);
        printf("\nPrioridade: %d", atual->prioridade);

        atual = atual->seg;
    }
}