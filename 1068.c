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
#include <string.h>

int main() {
    char exp[1005];

    while (scanf("%s", exp) != EOF) {
        int t = 0; // t representa o topo da pilha
        int erro = 0;

        for (int i = 0; exp[i] != '\0'; i++) {
            if (exp[i] == '(') {
                t++; // empilha[cite: 1]
            } 
            else if (exp[i] == ')') {
                if (t != 0) {
                    --t; // desempilha se houver par correspondente
                } else {
                    erro = 1;
                    break;
                }
            }
        }

        if (erro == 0 && t == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}