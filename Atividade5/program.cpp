// ATIVIDADE 5 - A escola Norte enviou os IDs de seus alunos {20, 40, 60} e a escola Sul enviou {10, 30, 50, 70}. Ambas já estão ordenadas.
// Missão: Sem usar recursividade ainda, escreva apenas a função merge que recebe esses dois pequenos vetores e os junta em um terceiro vetor de 7 posições perfeitamente ordenado.

#include <stdio.h>

void merge(int escolaNorte[], int tamanhoNorte, int escolaSul[], int tamanhoSul, int resultado[]) {
    int i = 0, j = 0, k = 0;

    while (i < tamanhoNorte && j < tamanhoSul) {
        if (escolaNorte[i] < escolaSul[j]) {
            resultado[k++] = escolaNorte[i++];
        } else {
            resultado[k++] = escolaSul[j++];
        }
    }

    while (i < tamanhoNorte) {
        resultado[k++] = escolaNorte[i++];
    }

    while (j < tamanhoSul) {
        resultado[k++] = escolaSul[j++];
    }
}
int main() {
    printf("==== ATIVIDADE 5 ====");
    printf("\nMesclando os IDs dos alunos. \n\n");

    int escolaNorte[] = {20, 40, 60};
    int escolaSul[] = {10, 30, 50, 70};
    int resultado[7];

    merge(escolaNorte, 3, escolaSul, 4, resultado);

    printf("IDs mesclados e ordenados:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}