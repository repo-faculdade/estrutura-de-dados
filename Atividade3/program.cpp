// ATIVIDADE 3 - O lote de pagamentos do banco chegou quase perfeito: {101, 102, 103, 104, 105, 99}. Apenas o protocolo 99 sofreu atraso de rede e caiu no final.
// Missão: Implemente o Insertion Sort com um contador de comparações (quantas vezes o if é testado). Veja como ele resolve esse problema rapidamente, "puxando" o 99 para o início e parando de comparar o resto.
#include <stdio.h>

void insertionSort(int pagamentos[], int tamanho) {
    int contador_comparacoes = 0;

    for (int i = 1; i < tamanho; i++) {
        int chave = pagamentos[i];
        int j = i - 1;

        while (j >= 0 && pagamentos[j] > chave) {
            contador_comparacoes++;
            pagamentos[j + 1] = pagamentos[j];
            j--;
        }
        if (j >= 0) {
            contador_comparacoes++;
        }
        pagamentos[j + 1] = chave;
    }

    printf("Pagamentos ordenados:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", pagamentos[i]);
    }
    printf("\nTotal de comparacoes: %d\n", contador_comparacoes);
}
int main(){
    printf("==== ATIVIDADE 3 ====");
    printf("\nOrdenando pagamentos. \n\n");

    int pagamentos[] = {101, 102, 103, 104, 105, 99};
    int tamanho = 6;

    printf("Pagamentos Originais:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", pagamentos[i]);
    }
    printf("\n\n");

    insertionSort(pagamentos, tamanho);

    return 0;
}