// ATIVIDADE 4 - Temos um vetor totalmente invertido: {9, 8, 7, 6, 5, 4, 3, 2, 1}.
// Missão: Em um mesmo programa, passe esse vetor por uma função Bubble Sort e por uma função Selection Sort. Imprima o número de Comparações e Trocas de ambos. Compare os resultados. 

#include <stdio.h>

void bubbleSort(int vetor[], int tamanho) {
    int contador_comparacoes = 0;
    int contador_trocas = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            contador_comparacoes++;
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                contador_trocas++;
            }
        }
    }
    printf("Bubble Sort - Comparacoes: %d, Trocas: %d\n", contador_comparacoes, contador_trocas);
    printf("Vetor ordenado com Bubble Sort:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void selectionSort(int vetor[], int tamanho) {
    int contador_comparacoes = 0;
    int contador_trocas = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        int indice_menor = i;

        for (int j = i + 1; j < tamanho; j++) {
            contador_comparacoes++;
            if (vetor[j] < vetor[indice_menor]) {
                indice_menor = j;
            }
        }

        if (indice_menor != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indice_menor];
            vetor[indice_menor] = temp;
            contador_trocas++;
        }
    }
    printf("Selection Sort - Comparacoes: %d, Trocas: %d\n", contador_comparacoes, contador_trocas);
    printf("Vetor ordenado com Selection Sort:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    printf("==== ATIVIDADE 4 ====");
    printf("\nOrdenando vetor invertido. \n\n");

    int vetor[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tamanho = 9;

    printf("Vetor Original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    bubbleSort(vetor, tamanho);
    selectionSort(vetor, tamanho);

    return 0;
}