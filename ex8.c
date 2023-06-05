/**
 * Crie um algoritmo que leia um número entre 5 e 20 e gere a saída com a seguinte configuração:
 * Digite um número:
 * */

#include <stdio.h>

int leNumero();
int mostraLista(int n);

int main() {
  mostraLista(leNumero());
  return 0;
}

int leNumero() {
  int n = 0;
  printf("Digite um numero: ");
  scanf("%d", &n);
  if(n <= 5 || n >= 20) {
    printf("Numero invalido!\n");
  }
  return n;
}

int mostraLista(int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i > j) {
        printf("x");
        continue;
      }
      printf("%d", (j-i) + 1);
    }
    printf("\n");
  }
}
