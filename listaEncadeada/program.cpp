#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. A ESTRUTURA DO N� (O Combo: Dado + Corrente)
// ==========================================
typedef struct No {
    int valor;             // A Carga �til (Payload)
    struct No *proximo;    // O Ponteiro para o pr�ximo n� (A Corrente)
} No;

// ==========================================
// FUN��O AUXILIAR: DESENHAR A LISTA NA TELA
// ==========================================
void imprimirLista(No *head) {
    printf("\nEstado atual da Lista:\n");
    printf("[HEAD] -> ");

    No *atual = head;
    while (atual != NULL) {
        printf("[ %d ] -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n\n");
}

// ==========================================
// 2. OPERA��ES DA LISTA ENCADEADA
// ==========================================

// Inserir no In�cio - Complexidade: O(1)
void inserirInicio(No **head, int valor) {
    // 1. Pede mem�ria ao Heap
    No *novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro: Mem�ria insuficiente!\n");
        return;
    }

    // 2. Preenche o n�
    novo_no->valor = valor;

    // 3. A corrente do novo aponta para o antigo primeiro
    novo_no->proximo = *head;

    // 4. O sistema reconhece o novo n� como o primeiro (Head)
    *head = novo_no;

    printf(">> Sucesso! [%d] inserido no INICIO em O(1).\n", valor);
}

// Inserir no Fim - Complexidade: O(n)
void inserirFim(No **head, int valor) {
    No *novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = NULL; // Como vai ser o �ltimo, aponta para NULL

    // Caso especial: A lista est� vazia
    if (*head == NULL) {
        *head = novo_no;
        printf(">> Lista estava vazia. [%d] inserido como primeiro e ultimo n�.\n", valor);
        return;
    }

    // Se n�o est� vazia, o ped�gio do O(n): temos que varrer at� o fim
    No *atual = *head;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    // Chegamos no �ltimo. Conectamos ele ao novo.
    atual->proximo = novo_no;
    printf(">> Sucesso! Vareu a lista e inseriu [%d] no FIM em O(n).\n", valor);
}

// Remover do In�cio - Complexidade: O(1)
void removerInicio(No **head) {
    if (*head == NULL) {
        printf(">> Erro: A lista ja esta vazia!\n");
        return;
    }

    // Guarda o n� que vai morrer para podermos dar free()
    No *no_removido = *head;

    // O Head pula para o segundo n� da fila
    *head = (*head)->proximo;

    printf(">> Sucesso! [%d] removido do INICIO em O(1).\n", no_removido->valor);

    // Devolve a mem�ria pro Sistema Operacional (Evita Memory Leak)
    free(no_removido);
}

// Remover do Fim - Complexidade: O(n)
void removerFim(No **head) {
    if (*head == NULL) {
        printf(">> Erro: A lista ja esta vazia!\n");
        return;
    }

    // Caso especial: S� tem 1 n� na lista
    if ((*head)->proximo == NULL) {
        printf(">> Sucesso! [%d] removido. A lista ficou vazia.\n", (*head)->valor);
        free(*head);
        *head = NULL;
        return;
    }

    // Ped�gio O(n): Varrer at� encontrar o PEN�LTIMO n�
    No *atual = *head;
    while (atual->proximo->proximo != NULL) {
        atual = atual->proximo;
    }

    // 'atual' agora � o pen�ltimo. 'atual->proximo' � o �ltimo.
    No *no_removido = atual->proximo;
    printf(">> Sucesso! Vareu a lista e removeu [%d] do FIM em O(n).\n", no_removido->valor);

    // O pen�ltimo agora se torna o �ltimo (aponta para NULL)
    atual->proximo = NULL;
    free(no_removido);
}

// Busca Linear - Complexidade: O(n)
void buscarValor(No *head, int valor) {
    No *atual = head;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            printf(">> ENCONTRADO! O valor [%d] esta no indice %d (apos %d pulos).\n", valor, posicao, posicao);
            return;
        }
        atual = atual->proximo;
        posicao++;
    }

    printf(">> FALHA: O valor [%d] nao existe nesta lista. Vareu O(n) atoa.\n", valor);
}

// ==========================================
// 3. O MENU INTERATIVO PARA O PROFESSOR
// ==========================================
int main() {
    // Inicializa a fila vazia
    No *lista = NULL;
    int opcao, valor;

    // Popula a lista com alguns dados iniciais s� para come�ar a aula legal
    inserirInicio(&lista, 33);
    inserirInicio(&lista, 22);
    inserirInicio(&lista, 11);

    do {
        imprimirLista(lista);

        printf("=== SIMULADOR DE LISTA ENCADEADA ===\n");
        printf("1. Inserir no Inicio  [ O(1) ]\n");
        printf("2. Inserir no Fim     [ O(n) ]\n");
        printf("3. Remover do Inicio  [ O(1) ]\n");
        printf("4. Remover do Fim     [ O(n) ]\n");
        printf("5. Buscar Valor       [ O(n) ]\n");
        printf("0. Sair\n");
        printf("Escolha uma operacao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o valor para inserir no inicio: ");
                scanf("%d", &valor);
                inserirInicio(&lista, valor);
                break;
            case 2:
                printf("Digite o valor para inserir no fim: ");
                scanf("%d", &valor);
                inserirFim(&lista, valor);
                break;
            case 3:
                removerInicio(&lista);
                break;
            case 4:
                removerFim(&lista);
                break;
            case 5:
                printf("Digite o valor que deseja buscar: ");
                scanf("%d", &valor);
                buscarValor(lista, valor);
                break;
            case 0:
                printf("Encerrando o simulador. Ate a proxima aula!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("--------------------------------------------------\n");

    } while(opcao != 0);

    return 0;
}
