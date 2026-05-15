// Exercício 3 - Um cidadão ligou para o CRAS perguntando se o CPF dele está na lista de aprovados para receber a cesta básica. Escreva uma função int buscarCidadão(struct No *head, int cpf_buscado). A função deve percorrer a lista. Se encontrar o CPF, retorna 1 (Verdadeiro). Se percorrer a lista inteira e chegar ao NULL sem encontrar, retorna 0 (Falso).

#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

//head e a lista inteira propriamente dita
int buscarCidadao(struct No *head, int cpf_buscado){
  
    struct No *atual = head;
    while(atual != NULL){
        if(atual->dado == cpf_buscado){
            return 1;
        }
        atual = atual->proximo;
    }
    printf("Nao encontrado o cpf!\n");
    printf("Nao aprovado a receber Cesta basica!\n");
    return 0;
}


int main(){
    int cpf = 021;

    //reservando 3 espacos na memoria Heap
    struct No *cidadao1 = (struct No*) malloc(sizeof(struct No));
    struct No *cidadao2 = (struct No*) malloc(sizeof(struct No));
    struct No *cidadao3 = (struct No*) malloc(sizeof(struct No));

    //populando os 3 espacos reservandos na memoria Heap
    cidadao1->dado=21;
    cidadao2->dado=500;
    cidadao3->dado=370;
    //populando proximo com valores do proximo elemento (endereço/buraco de minhoca que sera usado para localizar o proximo)
    cidadao1->proximo = cidadao2;
    cidadao2->proximo = cidadao3;
    cidadao3->proximo = NULL;

    //setar o inicio da lista como a obra1
    struct No *inicio_da_lista=cidadao1;

    //passar o inicio da lista 
    int aprovado = buscarCidadao(inicio_da_lista, cpf);
    if(aprovado == 1){
        printf("Aprovado, pode receber a cesta basica!\n");
    }
    free(cidadao1);
    free(cidadao2);
    free(cidadao3);

    return 0;
}