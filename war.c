#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[50];
    char cor[30];
    int tropas;
} Territorio;

void batalhar(Territorio *atacante, Territorio *defensor) {
    int dadoAtaque = rand() % 6 + 1;  // Valor entre 1 e 6
    int dadoDefesa = rand() % 6 + 1;

    printf("\nBatalha entre %s (atacante) e %s (defensor)\n", atacante->nome, defensor->nome);
    printf("Dado do ataque: %d | Dado da defesa: %d\n", dadoAtaque, dadoDefesa);

    if (dadoAtaque >= dadoDefesa) {
        defensor->tropas--;
        printf("O atacante venceu a rodada!\n");
        if (defensor->tropas <= 0) {
            printf("O território %s foi conquistado por %s!\n", defensor->nome, atacante->nome);
            defensor->tropas = 1; // Território conquistado começa com 1 tropa
            strcpy(defensor->cor, atacante->cor);
        }
    } else {
        atacante->tropas--;
        printf("O defensor resistiu ao ataque!\n");
    }
}

// Função para exibir o estado atual do mapa
void exibirMapa(Territorio *mapa, int n) {
    printf("\n--- Mapa atual do Mundo ---\n\n");
    for (int i = 0; i < n; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("-----------------------------\n");
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int n = 5;
    Territorio *mapa = (Territorio *)calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Cadastro dos territórios
    for (int i = 0; i < n; i++) {
        printf("-- Cadastro do Território %d --\n", i + 1);

        printf("Nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // Limpa o buffer

        printf("\n");
    }

    int opcao;
    do {
        exibirMapa(mapa, n);

        printf("\n--Fase de Batalha--\n");
        printf("Escolha o território atacante (1 a %d): ", n);
        int atq;
        scanf("%d", &atq);
        getchar();

        printf("Escolha o território defensor (1 a %d): ", n);
        int def;
        scanf("%d", &def);
        getchar();

        if (atq < 1 || atq > n || def < 1 || def > n || atq == def) {
            printf("Escolha inválida! Tente novamente.\n");
        } else if (mapa[atq - 1].tropas <= 0) {
            printf("⚠️ O território atacante não possui tropas suficientes!\n");
        } else {
            batalhar(&mapa[atq - 1], &mapa[def - 1]);
        }

        printf("\nDeseja realizar outra batalha? (1 - Sim / 0 - Não): ");
        scanf("%d", &opcao);
        getchar();

    } while (opcao != 0);

    printf("\nFim do jogo! Obrigado por jogar WAR Estruturado!\n");

    free(mapa); // Libera a memória alocada dinamicamente
    return 0;                               
} 