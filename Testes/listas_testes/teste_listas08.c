#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char materia[50];
    int aulas;
    int faltas;
    float nota;
    char professor[20];
    struct cel *seg;
} semestre;

void push(char[], int, int, float, char[], semestre*);
void pop(semestre*);
void show(semestre*);
void search(semestre*, char[]);

int main(){
    semestre cabeca;
    cabeca.seg = NULL;

    char materia_temp[50], professor_temp[20];
    int aulas_temp, faltas_temp;
    float nota_temp;

    int n;
    char opc, materia_busca[50];

    printf("\nQuantas materias ira cadastrar: ");
    scanf("%d", &n);
    getchar();

    printf("\nCadastro: ");
    for (int i = 0; i < n; i++){
        printf("\nMateria: ");
        fgets(materia_temp, sizeof(materia_temp), stdin);
        materia_temp[strcspn(materia_temp, "\n")] = '\0';

        printf("\nAulas: ");
        scanf("%d", &aulas_temp);
        getchar();

        printf("\nFaltas: ");
        scanf("%d", &faltas_temp);
        getchar();

        printf("\nNota: ");
        scanf("%f", &nota_temp);
        getchar();

        printf("\nProfessor: ");
        fgets(professor_temp, sizeof(professor_temp), stdin);
        professor_temp[strcspn(professor_temp, "\n")] = '\0';

        push(materia_temp, aulas_temp, faltas_temp, nota_temp, professor_temp, &cabeca);
    }

    show(&cabeca);

    printf("\nQuer remover ou buscar materias? (R/B): ");
    scanf(" %c", &opc);
    getchar();
    while (opc != 'R' && opc != 'r' && opc != 'B' && opc != 'b')
    {
        printf("\nDigite (R/B): ");
        scanf(" %c", &opc);
        getchar();
    }

    if(opc == 'b' || opc == 'B'){
        printf("\nMateria: ");
        fgets(materia_busca, sizeof(materia_busca), stdin);
        materia_busca[strcspn(materia_busca, "\n")] = '\0';
    }

    switch (opc)
    {
    case 'R':
    case 'r':
        pop(&cabeca);
        show(&cabeca);
        break;
    case 'B':
    case 'b':
        search(&cabeca, materia_busca);
        break;
    default:
        break;
    }
    

    return 0;
}

void push(char materia_ins[], int aulas_ins, int faltas_ins, float nota_ins, char professor_ins[], semestre *cabeca){
    semestre *novo;
    novo = malloc(sizeof(semestre));

    strcpy(novo->materia, materia_ins);
    novo->aulas = aulas_ins;
    novo->faltas = faltas_ins;
    novo->nota = nota_ins;
    strcpy(novo->professor, professor_ins);

    novo->seg = cabeca->seg;
    cabeca->seg = novo;
}

void pop(semestre *cabeca){
    semestre *remover;
    if(cabeca->seg == NULL){
        printf("\nLista Vazia");
        return;
    }

    remover = cabeca->seg;
    cabeca->seg = remover->seg;
    free(remover);
}

void show(semestre *cabeca){
    semestre *atual;
    atual = cabeca->seg;

    while(atual != NULL){
        printf("\nMateria: %s", atual->materia);
        printf("\nAulas: %d", atual->aulas);
        printf("\nFaltas: %d", atual->faltas);
        printf("\nNota: %f", atual->nota);
        printf("\nProfessor: %s", atual->professor);

        printf("\n\n--------------");

        atual = atual->seg;
    }
}

void search(semestre *cabeca, char materia_busca_ins[]){
    semestre *atual;
    atual = cabeca->seg;

    while(atual != NULL){
        if(strcmp(atual->materia, materia_busca_ins) == 0){
            printf("\nMateria encontrada!\n");
            printf("\nMateria: %s", atual->materia);
            printf("\nAulas: %d", atual->aulas);
            printf("\nFaltas: %d", atual->faltas);
            printf("\nNota: %f", atual->nota);
            printf("\nProfessor: %s", atual->professor);
            return;
        }

        atual = atual->seg;
    }

    printf("\nMateria nao encontrada!");
}