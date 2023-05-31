#include <stdio.h>

int soma(int *s, int *vetor) {
    int i = 0;
    *s += vetor[i];
    return soma(s, vetor);
}

int main() {
    int vetor[10];
    int s = 0;
    int *ptrS = &s;
    for(int i = 1; i <= 10; i++) {
        vetor[i] = i;
    }
    soma(ptrS, vetor);
    return 0;
}