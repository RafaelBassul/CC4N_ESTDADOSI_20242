#include <stdio.h>

// Função para trocar dois elementos no array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para criar o heap máximo
void heapify(int arr[], int n, int i) {
    int maior = i;         // Inicializa o maior como raiz
    int esq = 2 * i + 1;   // Filho à esquerda
    int dir = 2 * i + 2;   // Filho à direita

    // Se o filho à esquerda é maior que a raiz
    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    // Se o filho à direita é maior que o maior atual
    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    // Se o maior não for a raiz
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);

        // Heapifica o sub-árvore afetado
        heapify(arr, n, maior);
    }
}

// Função Heap Sort
void heapSort(int arr[], int n) {
    // Constrói o heap máximo (reorganiza o array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extrai os elementos um a um do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (maior) para o fim
        trocar(&arr[0], &arr[i]);

        // Chama o heapify na árvore reduzida
        heapify(arr, i, 0);
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

    heapSort(vetor, tamanho);

    for (i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]);
    }

    return 0;
}
