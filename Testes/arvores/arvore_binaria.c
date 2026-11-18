#include <stdio.h>

typedef struct cel {
    int conteudo;
    struct cel *esq;
    struct cel *dir;
} no;

typedef no *arvore;

void imprimir(arvore r);

int main(void) {
    no a = {25, NULL, NULL};
    no b = {10, NULL, NULL};
    no c = {40, NULL, NULL};
    no d = {5,  NULL, NULL};
    no e = {18, NULL, NULL};
    no f = {15, NULL, NULL};
    no g = {35, NULL, NULL};
    no h = {50, NULL, NULL};

    a.esq = &b;
    a.dir = &c;

    b.esq = &d;
    b.dir = &e;

    e.esq = &f;

    c.esq = &g;
    c.dir = &h;

    arvore raiz = &a;

    printf("Arvore inteira: ");
    imprimir(raiz);
    printf("\n");

    printf("Subarvore esquerda: ");
    imprimir(raiz->esq);
    printf("\n");

    printf("Arvore vazia: ");
    imprimir(NULL);
    printf("\n");

    return 0;
}

void imprimir(arvore r) {
    if(r != NULL){
        imprimir(r->esq);
        printf("%d\t", r->conteudo);
        imprimir(r->dir);
    }
}