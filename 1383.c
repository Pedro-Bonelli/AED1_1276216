/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Henrique Bonelli Silva
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 24/08/2026
Objetivo    : Verificar se o Sudoku está correto
Dificuldade : Os métodos de verificação e otimizar o código
Uso de IA   : Usei IA para validar a lógica de verificação
-------------------------------------------------------------------------- */

#include <stdio.h>

int VerificaLinha(int [][9]);
int VerificaColuna(int [][9]);
int VerificaQuadrante(int [][9]);

int main() {
    int n;
    int sudoku[9][9];
    
    scanf("%d", &n);
    
    for (int k = 1; k <= n; k++) {
        
        for (int i = 0; i < 9; i++) {         
            for (int j = 0; j < 9; j++) {     
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        int valido = VerificaLinha(sudoku);
        if(valido == 1){
            valido = VerificaColuna(sudoku);
        }  
        if(valido == 1){
            valido = VerificaQuadrante(sudoku);
        }

        printf("Instancia %d\n", k);
        if (valido == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        printf("\n"); 
    }
    
    return 0;
}

int VerificaLinha(int sudoku[9][9]){
    
        // Verificar as linhas
        for(int i = 0; i < 9; i++){
            int marca[10] = {0};

            for(int j = 0; j < 9; j++){
                int numero = sudoku[i][j];

                if(marca[numero] == 1){
                    return 0;
                }
                else {
                    marca[numero] = 1;
                }
            }
        }

        return 1;
}

int VerificaColuna(int sudoku[9][9]){
    for(int j = 0; j < 9; j++){
        int marca[10] = {0};

        for(int i = 0; i < 9; i++){
            int numero = sudoku[i][j];

            if(marca[numero] == 1){
                return 0;
            }
            else{
                marca[numero] = 1;
            }
        }
    }

    return 1;
}

int VerificaQuadrante(int sudoku[9][9]){
    for(int m = 0; m < 9; m+=3){
        for(int n = 0; n < 9; n+=3){
            int marca[10] = {0};

            for(int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++)
                {
                    int numero = sudoku[m + i][n + j];
                    if(marca[numero] == 1){
                        return 0;
                    }
                    else{
                        marca[numero] = 1;
                    }
                }
                
            }
        }
    }
    return 1;
}