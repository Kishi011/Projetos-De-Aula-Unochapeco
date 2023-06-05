#include "stdio.h"

void encriptar();
void inverte(int);

char texto[50];
int main() {
  int testes;
  scanf("%d", &testes);
  for(int i = 0; i < testes; i++) {
    scanf(" %[^\n]", texto);
    encriptar(texto);
    printf("%s\n", texto);
  }
  return 0;
}

void encriptar() {
  int tam = 0;
  while(texto[tam] != '\0') {
    if(texto[tam] >= 'A' && texto[tam] <= 'Z' || texto[tam] >= 'a' && texto[tam] <= 'z') {
      texto[tam] += 3;
    }
    tam++;
  }
  inverte(tam);
  int i = 0, j = tam-1;
  while(j >= i) {
    texto[j] -= 1;
    j--; i++;
  }
}

void inverte(int tam) {
  int i = 0,  j = tam-1;
  while(i < j) {
    char aux = texto[j];
    texto[j] = texto[i];
    texto[i] = aux;
    i++; j--;
  }
}
