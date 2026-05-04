// A Secretaria de Trânsito quer ordenar os valores de 6 multas: {500, 130, 880, 195, 290, 880}. O hardware do servidor é antigo e queremos poupar a memória RAM.
// Missão: Implemente o Selection Sort. Crie uma variável contador_trocas. Incremente essa variável apenas quando o comando de troca (swap) for executado. Imprima o total no final. 


#include <stdio.h>

// Func Aux pra imprimir o vetor formatado
void imprimirVetor(int senhas[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%02d, ", senhas[i]);
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
    printf("Multas ordenadas:");
    imprimirVetor(multas, tamanho);
    printf("\nTotal de trocas: %d\n", contador_trocas);
}

int main() {
    printf("==== ATIVIDADE 2 ====");
    printf("\n Ordenando multas. \n\n");

    int multas[] = {500, 130, 880, 195, 290, 880};
    int tamanho = 6;

    selectionSort(multas, tamanho);

    return 0;
}