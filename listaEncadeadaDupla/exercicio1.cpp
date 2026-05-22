//Exercício 1 - A prefeitura quer provar que o sistema é transparente e permite auditoria de trás para frente. Você recebeu o ponteiro head da fila de obras. Escreva a função void imprimirIdaEVolta(struct NoDuplo *head). Você deve varrer a fila usando o proximo até chegar ao último nó, imprimindo os valores. Quando bater no último nó (aquele cujo próximo é NULL), você não deve parar. Use o ponteiro anterior para voltar dando "marcha à ré" até o início, imprimindo os valores novamente.

#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

void imprimirIdaEVolta(struct NoDuplo *head){
    if(head == NULL){
        printf("Fila Vazia!\n");
        return;
    }
    NoDuplo *atual = head;
    NoDuplo *ultimo = NULL;
    printf("\nPrimeiro ao Ultimo:\n");
    while(atual != NULL){
        printf("%d - ", atual->cpf);
        ultimo = atual;
        atual = atual->proximo;
    }
    printf("\nUltimo ao Primeiro:\n");
    while (ultimo != NULL){
        printf("%d ", ultimo->cpf);
        ultimo = ultimo->anterior;
    }
    printf("\n");
}

int main(){
    NoDuplo *head = NULL;
    
    // Inserindo alguns nós para teste
    NoDuplo *novo1 = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo1->cpf = 123;
    novo1->anterior = NULL;
    novo1->proximo = NULL;
    head = novo1;

    NoDuplo *novo2 = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo2->cpf = 456;
    novo2->anterior = head;
    novo2->proximo = NULL;
    head->proximo = novo2;

    NoDuplo *novo3 = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo3->cpf = 789;
    novo3->anterior = novo2;
    novo3->proximo = NULL;
    novo2->proximo = novo3;

    imprimirIdaEVolta(head);

    return 0;
}