// ATIVIDADE 8 - O banco de dados central tem os CPFs (simplificados em 4 dígitos) desordenados: {4321, 1111, 9999, 3333, 7777, 2222, 5555}.
// Missão: Implemente o Quick Sort completo utilizando a função de partição do exercício anterior.
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô é o último elemento
    int i = low - 1; // Índice para o menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int cpfs[] = {4321, 1111, 9999, 3333, 7777, 2222, 5555};
    int n = sizeof(cpfs) / sizeof(cpfs[0]);

    quickSort(cpfs, 0, n - 1);

    printf("CPFs ordenados: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", cpfs[i]);
    }
    printf("\n");

    return 0;
}