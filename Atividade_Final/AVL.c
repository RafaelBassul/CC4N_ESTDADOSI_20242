#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore AVL
typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
    int altura;
} No;

// Função para obter a altura de um nó
int obterAltura(No* no) {
    return no ? no->altura : 0;
}

// Função para calcular o fator de balanceamento
int calcularFatorBalanceamento(No* no) {
    if (!no) return 0;
    return obterAltura(no->esquerda) - obterAltura(no->direita);
}

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
    novoNo->altura = 1; // Altura inicial do nó é 1
    return novoNo;
}

// Função para realizar uma rotação à direita
No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    // Atualizando alturas
    y->altura = 1 + (obterAltura(y->esquerda) > obterAltura(y->direita) ? obterAltura(y->esquerda) : obterAltura(y->direita));
    x->altura = 1 + (obterAltura(x->esquerda) > obterAltura(x->direita) ? obterAltura(x->esquerda) : obterAltura(x->direita));

    return x;
}

// Função para realizar uma rotação à esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    // Atualizando alturas
    x->altura = 1 + (obterAltura(x->esquerda) > obterAltura(x->direita) ? obterAltura(x->esquerda) : obterAltura(x->direita));
    y->altura = 1 + (obterAltura(y->esquerda) > obterAltura(y->direita) ? obterAltura(y->esquerda) : obterAltura(y->direita));

    return y;
}

// Função para inserir um valor na árvore AVL
No* inserir(No* raiz, int chave) {
    if (!raiz) {
        return criarNo(chave);
    }

    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else if (chave > raiz->chave) {
        raiz->direita = inserir(raiz->direita, chave);
    } else {
        // Não permitimos chaves duplicadas
        return raiz;
    }

    // Atualizando altura do nó atual
    raiz->altura = 1 + (obterAltura(raiz->esquerda) > obterAltura(raiz->direita) ? obterAltura(raiz->esquerda) : obterAltura(raiz->direita));

    // Verificando o fator de balanceamento
    int balanceamento = calcularFatorBalanceamento(raiz);

    // Caso 1: Desbalanceado à esquerda
    if (balanceamento > 1 && chave < raiz->esquerda->chave) {
        return rotacaoDireita(raiz);
    }

    // Caso 2: Desbalanceado à direita
    if (balanceamento < -1 && chave > raiz->direita->chave) {
        return rotacaoEsquerda(raiz);
    }

    // Caso 3: Rotação dupla (esquerda-direita)
    if (balanceamento > 1 && chave > raiz->esquerda->chave) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    // Caso 4: Rotação dupla (direita-esquerda)
    if (balanceamento < -1 && chave < raiz->direita->chave) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
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

// Função principal
int main() {
    No* raiz = NULL;

    // Inserindo valores na árvore AVL
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 25);

    printf("Árvore AVL em ordem: ");
    exibirEmOrdem(raiz);
    printf("\n");

    return 0;
}
