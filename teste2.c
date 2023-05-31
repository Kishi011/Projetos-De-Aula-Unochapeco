#include <stdio.h>

void mostra(char *nome) {
    int i = 0;
    while (nome[i] != '\0') {
        printf("%c", nome[i]);
        i++;
    }
    printf("\n");
}

void inverte(char *v, int n) {
    int i = 0;
    int f = n-1;
    while(i < f) {
        char temp = v[i];
        v[i] = v[f];
        v[f] = temp;
        i++; f--;
    }
}

int main() {
    char nome[] = {'V', 'i', 'n', 'i', 'c', 'i', 'u', 's', '\0'};
    inverte(nome, 8);
    mostra(nome);
}