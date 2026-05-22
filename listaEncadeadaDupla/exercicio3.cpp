//Exercício 3 - O servidor da prefeitura andou travando e há suspeitas de que alguns nós perderam a conexão do "retrovisor", quebrando a lista dupla (Memory Leak). Escreva uma função int verificarIntegridade(struct NoDuplo *head). Ela deve varrer a lista e, para cada nó, perguntar: "O retrovisor do meu vizinho da frente aponta pra mim?" (Ou seja: atual->proximo->anterior == atual). Se toda a lista estiver perfeitamente costurada, retorne 1 (Verdadeiro). Se achar qualquer elo quebrado, retorne 0.

#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

int verificarIntegridade(struct NoDuplo *head){
    if(head == NULL){
        printf("Fila Vazia!\n");
        return 1; 
    }
    NoDuplo *atual = head;
    while(atual != NULL){
        if(atual->proximo == NULL || atual->proximo->anterior == atual)
            atual = atual->proximo;
        else
            return 0;
    }
    return 1;
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

    if(verificarIntegridade(head) == 1){
        printf("A lista está íntegra! Todos os retrovisores estão apontando corretamente.\n");
    } else {
        printf("A lista está quebrada! Há um nó com o retrovisor desconectado.\n");
    }
    return 0;
}