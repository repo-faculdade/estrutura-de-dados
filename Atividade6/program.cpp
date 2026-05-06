// ATIVIDADE 6 - O RH do Banrisul precisa ordenar as matrículas de 8 novos servidores: {44, 21, 98, 12, 55, 73, 31, 8}.
// Missão: Junte a função do exercício anterior com a função recursiva de divisão do Merge Sort. Faça o programa imprimir "Dividindo..." sempre que a função for chamada, para provar que ele quebra o vetor até chegar em tamanho 1.

#include <stdio.h>

void merge(int *vet, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // Criação de vetores temporários para a combinação dos dois subv Arrays
    int esq[n1], dir[n2];

    for (int i = 0; i < n1; i++) {
        esq[i] = vet[p + i];
    }
    for (int j = 0; j < n2; j++) {
        dir[j] = vet[q + 1 + j];
    }

    int i, j, k;
    i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            vet[k++] = esq[i++];
        } else {
            vet[k++] = dir[j++];
        }
    }

    // Colocando os restantes elementos de esq[]
    while (i < n1) {
        vet[k++] = esq[i++];
    }

    // Colocando os restantes elementos de dir[]
    while (j < n2) {
        vet[k++] = dir[j++];
    }
}

void mergeSort(int *vet, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; // Divide o vetor em dois

        printf("Dividindo... %d\n", q); // Imprime sempre que a função for chamada
        
        mergeSort(vet, p, q);       // Divisão do lado esquerdo
        mergeSort(vet, q + 1, r);   // Divisão do lado direito

        merge(vet, p, q, r); // Mescla os dois subv Arrays
    }
}

int main() {
    printf("==== ATIVIDADE 6 ====");
    printf("\nOrdenando matrículas de novos servidores. \n\n");

    int novosServidores[] = {44, 21, 98, 12, 55, 73, 31, 8};
    int tamanhoNovosServidores = sizeof(novosServidores) / sizeof(novosServidores[0]);

    mergeSort(novosServidores, 0, tamanhoNovosServidores - 1);

    printf("Matrículas ordenadas:\n");
    for (int i = 0; i < tamanhoNovosServidores; i++) {
        printf("%d ", novosServidores[i]);
    }
    printf("\n");

    return 0;
}
