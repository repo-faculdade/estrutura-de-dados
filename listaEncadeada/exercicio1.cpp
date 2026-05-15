// EXERCÍCIO 1 - A prefeitura precisa exibir no site todos os números de protocolo de obras que estão na fila de execução. O sistema entregou para você apenas o ponteiro head (o primeiro da fila). Escreva uma função void imprimirObras(struct No *head). Essa função deve varrer a lista encadeada do início ao fim e imprimir o número de cada protocolo na tela. A função deve parar automaticamente quando o ponteiro atingir o NULL.

#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

//head e a lista inteira propriamente dita
void imprimirObras(struct No *head){
    //atribuir head a uma nova variavel que sera percorrida, para nao adulterar a lista 
    struct No *atual = head;
    printf("===========Imprimir Obras===========\n");

    while(atual != NULL){
        printf("Protocolo: %d\n",atual->dado);

        //indo para o proximo acessando o *proximo da struct
        atual = atual->proximo;
    }
}


int main(){
    //reservando 3 espacos na memoria Heap
    struct No *obra1 = (struct No*) malloc(sizeof(struct No));
    struct No *obra2 = (struct No*) malloc(sizeof(struct No));
    struct No *obra3 = (struct No*) malloc(sizeof(struct No));

    //populando os 3 espacos reservandos na memoria Heap
    obra1->dado=1045;
    obra2->dado=1046;
    obra3->dado=5050;
    //populando proximo com valores do proximo elemento (endereço/buraco de minhoca que sera usado para localizar o proximo)
    obra1->proximo = obra2;
    obra2->proximo = obra3;
    obra3->proximo = NULL;

    //setar o inicio da lista como a obra1
    struct No *inicio_da_lista=obra1;

    //passar o inicio da lista 
    imprimirObras(inicio_da_lista);
    free(obra1);
    free(obra2);
    free(obra3);

    return 0;
}