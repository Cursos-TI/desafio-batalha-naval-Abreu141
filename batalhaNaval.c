#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int linha_navio, coluna_navio;  // posição do navio
    int linha_tiro, coluna_tiro;    // tiro do jogador
    int tentativas = 0;             // contador de jogadas
    int acerto = 0;                 // flag de acerto (0 = não acertou, 1 = acertou)

    const int TAMANHO = 10;         

    // Gerar posição aleatória do navio (tabuleiro 10x10)
    srand(time(NULL));
    linha_navio = rand() % TAMANHO;   
    coluna_navio = rand() % TAMANHO;  

    printf("=== ⚓ BATALHA NAVAL ===\n");
    printf("O tabuleiro é 10x10 (linhas e colunas de 0 a 9)\n");
    printf("Tente acertar onde o navio está escondido!\n\n");

    while (acerto == 0) {
        printf("Digite a linha (0 a 9): ");
        scanf("%d", &linha_tiro);

        printf("Digite a coluna (0 a 9): ");
        scanf("%d", &coluna_tiro);

        if (linha_tiro < 0 || linha_tiro >= TAMANHO || coluna_tiro < 0 || coluna_tiro >= TAMANHO) {
            printf("\n🚫 Posição inválida! Digite números entre 0 e 9.\n\n");
            continue; 
        }

        tentativas++;

        // Verifica se o tiro acertou
        if (linha_tiro == linha_navio && coluna_tiro == coluna_navio) {
            printf("\n💥 ACERTOU O NAVIO! 💥\n");
            printf("Você venceu em %d tentativas!\n", tentativas);
            acerto = 1;
        } else {
            printf("\n🌊 Água! O navio não está em (%d, %d).\n", linha_tiro, coluna_tiro);

            // Dicas de direção
            if (linha_tiro < linha_navio)
                printf("👉 O navio está mais em BAIXO.\n");
            else if (linha_tiro > linha_navio)
                printf("👆 O navio está mais em CIMA.\n");

            if (coluna_tiro < coluna_navio)
                printf("➡️  O navio está mais à DIREITA.\n");
            else if (coluna_tiro > coluna_navio)
                printf("⬅️  O navio está mais à ESQUERDA.\n");

            printf("-----------------------------\n");
        }
    }

    printf("\nFim de jogo. Obrigado por jogar!\n");

    return 0;
}
