// ATIVIDADE 7 - Uma fila de subsídios com os valores: {300, 150, 800, 200, 900, 500}.
// Missão: Não faça a recursão do Quick Sort. Escolha o último elemento (500) como Pivô. Escreva apenas o laço for que joga tudo que é menor que 500 para a esquerda e o que é maior para a direita. Imprima o vetor ao final para ver o pivô no seu lugar definitivo.
#include <stdio.h>

int main() {
    int subsidies[] = {300, 150, 800, 200, 900, 500};
    int pivot = subsidies[5]; // Pivô é o último elemento (500)
    int i = -1; // Índice para o menor elemento

    for (int j = 0; j < 5; j++) { 
        if (subsidies[j] < pivot) { 
            i++;
            printf("%d %d\n",subsidies[i], subsidies[j]); 
        }
    }
    printf("%d %d\n",subsidies[i + 1], subsidies[5]);

    printf("Vetor apos a organizacao em relacao ao pivo: ");
    for (int k = 0; k < 6; k++) {
        printf("%d ", subsidies[k]);
    }
    printf("\n");

    return 0;
}