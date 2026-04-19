#include <stdio.h>
#include <math.h>

int main()
{
    int tamanho = 10;
    int arrayInsert[tamanho] = {1, 5, 2, 3, 4, 9, 7, 6, 8, 0};
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", arrayInsert[i]);
    }
    printf("\n");
    int n = tamanho;
    long passos = 0;
    long trocas = 0;

    for (int i = 1; i < n; i++)
    {
        int chave = arrayInsert[i];
        int j = i - 1;
        while (j >= 0 && arrayInsert[j] > chave)
        {
            passos++;
            arrayInsert[j + 1] = arrayInsert[j];
            j--;
            trocas++;
        }
        passos++;
        arrayInsert[j + 1] = chave;
    }
    printf("\nOrdenacao\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d, ", arrayInsert[i]);
    }
    printf("\n");
}