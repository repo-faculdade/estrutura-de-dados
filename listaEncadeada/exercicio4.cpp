// Exercício 4 - A fila de transplantes do estado é uma lista encadeada. Um novo paciente idoso chegou e tem prioridade por lei. Ele não pode ir para o final da fila, mas também não vai ser o primeiro. Ele deve ser inserido exatamente logo após o paciente de ID 500 (que já estava na fila). Escreva uma função void inserirApos(struct No *head, int id_alvo, int novo_id). A função deve procurar o nó que contém o id_alvo (500). Quando achar, deve criar um nó para o novo_id e plugá-lo na corrente imediatamente após o alvo.

// Atenção: Cuidado com a ordem dos ponteiros! Se você plugar o alvo no novo nó antes de plugar o novo nó no restante da fila, você perde a lista inteira no Limbo da Memória (Memory Leak).

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
void inserirApos(struct No *head, int id_alvo, int novo_id){
    struct No *novoPaciente = (struct No*) malloc(sizeof(struct No));
    novoPaciente->dado = novo_id;
    //atribuir head a uma nova variavel que sera percorrida, para nao adulterar a lista
    struct No *atual = head;
    while(atual != NULL){
        if(atual->dado == id_alvo){
            novoPaciente->proximo = atual->proximo;
            atual->proximo = novoPaciente;
            return;
        }
        atual = atual->proximo;
    }
    printf("Nao encontrado id alvo!\n");
    return;
}


int main(){
    int alvo = 500;
    //reservando 3 espacos na memoria Heap
    struct No *paciente1 = (struct No*) malloc(sizeof(struct No));
    struct No *paciente2 = (struct No*) malloc(sizeof(struct No));
    struct No *paciente3 = (struct No*) malloc(sizeof(struct No));

    //populando os 3 espacos reservandos na memoria Heap
    paciente1->dado=21;
    paciente2->dado=500;
    paciente3->dado=370;
    //populando proximo com valores do proximo elemento (endereço/buraco de minhoca que sera usado para localizar o proximo)
    paciente1->proximo = paciente2;
    paciente2->proximo = paciente3;
    paciente3->proximo = NULL;

    //setar o inicio da lista como a obra1
    struct No *inicio_da_lista=paciente1;

    //passar o inicio da lista 
    inserirApos(inicio_da_lista, alvo, 220);
    imprimir(inicio_da_lista);
    printf("\n");
    free(paciente1);
    free(paciente2);
    free(paciente3);
    // free(novoPaciente);

    return 0;
}