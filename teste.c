#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tamanho = 5;

void preenche(int*);
void matriz_transposta(int*);
void imprime(int*);
void matriz_identidade(int *m);

int main() {
    srand(time(NULL));
    int matriz[tamanho][tamanho];
    preenche(matriz[0]);
    imprime(matriz[0]);
    matriz_transposta(matriz[0]);
    return 0;
}

void preenche(int* m) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            m[(i * tamanho) + j] = (rand()%51);
        }
    }
}

void imprime(int *m) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            printf("[%d] ", m[(i * tamanho) + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matriz_transposta(int *m) {
    int contador = 0;
    int coluna = 1;
    for(int i = 0; i < (tamanho*tamanho); i++) {
        printf("[%d] ", m[contador]);
        contador += tamanho;
        if(contador >= (tamanho*tamanho)) {
            contador = coluna++;
            printf("\n");
        }
    }
}

void matriz_identidade(int *m) {
    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            m
        }
    }
}
