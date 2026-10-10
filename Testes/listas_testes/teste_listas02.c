#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Célula para estrutura da lista de produtos
typedef struct cel{
    char nome[50];
    float preco;
    struct cel *seg;
} produto;

void push(char[], float, produto*);

int main(){
    produto cabeca;
    cabeca.seg = NULL;

    char nome_temp[50];
    float preco_temp;
    int n; // Quantidade de produtos para serem cadastrados

    printf("Quantos produtos irá cadastrar? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        printf("\n-- CADASTRO --\n");

        printf("Nome do produto: ");
        fgets(nome_temp, sizeof(nome_temp), stdin);
        nome_temp[strcspn(nome_temp, "\n")] = '\0';

        printf("Preço do produto: ");
        scanf("%f", &preco_temp);

        push(nome_temp, preco_temp, &cabeca);
    }
}

void push(char nome_cad[], float preco_cad, produto *cabeca){
    produto *novo;
    novo = malloc(sizeof(produto));

    strcpy(novo->nome, nome_cad);
    novo->preco = preco_cad;

    novo->seg = cabeca->seg;
    cabeca->seg = novo;
}