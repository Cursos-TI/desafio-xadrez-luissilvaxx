#include <stdio.h>

/*
  ===========================================
  XADREZ — Nível Mestre: Movimentos Complexos
  - Torre, Bispo, Rainha: recursividade
  - Cavalo: loops aninhados com múltiplas condições, continue/break
  - Bispo: cada passo diagonal impresso por loops aninhados
           (externo = vertical, interno = horizontal)
  Notas:
  - Apenas inteiros e strings.
  - Saídas padronizadas: "Cima", "Baixo", "Esquerda", "Direita".
  - Linhas em branco separam as peças.
  ===========================================
*/

/* =========================
   Funções recursivas
   ========================= */

// Torre: mover N casas para a Direita (exemplo do enunciado anterior)
void moverTorreRec(int restantes) {
    if (restantes <= 0) return;            // caso base
    printf("Direita\n");                    // ação desta "casa"
    moverTorreRec(restantes - 1);           // passo recursivo
}

// Rainha: mover N casas para a Esquerda
void moverRainhaRec(int restantes) {
    if (restantes <= 0) return;
    printf("Esquerda\n");
    moverRainhaRec(restantes - 1);
}

/*
  Bispo (diagonal para cima e direita):
  - Recursivo para os passos.
  - Em CADA passo, usamos loops aninhados:
    * loop externo: movimento vertical ("Cima")
    * loop interno: movimento horizontal ("Direita")
  Isso satisfaz a exigência de recursividade + loops aninhados.
*/
void imprimirPassoBispoComLoops(void) {
    // Externo (vertical)
    for (int v = 0; v < 1; v++) {
        printf("Cima\n");
        // Interno (horizontal)
        for (int h = 0; h < 1; h++) {
            printf("Direita\n");
        }
    }
}
void moverBispoRec(int restantes) {
    if (restantes <= 0) return;
    imprimirPassoBispoComLoops();
    moverBispoRec(restantes - 1);
}

/* =========================
   Cavalo — loops aninhados “complexos”
   Movimento pedido: duas casas para CIMA e uma para a DIREITA.
   Requisitos:
   - loops aninhados, múltiplas variáveis/condições
   - usar continue e break
   Estratégia:
   - Controlamos três “passos” no total.
   - Variáveis u (fez movimentos para cima) e r (fez movimentos para direita).
   - Loop externo controla a sequência; interno decide imprimir "Cima" ou "Direita".
*/
void moverCavaloComplexo(void) {
    int subirNecessario = 2;   // duas para cima
    int direitaNecessaria = 1; // uma para a direita

    int u = 0; // quantos "Cima" já fiz
    int r = 0; // quantos "Direita" já fiz

    printf("\nMovimento do Cavalo (loops aninhados com condições):\n");

    // Loop externo com múltiplas variáveis no cabeçalho
    for (int passo = 1; passo <= (subirNecessario + direitaNecessaria); passo++) {

        // Loop interno decide qual direção imprimir neste "passo"
        // tentativa = 0 tenta vertical primeiro; tentativa = 1 tenta horizontal depois
        for (int tentativa = 0; tentativa < 2; tentativa++) {

            // Se ainda faltam movimentos para CIMA, priorize-os
            if (tentativa == 0) {
                if (u < subirNecessario) {
                    printf("Cima\n");
                    u++;
                    // Já imprimimos algo neste passo, siga para o próximo passo externo
                    break;
                } else {
                    // Nada a fazer verticalmente; tente horizontal no mesmo passo
                    continue; // volta ao loop interno (tentativa == 1)
                }
            }

            // tentativa == 1: agora verificamos a DIREITA
            if (r < direitaNecessaria) {
                // Só move para a direita quando já cumpriu os dois "Cima"
                if (u >= subirNecessario) {
                    printf("Direita\n");
                    r++;
                    break; // concluímos este passo
                } else {
                    // Ainda não cumpriu os "Cima"; ignora e volta para o próximo passo
                    break;
                }
            }

            // Se chegou aqui, não há mais o que imprimir neste passo
        }

        // Se já concluí todos os movimentos, encerro antecipadamente
        if (u >= subirNecessario && r >= direitaNecessaria) {
            break; // uso de break para controle de fluxo
        }
    }
}

/* =========================
   Programa principal
   ========================= */
int main(void) {
    // Parâmetros (definidos no código, como pedido)
    int passosTorre   = 5; // Direita
    int passosBispo   = 5; // Cima + Direita (diagonal)
    int passosRainha  = 8; // Esquerda

    // --- TORRE (recursivo) ---
    printf("Movimento da Torre (recursivo):\n");
    moverTorreRec(passosTorre);

    // linha em branco separando peças
    printf("\n");

    // --- BISPO (recursivo + loops aninhados em cada passo) ---
    printf("Movimento do Bispo (recursivo + loops aninhados):\n");
    moverBispoRec(passosBispo);

    // linha em branco
    printf("\n");

    // --- RAINHA (recursivo) ---
    printf("Movimento da Rainha (recursivo):\n");
    moverRainhaRec(passosRainha);

    // Cavalo já imprime linha em branco dentro da função
    moverCavaloComplexo();

    return 0;
}

