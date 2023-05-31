#include <stdio.h>

void encriptar(char*);
void inverte(char*, int);

int main() {
  int testes;
  scanf("%d", &testes);
  char *texto;
  for(int i = 0; i < testes; i++) {
    scanf(" %[^\n]", texto);
    encriptar(texto);
    printf("%s\n", texto);
  }
  return 0;
}

void encriptar(char *s) {
  int i = 0;
  while(s[i] != '\0') {
    if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
      s[i] += 3;
    }
    i++;
  }
  int tam = ++i;
  inverte(s, tam);
}

void inverte(char *s, int tam) {
  int i = 0, j = tam;
  while(i++ < tam && --j >= 0) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
