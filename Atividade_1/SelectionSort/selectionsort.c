#include <stdio.h>

// Função para realizar a ordenação por seleção
void selection(int *vetor, int tamanho) {
    int i, j, aux, menorindice; // Declaração de variáveis: i e j para iteração, aux para troca, menorindice para o índice do menor elemento

    // Laço que percorre todos os elementos do vetor
    for(i = 0; i < tamanho; i++) {
        menorindice = i; // Assume que o primeiro elemento não ordenado é o menor
        // Laço para encontrar o menor elemento no vetor não ordenado
        for(j = i + 1; j < tamanho; j++) { // Começa de i + 1 para evitar comparar o menor atual com ele mesmo
            if(vetor[j] < vetor[menorindice]) { // Se o elemento atual for menor que o menor encontrado
                menorindice = j; // Atualiza o índice do menor elemento
            }
        }
        // Troca o elemento na posição i com o menor elemento encontrado
        int aux = vetor[i]; // Armazena o valor atual em aux
        vetor[i] = vetor[menorindice]; // Coloca o menor elemento na posição atual
        vetor[menorindice] = aux; // Coloca o elemento atual na posição do menor
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

    selection(vetor, tamanho); 

    for(i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]); 
    }

    return 0; 
}
