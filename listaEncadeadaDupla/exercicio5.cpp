//Exercício 5 - Um contribuinte pagou o IPTU e precisa sair da fila de devedores. Na Lista Simples, tínhamos que varrer a lista arrastando um ponteiro anterior para consertar o buraco deixado. Agora, o próprio nó sabe quem está atrás dele! Escreva a função void removerCpf(struct NoDuplo head, int cpf_alvo). Você deve usar apenas um ponteiro de caminhada (atual). Quando achar o alvo, o próprio nó alvo avisa seus vizinhos para darem as mãos (atual->anterior->proximo = atual->proximo e vice-versa), isolando-o da fila antes de você aplicar o free(atual).


#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

void imprimir(NoDuplo *head) {
    NoDuplo *atual = head;
    while(atual != NULL) {
        printf("%d ", atual->cpf);
        atual = atual->proximo;
    }
    printf("\n");
}

void removerCpf(struct NoDuplo *head, int cpf_alvo){
    if(head == NULL){
        printf("Lista vazia.\n");
        return;
    }
    NoDuplo *atual = head;
    while(atual != NULL && atual->cpf != cpf_alvo){
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("CPF alvo não encontrado.\n");
        return;
    }
    atual->anterior->proximo = atual->proximo; //e vice-versa
    atual->proximo->anterior = atual->anterior;
    free(atual);
    printf("CPF [%d] removido com sucesso.\n", cpf_alvo);
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

    removerCpf(head, 500);
    imprimir(head);
    return 0;
}