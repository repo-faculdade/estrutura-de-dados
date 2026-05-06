// ATIVIDADE 10 - Sistemas reais (como o V8 do JavaScript ou o Python) não usam um algoritmo só. Eles misturam os melhores!

// Missão: Crie uma função chamada super_sort(vetor, tamanho).

// Se o tamanho for menor que 10, ela deve chamar o Insertion Sort (porque em arrays minúsculos ele não tem overhead de recursão e é mais rápido).

// Se o tamanho for maior ou igual a 10, ela deve chamar o Quick Sort.

// Desafio extra: Teste com um vetor de 8 posições e um de 15 posições para ver a inteligência do código escolhendo o melhor caminho.
#include <stdio.h>
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high]; // Pivô é o último elemento
        int i = low - 1; // Índice para o menor elemento

        for (int j = low; j < high; j++) {
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

void super_sort(int arr[], int n) {
    if (n < 10) {
        insertionSort(arr, n);
    } else {
        quickSort(arr, 0, n - 1);
    }
}

int main() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int arr2[] = {10, 7, 8, 9, 1, 5, 6, 2, 3, 4, 5, 6, 7, 8, 9};

    super_sort(arr1, sizeof(arr1) / sizeof(arr1[0]));
    super_sort(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("Array 1 ordenado: ");
    for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Array 2 ordenado: ");
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
