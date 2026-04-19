#include <stdio.h>
#include <math.h>

int main(){
    int tamanho = 10;
    int arraySelection[tamanho] = {1,5,2,3,4,9,7,6,8,0};    
    for(int i = 0; i < tamanho; i++){
            printf("%d, ", arraySelection[i]);
    }
    printf("\n");

    int troca = 0;
            for (int i = 0; i < tamanho - 1; i++)
            {
                int indiceMenor = i;
                for (int j = i + 1; j < tamanho; j++)
                {
                    if (arraySelection[j] < arraySelection[indiceMenor])
                        indiceMenor = j;
                }
                if (indiceMenor != i)
                {
                    int temp = arraySelection[i];
                    arraySelection[i] = arraySelection[indiceMenor];
                    arraySelection[indiceMenor] = temp;
                    troca++;
                }
            }

    printf("\nOrdenacao\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", arraySelection[i]);
    }
    printf("\n");
}   