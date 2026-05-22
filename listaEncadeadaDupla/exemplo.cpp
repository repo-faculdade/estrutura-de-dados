#include <stdio.h>
#include <stdlib.h>

// ==========================================
// 1. A NOVA ANATOMIA (O Nó de Três Partes)
// ==========================================
typedef struct NoDuplo {
    struct NoDuplo *anterior;  // O Retrovisor
    int cpf;                   // A Carga Útil (Payload)
    struct NoDuplo *proximo;   // O Para-brisa
} NoDuplo;

// ==========================================
// FUNÇÃO VISUAL: PROVANDO A VIA DE MÃO DUPLA
// ==========================================
void imprimirIdaEVolta(NoDuplo *head) {
    if (head == NULL) {
        printf("Fila vazia!\n\n");
        return;
    }

    NoDuplo *atual = head;
    NoDuplo *ultimo = NULL;

    printf("\n--- NAVEGANDO PARA FRENTE (Head -> Tail) ---\n");
    printf("NULL <- ");
    while (atual != NULL) {
        printf("[ %d ]", atual->cpf);
        if (atual->proximo != NULL) printf(" <==> ");
        
        ultimo = atual; // Guarda o último nó antes de cair no abismo (NULL)
        atual = atual->proximo;
    }
    printf(" -> NULL\n");

    printf("--- DANDO MARCHA A RE (Tail -> Head) -----\n");
    printf("NULL <- ");
    while (ultimo != NULL) {
        printf("[ %d ]", ultimo->cpf);
        if (ultimo->anterior != NULL) printf(" <==> ");
        
        ultimo = ultimo->anterior; // Usando o retrovisor!
    }
    printf(" -> NULL\n\n");
}

// ==========================================
// 2. INSERÇÕES
// ==========================================

// Inserir no Início (O(1))
void inserirInicio(NoDuplo **head, int cpf) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->cpf = cpf;
    novo->anterior = NULL; // Como é o primeiro, ninguém está atrás
    novo->proximo = *head; // O para-brisa aponta pro antigo primeiro

    // Se a fila não estava vazia, o antigo primeiro precisa olhar para trás e ver o novo nó
    if (*head != NULL) {
        (*head)->anterior = novo;
    }

    *head = novo; // O sistema reconhece o novo Head
    printf(">> [%d] Inserido no INICIO.\n", cpf);
}

// Inserir no Fim (O(n) - Sem ponteiro Tail)
void inserirFim(NoDuplo **head, int cpf) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->cpf = cpf;
    novo->proximo = NULL; // Como é o último, não tem ninguém na frente

    if (*head == NULL) {
        novo->anterior = NULL;
        *head = novo;
        printf(">> [%d] Inserido no FIM (Fila estava vazia).\n", cpf);
        return;
    }

    // Varre até achar o último
    NoDuplo *atual = *head;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    // Conecta os vizinhos
    atual->proximo = novo;  // O antigo último aponta para frente (pro novo)
    novo->anterior = atual; // O novo olha para trás (pro antigo último)
    printf(">> [%d] Inserido no FIM.\n", cpf);
}

// A DANÇA DOS 4 PONTEIROS: Inserir no Meio (Após um alvo)
void inserirMeio(NoDuplo **head, int cpf_alvo, int novo_cpf) {
    NoDuplo *atual = *head;

    // Busca o cidadão alvo
    while (atual != NULL && atual->cpf != cpf_alvo) {
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf(">> Erro: CPF [%d] nao encontrado para inserir no meio!\n", cpf_alvo);
        return;
    }

    // Criamos o novo nó (o "Fura-Fila")
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->cpf = novo_cpf;

    // 1 e 2: O novo nó segura a mão de quem está na frente e atrás
    novo->proximo = atual->proximo; 
    novo->anterior = atual;         

    // 3: Se existir alguém na frente, esse alguém precisa soltar o 'atual' e segurar o 'novo' pelo retrovisor
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novo; 
    }

    // 4: O alvo original solta quem estava na frente e passa a segurar o novo
    atual->proximo = novo; 

    printf(">> [%d] Inserido LOGO APOS o [%d].\n", novo_cpf, cpf_alvo);
}

// Inserir Ordenado (Mantém a fila sempre organizada - Excelente para prioridades)
void inserirOrdenado(NoDuplo **head, int cpf) {
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));
    novo->cpf = cpf;

    // Caso 1: Fila vazia ou novo elemento é menor que o Head (Vira o novo primeiro)
    if (*head == NULL || (*head)->cpf >= cpf) {
        novo->anterior = NULL;
        novo->proximo = *head;
        if (*head != NULL) (*head)->anterior = novo;
        *head = novo;
        printf(">> [%d] Inserido ORDENADO (no inicio).\n", cpf);
        return;
    }

    // Caso 2: Varre até achar o ponto de inserção
    NoDuplo *atual = *head;
    while (atual->proximo != NULL && atual->proximo->cpf < cpf) {
        atual = atual->proximo;
    }

    // Costura o novo nó entre 'atual' e 'atual->proximo'
    novo->proximo = atual->proximo;
    novo->anterior = atual;
    printf("%d\n", atual->proximo->anterior->cpf);
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novo;
        printf("Entrou no IF: %d\n", atual->proximo->anterior->cpf);
    }
    atual->proximo = novo;

    printf(">> [%d] Inserido ORDENADO (no meio/fim).\n", cpf);
}

// ==========================================
// 3. REMOÇÕES
// ==========================================

// Remover do Início
void removerInicio(NoDuplo **head) {
    if (*head == NULL) return;

    NoDuplo *removido = *head;
    *head = removido->proximo; // O segundo passa a ser o primeiro

    if (*head != NULL) {
        (*head)->anterior = NULL; // O novo primeiro não olha mais para o apagado
    }

    printf(">> [%d] Removido do INICIO.\n", removido->cpf);
    free(removido);
}

// Remover do Fim
void removerFim(NoDuplo **head) {
    if (*head == NULL) return;

    NoDuplo *atual = *head;

    // Vai até o último
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    // Se o anterior for NULL, significa que só tinha 1 elemento na fila
    if (atual->anterior == NULL) {
        *head = NULL;
    } else {
        atual->anterior->proximo = NULL; // O penúltimo corta a relação com o último
    }

    printf(">> [%d] Removido do FIM.\n", atual->cpf);
    free(atual);
}

// ==========================================
// MAIN (Testando o Sistema)
// ==========================================
int main() {
    NoDuplo *fila_cras = NULL;

    printf("--- INICIANDO OS TESTES DA LISTA DUPLA ---\n");

    inserirInicio(&fila_cras, 500);
    inserirInicio(&fila_cras, 300);
    inserirFim(&fila_cras, 800);
    
    imprimirIdaEVolta(fila_cras); // Vai imprimir 300 <==> 500 <==> 800

    inserirMeio(&fila_cras, 500, 600); // Insere o 600 logo após o 500
    
    imprimirIdaEVolta(fila_cras); // Vai imprimir 300 <==> 500 <==> 600 <==> 800

    removerInicio(&fila_cras); // Tira o 300
    removerFim(&fila_cras);    // Tira o 800

    imprimirIdaEVolta(fila_cras); // Vai sobrar 500 <==> 600

    // Testando a inserção ordenada (Fila separada para limpar o teste)
    printf("--- LIMPANDO E TESTANDO ORDENACAO ---\n");
    NoDuplo *fila_prioridade = NULL;
    inserirOrdenado(&fila_prioridade, 90);
    inserirOrdenado(&fila_prioridade, 10);
    inserirOrdenado(&fila_prioridade, 50);
    inserirOrdenado(&fila_prioridade, 30);
    
    imprimirIdaEVolta(fila_prioridade); // Vai imprimir 10 <==> 30 <==> 50 <==> 90

    return 0;
}