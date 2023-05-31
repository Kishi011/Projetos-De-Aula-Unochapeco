#include <stdio.h>
#include <stdlib.h>

void sort(int tam, int *vetor);
int find(int tam, int num, int *vetor);

int main() {
    int qtd_marbles, qtd_consultas;
    int *marbles;
    int tentativa = 0;
    int casos = 1;
    do {
        scanf(" %d %d", &qtd_marbles, &qtd_consultas);
        if(qtd_marbles > 0 && qtd_consultas > 0) {
            marbles = (int*) malloc(qtd_marbles * sizeof(int));
            int tam = 0;
            for(int i = 0; i < qtd_marbles; i++) {
                scanf("%d", marbles+i);
                tam++;
            }
            sort(tam, marbles);
            int index = 0;
            printf("CASE# %d:\n", casos);
            for(int i = 0; i < qtd_consultas; i++) {
                scanf("%d", &tentativa);
                index = find(tam, tentativa, marbles);
                if(index >= 0) {
                    printf("%d found at %d\n", tentativa, index+1);
                } else {
                    printf("%d not found\n", tentativa);
                }
            }
            free(marbles);
        } else {
            break;
        }
        casos++;
    } while(1);
    return 0;
}

void sort(int tam, int *vetor) {
    int v = 0, j = 0;
    for(int i = 1; i < tam; i++) {
        v = vetor[i];
        j = i - 1;
        while(j >= 0 && vetor[j] > v) {
            vetor[j+1] = vetor[j];
            j--;
        }
       vetor[j+1] = v;
    }
}

int find(int tam, int num, int *vetor) {
    int i = 0;
    do {
        if(vetor[i] != num) {
            continue;
        } else {
            return i;
        }
    } while(++i < tam);
    return -1;
}
