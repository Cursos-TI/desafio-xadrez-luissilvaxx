#include <stdio.h>

int main() {

    // ======== TORRE ========
    int movimentoTorre = 5;
    printf("Movimento da Torre (for):\n");
    for (int i = 1; i <= movimentoTorre; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // ======== BISPO ========
    int movimentoBispo = 5;
    int contadorBispo = 1;
    printf("Movimento do Bispo (while):\n");
    while (contadorBispo <= movimentoBispo) {
        printf("Cima Direita\n");
        contadorBispo++;
    }
    printf("\n");

    // ======== RAINHA ========
    int movimentoRainha = 8;
    int contadorRainha = 1;
    printf("Movimento da Rainha (do-while):\n");
    do {
        printf("Esquerda\n");
        contadorRainha++;
    } while (contadorRainha <= movimentoRainha);

    // ======== CAVALO ========
    // Movimento: 2 para baixo e 1 para a esquerda (em "L")
    // Loops aninhados: um for obrigatório + um while
    int passosBaixo = 2;
    int passosEsquerda = 1;

    printf("\nMovimento do Cavalo (for + while):\n");

    // Primeiro movimento: 2 casas para baixo (loop externo for)
    for (int i = 1; i <= passosBaixo; i++) {
        printf("Baixo\n");
    }

    // Depois 1 casa para a esquerda (loop interno while)
    int contadorEsquerda = 1;
    while (contadorEsquerda <= passosEsquerda) {
        printf("Esquerda\n");
        contadorEsquerda++;
    }

    return 0;
}

