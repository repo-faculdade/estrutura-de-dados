// Exercício 2 - A Secretaria de Educação tem uma lista encadeada de alunos aguardando vaga em creches. O prefeito perguntou: "Quantas crianças estão na fila hoje?". Escreva uma função int contarFila(struct No *head). Você não pode usar variáveis globais. A função deve percorrer a lista encadeada, contar quantos nós existem e retornar esse valor inteiro.


#include <stdio.h>
#include <stdlib.h>

struct No {
    int dado;
    struct No *proximo;
};

//head e a lista inteira propriamente dita
int contarFila(struct No *head){
    //atribuir head a uma nova variavel que sera percorrida, para nao adulterar a lista 
    struct No *atual = head;
    int contador = 0;
    while(atual != NULL){
        printf("Crianca id: %d\n",atual->dado);
        //indo para o proximo acessando o *proximo da struct
        atual = atual->proximo;
        contador++;
    }
    return contador;
}


int main(){
    //reservando 3 espacos na memoria Heap
    struct No *crianca1 = (struct No*) malloc(sizeof(struct No));
    struct No *crianca2 = (struct No*) malloc(sizeof(struct No));
    struct No *crianca3 = (struct No*) malloc(sizeof(struct No));

    //populando os 3 espacos reservandos na memoria Heap
    crianca1->dado=5;
    crianca2->dado=8;
    crianca3->dado=33;
    //populando proximo com valores do proximo elemento (endereço/buraco de minhoca que sera usado para localizar o proximo)
    crianca1->proximo = crianca2;
    crianca2->proximo = crianca3;
    crianca3->proximo = NULL;

    //setar o inicio da lista como a obra1
    struct No *inicio_da_lista=crianca1;

    //passar o inicio da lista 
    int quantidade = contarFila(inicio_da_lista);
    printf("Tem %d criancas aguardando na fila\n", quantidade);
    free(crianca1);
    free(crianca2);
    free(crianca3);

    return 0;
}