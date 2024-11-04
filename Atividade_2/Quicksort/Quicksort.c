#include <stdio.h>

// Função auxiliar para trocar dois elementos no array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de particionamento usando o primeiro elemento como pivô
int particionar(int arr[], int inicio, int fim) {
    int pivo = arr[inicio]; // Primeiro elemento como pivô
    int i = inicio + 1;     // Índice da esquerda
    int j = fim;            // Índice da direita

    while (1) {
        // Avança o índice da esquerda até encontrar um valor maior ou igual ao pivô
        while (i <= j && arr[i] <= pivo) {
            i++;
        }
        // Avança o índice da direita até encontrar um valor menor ou igual ao pivô
        while (i <= j && arr[j] > pivo) {
            j--;
        }
        // Se os índices se cruzaram, a partição está completa
        if (i > j) {
            break;
        }
        // Troca os elementos fora de ordem
        trocar(&arr[i], &arr[j]);
    }

    // Coloca o pivô na posição correta
    trocar(&arr[inicio], &arr[j]);

    // Retorna o índice do pivô
    return j;
}

// Função recursiva do Quicksort
void quicksort_rec(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Particiona o array e obtém o índice do pivô
        int indicePivo = particionar(arr, inicio, fim);
        // Ordena recursivamente as sublistas à esquerda e à direita do pivô
        quicksort_rec(arr, inicio, indicePivo - 1);
        quicksort_rec(arr, indicePivo + 1, fim);
    }
}

void quicksort(int arr[], int tamanho) {
    quicksort_rec(arr, 0, tamanho - 1);
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

    quicksort(vetor, tamanho);


    for (i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]);
    }

    return 0; 
}
