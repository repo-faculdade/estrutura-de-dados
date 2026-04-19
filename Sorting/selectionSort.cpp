#include <stdio.h>
#include <math.h>
int main(){
    int tamanho = 10;
    int arraySelection[tamanho] = {1,5,2,3,4,9,7,6,8,10,0};    
    int estaOrdenados = 0;
    int menorNum = 0;

    for(int i = 0; i < tamanho; i++){
            printf("%d, ", arraySelection[i]);
    }
    printf("\n");

    int trocaGeral = 0;
    for (int i = 0; i < tamanho - 1; i++)
    {
        int posicao = i;
        int menorNum = arraySelection[i];

        for(int j = i + 1; j < tamanho; j++){
            if(arraySelection[j] < menorNum){
                menorNum = arraySelection[j];
                posicao = j;
            }
        }

        if(posicao != i){
            int aux = arraySelection[i];
            arraySelection[i] = arraySelection[posicao];
            arraySelection[posicao] = aux;
            trocaGeral = 1;
        }
    }

    printf("\nOrdenacao\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", arraySelection[i]);
    }
    printf("\n");
}