//Exercício 2 - No CRAS, quando o atendente busca um CPF, o sistema agora precisa mostrar quem está aguardando antes e depois dessa pessoa na fila para evitar fraudes. Escreva void buscarComVizinhos(struct NoDuplo *head, int cpf_alvo). A função deve encontrar o nó alvo e imprimir: "O cidadão [X] está na fila. Na frente dele está o [Y] e atrás dele está o [Z]".

#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

void buscarComVizinhos(struct NoDuplo *head, int cpf_alvo){
    if(head == NULL){
        printf("Fila Vazia!\n");
        return;
    }
    NoDuplo *atual = head;
    while(atual != NULL && atual->cpf != cpf_alvo){
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("CPF [%d] nao encontrado na fila!\n", cpf_alvo);
        return;
    }
    if(atual->proximo == NULL){
        printf("O cidadão [%d] está na fila. Na frente dele está o [NULL] e atrás dele está o [%d]\n", atual->cpf, atual->anterior->cpf);
        return;
    }
    if(atual->anterior == NULL){
        printf("O cidadão [%d] está na fila. Na frente dele está o [%d] e atrás dele está o [NULL]\n", atual->cpf, atual->proximo->cpf);
        return;
    }
    printf("O cidadão [%d] está na fila. Na frente dele está o [%d] e atrás dele está o [%d]\n", atual->cpf, atual->proximo->cpf,atual->anterior->cpf);
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

    buscarComVizinhos(head, 789);

    return 0;
}