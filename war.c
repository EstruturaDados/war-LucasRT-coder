#include <stdio.h>
#include <string.h> 


typedef struct {
    char nome[50];
    char cor[30];
    int tropas;
} Territorio;

int main() {
    Territorio mapa[5]; // array 
    int i;

    printf(" -- Cadastro dos Territórios - Nível Novato -- \n");

    // Leitura dos dados dos territórios
    for (i = 0; i < 5; i++) {
        printf(">>> Cadastro do Território %d <<<\n", i + 1);

        printf("Nome do território: ");
        fgets(mapa[i].nome, sizeof(mapa[i].nome), stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0'; // Remove o '\n'

        printf("Cor do exército: ");
        fgets(mapa[i].cor, sizeof(mapa[i].cor), stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &mapa[i].tropas);
        getchar(); // Limpa o buffer do teclado

        printf("\n");
    }

    // Exibição do mapa completo
    printf("\n Estado Atual do Mapa \n");

    for (i = 0; i < 5; i++) {
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", mapa[i].nome);
        printf("Cor do Exército: %s\n", mapa[i].cor);
        printf("Tropas: %d\n", mapa[i].tropas);
        printf("\n");
    }

    return 0;
}