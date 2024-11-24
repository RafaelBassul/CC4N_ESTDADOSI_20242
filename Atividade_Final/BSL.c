#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore
typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criarNo(chave);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    }
    return raiz;
}

// Função para buscar um valor na árvore
No* buscar(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }
    if (chave < raiz->chave) {
        return buscar(raiz->esquerda, chave);
    }
    return buscar(raiz->direita, chave);
}

// Função para encontrar o menor valor (mínimo) na árvore
No* encontrarMinimo(No* raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

// Função para remover um valor da árvore
No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        return raiz;
    }
    if (chave < raiz->chave) {
        raiz->esquerda = remover(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = remover(raiz->direita, chave);
    } else {
        // Caso 1: Nó com zero ou um filho
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Caso 2: Nó com dois filhos
        No* temp = encontrarMinimo(raiz->direita);
        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }
    return raiz;
}

// Função para exibir a árvore em ordem
void exibirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        exibirEmOrdem(raiz->direita);
    }
}


int main() {
    No* raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Árvore em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    // Removendo um valor
    printf("Removendo 20...\n");
    raiz = remover(raiz, 20);
    printf("Árvore em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    printf("Removendo 30...\n");
    raiz = remover(raiz, 30);
    printf("Árvore em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    printf("Removendo 50...\n");
    raiz = remover(raiz, 50);
    printf("Árvore em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    return 0;
}
