
#include <stdio.h>

// Func Aux pra imprimir o vetor formatado
void imprimirVetor(int senhas[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%02d, ", senhas[i]);
    }
    printf("]");
}

// Função do BubleSort
void bubleSortRaioX(int senhas[], int tamanho) {
    printf("Estado inicial da fila:");
    imprimirVetor(senhas, tamanho);

    // Laço externo: Controla das passadas
    for (int i = 0; i < tamanho; i++) {
        // Laço interno: Faz as comparações
        for (int j = 0; j < tamanho - i - 1; j++) {
            // Compara posição atual com prox.
            if (senhas[j] > senhas[j + 1]) {
                int aux = senhas[j];
                senhas[j] = senhas[j + 1];
                senhas[j + 1] = aux;
            }
        }

        // Imprimindo estado atual
        printf("\nFim da passada: %d", i + 1);
        imprimirVetor(senhas, tamanho);
    }
}

int main() {
    printf("==== ATIVIDADE 1 ====");
    printf("\n Ordenando senhas do posto. \n\n");

    int senhas_atendimento[] = { 82, 45, 12, 78, 23 };
    int tamanho = 5;

    bubleSortRaioX(senhas_atendimento, tamanho);

    return 0;
}