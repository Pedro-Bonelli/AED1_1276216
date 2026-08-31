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

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        int f[100]; 
        int s = 0, t = 0; 

        for (int i = 1; i <= n; i++) {
            f[t++] = i; 
        }

        printf("Discarded cards:");
        int primeira_carta = 1;

        while ((t - s) >= 2) {
            int descartada = f[s++]; 
            
            if (primeira_carta) {
                printf(" %d", descartada);
                primeira_carta = 0;
            } else {
                printf(", %d", descartada);
            }

            int topo_para_fundo = f[s++]; 
            f[t++] = topo_para_fundo;     
        }

        printf("\nRemaining card: %d\n", f[s]);
    }

    return 0;
}