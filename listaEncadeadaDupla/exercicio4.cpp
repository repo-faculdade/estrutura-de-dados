//Exercício 4 - Na Lista Simples, inserir um nó antes de um alvo era um pesadelo (exigia um ponteiro auxiliar correndo atrás). Na Lista Dupla, é fácil! Um paciente grave chegou e precisa ser inserido exatamente antes do paciente com ID 500. Escreva void inserirAntes(struct NoDuplo head, int id_alvo, int novo_id). Encontre o id_alvo. Crie o novo nó e faça a amarração dos 4 ponteiros para que ele entre antes do alvo.

#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

void inserirAntes(struct NoDuplo *head, int id_alvo, int novo_id){
    NoDuplo *novoNo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novoNo->cpf = novo_id;
    if(head == NULL) {
        novoNo->anterior = NULL;
        novoNo->proximo = NULL;
        head = novoNo;
        return;
    }
    NoDuplo *atual = head;
    while(atual != NULL && atual->cpf != id_alvo) {
        atual = atual->proximo;
    }
    if(atual == NULL) {
        printf("ID alvo não encontrado.\n");
        free(novoNo);
        return;
    }
    // Amarração dos 4 ponteiros, novoNo->proximo = atual, novoNo->anterior = atual->anterior
    // se atual->anterior for NULL, atual = head, e head = novoNo 
    novoNo->proximo = atual;
    novoNo->anterior = atual->anterior;

    if (atual->anterior != NULL) {
        atual->anterior->proximo = novoNo;
    } else {
        head = novoNo;
    }
    atual->anterior = novoNo;
}
void imprimir(NoDuplo *head) {
    NoDuplo *atual = head;
    while(atual != NULL) {
        printf("%d ", atual->cpf);
        atual = atual->proximo;
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
    novo2->cpf = 500;
    novo2->anterior = head;
    novo2->proximo = NULL;
    head->proximo = novo2;

    NoDuplo *novo3 = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo3->cpf = 789;
    novo3->anterior = novo2;
    novo3->proximo = NULL;
    novo2->proximo = novo3;

    inserirAntes(head, 500, 890);
    imprimir(head);
    return 0;
}