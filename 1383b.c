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

int VerificaLinha(int **sudoku);
int VerificaColuna(int **sudoku);
int VerificaQuadrante(int **sudoku);

int main() {
    int n;
    int **sudoku, linhas, colunas;
    
    scanf("%d", &n);
    
    for (int k = 1; k <= n; k++) {

        //Quantidade de linhas e colunas
    scanf("%d", &linhas);
    scanf("%d", &colunas);

    // Alocar as linhas
    sudoku = (int **) malloc(linhas * sizeof(int *));
    if(sudoku == NULL){
        printf("Erro de alocacao");
        return 1;
    }

    // Alocar colunas
    for(int i = 0; i < linhas; i++){
        sudoku[i] = (int *) malloc(colunas * sizeof(int));
        if (sudoku[i] == NULL){
            printf("Erro de Alocacao");
            return 1;
        }
    }
        
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

        for(int i = 0; i < linhas; i++){
            free(sudoku[i]);
        }
        free(sudoku);
    }
    
    return 0;
}

int VerificaLinha(int **sudoku){
    
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

int VerificaColuna(int **sudoku){
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

int VerificaQuadrante(int **sudoku){
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