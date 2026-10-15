#include <stdio.h>

int busca_binaria(int v[], int tamanho, int valor){
    int inicio = 0; 
    int fim = tamanho - 1;
    int meio;

    while(inicio <= fim){
        meio = inicio + (fim - inicio)/2;

        if(v[meio] == x){
            return meio;
        }

        if(x > v[meio]){
            inicio = meio + 1;
        }
        else{
            fim = meio -1;
        }
    }
}

int main(void) {
    int v[] = {2, 5, 9, 12, 18, 25, 30};
    int x = 25;

    int posicao = busca_binaria(v, 7, x);

    if (posicao == -1) {
        printf("Valor nao encontrado.\n");
    } else {
        printf("Valor encontrado no indice %d.\n", posicao);
    }

    return 0;
}