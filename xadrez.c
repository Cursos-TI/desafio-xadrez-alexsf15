// Aluno: Alexssandro de Souza Freitas
//Versão 1.0
#include <stdio.h>

// Função recursiva para movimento do Bispo
void moverBispo(int passo, int limite) {
    if (passo >= limite) return;
    printf("Cima direita (passo %d)\n", passo);
    moverBispo(passo + 1, limite);
}

// Verifica se a posição está dentro dos limites do tabuleiro
int posicaoValida(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

int main() {
    int bispo = 0, torre = 0, rainha = 0;

    // Bispo (diagonal)
    printf("==!!Movendo o Bispo!!==\n\n");
    moverBispo(bispo, 5);

    // Torre (horizontal para a direita)
    printf("\n==!!Movendo a Torre!!==\n\n");
    for (torre = 0; torre < 5; torre++) {
        printf("Direita (casa %d)\n", torre + 1);
    }

    // Rainha (horizontal para a esquerda)
    printf("\n==!!Movendo a Rainha!!==\n\n");
    rainha = 0;
    do {
        printf("Esquerda (casa %d)\n", rainha + 1);
        rainha++;
    } while (rainha < 8);

    // Cavalo (movimento realista em L)
    printf("\n==!!Movendo o Cavalo!!==\n\n");
    int cavaloX = 4, cavaloY = 4; // posição inicial do Cavalo

    // Possíveis movimentos do Cavalo (L)
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int novoX = cavaloX + movimentos[i][0];
        int novoY = cavaloY + movimentos[i][1];

        if (!posicaoValida(novoX, novoY)) {
            continue; // ignora movimentos inválidos fora do tabuleiro
        }

        printf("Cavalo pode mover-se para (%d, %d)\n", novoX, novoY);

        // Exemplo de uso de break: para simular interrupção se chegar à borda
        if (novoX == 1 || novoY == 1 || novoX == 8 || novoY == 8) {
            printf("Cavalo chegou à borda do tabuleiro. Interrompendo...\n");
            break;
        }
    }

    return 0;
}
