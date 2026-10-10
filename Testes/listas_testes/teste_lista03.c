#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[50];
    float nota;
    struct cel *seg;
} aluno;

void push(char[], float, aluno*);

int main(){
    aluno cabeca;
    cabeca.seg = NULL;

    char nome_temp[50];
    float nota_temp;
    int n;

    printf("\nQuantos alunos serao cadastrados: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        printf("\n--Cadastro--");

        printf("Nome do aluno: ");
        fgets(nome_temp, sizeof(nome_temp), stdin);
        nome_temp[strcspn(nome_temp, "\n")] = '\0';

        printf("Nota: ");
        scanf("%f", &nota_temp);

        push(nome_temp, nota_temp, &cabeca);
    }
}

void push(char nome_ins[], float nota_ins, aluno *cabeca){
    aluno *novo;
    novo = malloc(sizeof(aluno));

    strcpy(novo->nome, nome_ins);
    novo->nota = nota_ins;

    novo->seg = cabeca->seg;
    cabeca->seg = novo;
}