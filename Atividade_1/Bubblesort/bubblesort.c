#include <stdio.h>

// Função para ordenar um vetor usando o algoritmo Bubble Sort
void bubblesort(int *vetor, int tamanho) {
    int i, j, aux; // Variáveis de controle e auxiliar para a troca

    // Laço externo para percorrer todo o vetor
    for(i = 0; i < tamanho; i++) {
        // Laço interno para comparar elementos adjacentes
        for(j = 0; j < tamanho - 1; j++) {
            // Se o elemento atual for maior que o próximo, troca-os
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];     // Armazena o valor atual
                vetor[j]     = vetor[j + 1]; // Troca com o próximo
                vetor[j + 1] = aux;          // Coloca o valor armazenado na nova posição
            }
        }
    }
}


int main() {
    int tamanho = 50; 
    int i; 
    int vetor[50] = {
        12, 45, -23, 56, 78, 90, -1, 34, 67, -9,
        22, 11, 98, -33, 15, 24, 62, -77, 89, 43,
        50, -20, 31, 29, -40, 17, 71, -10, 81, 37,
        94, -55, 63, -66, 85, -19, 10, 46, 68, 21,
        32, -8, 49, 58, 27, -5, 73, 88, 39, -42
    };

    bubblesort(vetor, tamanho);

    for(i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]); 
    }

    return 0; 
}
