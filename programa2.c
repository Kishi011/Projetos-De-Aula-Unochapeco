#include <stdio.h>
#include <string.h>

int minhaFuncao(char *string) {
    int tam = 0;
    while(string[tam] != '\0') {
        tam++;
    }
    return tam;
}

int main() {
    char string[30];
    scanf("%[^\n]", string);
    printf("Tamanho da String: %d\n", minhaFuncao(string));
    printf("%s\n", string);
    return 0;
}