#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Listas globais dinâmicas
char** nomes = NULL;
float* precoCompra = NULL;
float* precoVenda = NULL;
int* qtdCompra = NULL;
int* qtdVenda = NULL;

int quantidade = 0;

void adicionarFruta() {
    // Realocando espaço para mais uma fruta
    nomes = realloc(nomes, (quantidade + 1) * sizeof(char*));
    precoCompra = realloc(precoCompra, (quantidade + 1) * sizeof(float));
    precoVenda = realloc(precoVenda, (quantidade + 1) * sizeof(float));
    qtdCompra = realloc(qtdCompra, (quantidade + 1) * sizeof(int));
    qtdVenda = realloc(qtdVenda, (quantidade + 1) * sizeof(int));

    // Alocando espaço para o nome da fruta
    nomes[quantidade] = malloc(30 * sizeof(char));

    printf("Nome da fruta: ");
    scanf("%s", nomes[quantidade]);

    printf("Preço de compra: ");
    scanf("%f", &precoCompra[quantidade]);

    printf("Preço de venda: ");
    scanf("%f", &precoVenda[quantidade]);

    printf("Quantidade comprada: ");
    scanf("%d", &qtdCompra[quantidade]);

    printf("Quantidade vendida: ");
    scanf("%d", &qtdVenda[quantidade]);

    quantidade++;
}

void listarFrutas() {
    printf("\n--- Lista de Frutas ---\n");
    for (int i = 0; i < quantidade; i++) {
        int estoque = qtdCompra[i] - qtdVenda[i];
        float lucro = (precoVenda[i] * qtdVenda[i]) - (precoCompra[i] * qtdCompra[i]);

        printf("Fruta: %s\n", nomes[i]);
        printf("Estoque atual: %d\n", estoque);
        printf("Lucro/Prejuízo: R$ %.2f\n\n", lucro);
    }
}

void liberarMemoria() {
    for (int i = 0; i < quantidade; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(precoCompra);
    free(precoVenda);
    free(qtdCompra);
    free(qtdVenda);
}

int main() {
    int opcao = 0;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1 - Adicionar Fruta\n");
        printf("2 - Listar Frutas\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
            adicionarFruta();
        else if (opcao == 2)
            listarFrutas();
        else if (opcao == 3)
            break;
        else
            printf("Opção inválida.\n");
    }

    liberarMemoria(); // Libera memória alocada dinamicamente
    return 0;
}
