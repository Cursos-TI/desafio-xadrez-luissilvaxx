#include <stdio.h>

int main() {

    // ======== TORRE ========
    // Movimento: 5 casas para a direita
    // Estrutura de repetição: for
    int movimentoTorre = 5;
    printf("Movimento da Torre (for):\n");
    for (int i = 1; i <= movimentoTorre; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // ======== BISPO ========
    // Movimento: 5 casas na diagonal cima-direita
    // Estrutura de repetição: while
    int movimentoBispo = 5;
    int contadorBispo = 1;
    printf("Movimento do Bispo (while):\n");
    while (contadorBispo <= movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }
    printf("\n");

    // ======== RAINHA ========
    // Movimento: 8 casas para a esquerda
    // Estrutura de repetição: do-while
    int movimentoRainha = 8;
    int contadorRainha = 1;
    printf("Movimento da Rainha (do-while):\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= movimentoRainha);

    return 0;
}