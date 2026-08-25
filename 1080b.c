/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Henrique Bonelli Silva
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/08/2026
Objetivo    : Ler 100 inteiros e printar o maior e sua posição.
Dificuldade : 
Uso de IA   : Não
-------------------------------------------------------------------------- */

#include <stdio.h>

int main(){
    int *v;
    int n;
    int maiorV, pos;
    
    scanf("%d", &n);

    v = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    maiorV = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maiorV){
            maiorV = v[i];
            pos = i + 1;
        }
    }

    printf("%d\n", maiorV);
    printf("%d\n", pos);
    
    return 0;
}