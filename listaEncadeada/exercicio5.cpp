// Exercício 5 - Um contribuinte acaba de pagar o seu IPTU atrasado. O sistema precisa remover o CPF dele da lista encadeada de Inadimplentes da prefeitura. O problema é que ele pode estar no início, no meio ou no fim da lista. Escreva a função void removerCpf(struct No head, int cpf_alvo). Para remover um nó no meio da lista, você precisará de dois ponteiros de navegação (um atual e um anterior). Quando o atual achar o CPF, a corrente do anterior deve "pular" o nó removido e se conectar ao próximo, isolando o pagador para que você possa usar o free() nele. Lembre-se de tratar o caso onde o pagador é exatamente o primeiro da fila (*head).

#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

void imprimir(struct No *head){
    //atribuir head a uma nova variavel que sera percorrida, para nao adulterar a lista 
    struct No *atual = head;
    printf("===========Imprimir===========\n");

    while(atual != NULL){
        printf("Dado: %d\n",atual->dado);

        //indo para o proximo acessando o *proximo da struct
        atual = atual->proximo;
    }
}

//head e a lista inteira propriamente dita
void removerCpf(struct No *head, int cpf_alvo){
    //atribuir head a uma nova variavel que sera percorrida, para nao adulterar a lista

    struct No *atual = head;
    struct No *anterior = NULL;
    
    while(atual != NULL){
        if(atual->dado == cpf_alvo){
            if(anterior ==NULL){
                
                return;
            }else{
            anterior->proximo = atual->proximo;
            free(atual);
            return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Nao encontrado id alvo!\n");
    return;
}


int main(){
    int alvo = 21;
    //reservando 3 espacos na memoria Heap
    struct No *pessoa1 = (struct No*) malloc(sizeof(struct No));
    struct No *pessoa2 = (struct No*) malloc(sizeof(struct No));
    struct No *pessoa3 = (struct No*) malloc(sizeof(struct No));

    //populando os 3 espacos reservandos na memoria Heap
    pessoa1->dado=21;
    pessoa2->dado=500;
    pessoa3->dado=370;
    //populando proximo com valores do proximo elemento (endereço/buraco de minhoca que sera usado para localizar o proximo)
    pessoa1->proximo = pessoa2;
    pessoa2->proximo = pessoa3;
    pessoa3->proximo = NULL;

    //setar o inicio da lista como a obra1
    struct No *inicio_da_lista=pessoa1;

    //passar o inicio da lista 
    removerCpf(inicio_da_lista, alvo);
    imprimir(inicio_da_lista);
    printf("\n");
    free(pessoa1);
    free(pessoa2);
    free(pessoa3);

    return 0;
}