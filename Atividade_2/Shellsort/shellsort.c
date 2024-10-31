#include <stdio.h>

// Função para realizar a ordenação por inserção
// Função de ordenação Shellsort que recebe o tamanho do array e um ponteiro para o array
void shellsort(int *v, int size){
    int i, j, h = 1, aux;

    // Define o valor inicial de 'h' usando a sequência 3x + 1 de Knuth
    for(; h < size; h = h * 3 + 1);

    // Loop principal do Shellsort, onde 'h' é reduzido a cada iteração
    do {
        h /= 3; // Reduz o intervalo 'h'

        // Realiza a ordenação por inserção para elementos espaçados por 'h'
        for(i = h; i < size; i++){
            aux = v[i]; // Guarda o elemento atual
            j = i;

            // Move os elementos do array para criar espaço para o 'aux' na posição correta
            while (j >= h && v[j - h] > aux) {
                v[j] = v[j - h];
                j -= h; // Ajusta o índice com o intervalo 'h'
            }
            v[j] = aux; // Coloca o elemento 'aux' na posição correta
        }
    } while (h != 1); // Continua até que 'h' seja 1 (última iteração)
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

    shellsort(vetor, tamanho); 


    for (i = 0; i < tamanho; i++) {
        printf("%i ", vetor[i]);
    }

    return 0; 
}
