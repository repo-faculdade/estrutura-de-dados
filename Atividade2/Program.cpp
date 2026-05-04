#include <stdio.h>

void imprimirVetor(int multas[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%02d, ", multas[i]);
    }
    printf("]");
}

void selectionSort(int multas[], int tamanho) {
    int contador_trocas = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int indice_menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (multas[j] < multas[indice_menor]) {
                indice_menor = j;
            }
        }

        if (indice_menor != i) {
            // Troca os elementos
            int temp = multas[i];
            multas[i] = multas[indice_menor];
            multas[indice_menor] = temp;
            contador_trocas++;
        }
    }
    printf("Multas ordenadas:\n");
    imprimirVetor(multas, tamanho);
    printf("\nTotal de trocas: %d\n", contador_trocas);
}

int main() {
    printf("==== ATIVIDADE 2 ====");
    printf("\nOrdenando multas. \n\n");

    int multas[] = {500, 130, 880, 195, 290, 880};
    int tamanho = 6;
    printf("Multas Originais:\n");
    imprimirVetor(multas, tamanho);
    printf("\n\n");
    selectionSort(multas, tamanho);

    return 0;
}