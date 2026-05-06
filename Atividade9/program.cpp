// ATIVIDADE 9 - O sistema passou um vetor já ordenado de 10 posições {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} para um Quick Sort que sempre escolhe o último elemento como pivô.
// Missão: Rode o Quick Sort e conte quantas chamadas recursivas e comparações ele faz. Você deve escrever em comentário no código: por que a "Divisão e Conquista" falhou aqui e o algoritmo virou um O(n²)?
#include <stdio.h>

void quickSort(int arr[], int low, int high, int &comparisons, int &recursiveCalls) {
    if (low < high) {
        recursiveCalls++;
        int pivot = arr[high]; // Pivô é o último elemento
        int i = low - 1; // Índice para o menor elemento

        for (int j = low; j < high; j++) {
            comparisons++;
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap arr[i + 1] and arr[high]
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        quickSort(arr, low, i, comparisons, recursiveCalls);
        quickSort(arr, i + 2, high, comparisons, recursiveCalls);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;
    int recursiveCalls = 0;

    quickSort(arr, 0, n - 1, comparisons, recursiveCalls);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Total de comparações: %d\n", comparisons);
    printf("Total de chamadas recursivas: %d\n", recursiveCalls);

    return 0;
}
