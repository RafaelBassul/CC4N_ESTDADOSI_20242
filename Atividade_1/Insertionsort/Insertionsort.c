#include <stdio.h>

// Função para realizar a ordenação por inserção
void insertion(int *vetor, int tamanho) {
    int i, j, aux; // Declaração de variáveis: i e j para iteração, aux para armazenar o elemento atual

    // Laço que percorre o vetor começando do segundo elemento
    for (i = 1; i < tamanho; i++) {
        aux = vetor[i]; // Armazena o elemento atual (chave) a ser inserido na sublista ordenada
        j = i - 1; // j é inicializado para o índice do último elemento da sublista ordenada

        // Laço para mover os elementos maiores que aux para a direita
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j]; // Move o elemento para a direita
            j--; // Decrementa j para verificar o próximo elemento da sublista
        }
        // Insere o elemento auxiliar (aux) na posição correta
        vetor[j + 1] = aux;
    }
}

int main() {
    int tamanho = 50, i; 
    int vetor[50] = { 
        12, 45, -23, 56, 78, 90, -1, 34, 67, -9,
        22, 11, 98, -33, 15, 24, 62, -77, 89, 43,
        50, -20, 31, 29, -40, 17, 71, -10, 81, 37,
        94, -55, 63, -66, 85, -19, 10, 46, 68, 21,
        32, -8, 49, 58, 27, -5, 73, 88, 39, -42
    };

    insertion(vetor, tamanho); 


    for (i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]);
    }

    return 0; 
}
