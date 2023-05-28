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
  int tam = 0;
  while(s[tam] != '\0') {
    if(s[tam] >= 'A' && s[tam] <= 'Z' || s[tam] >= 'a' && s[tam] <= 'z') {
      s[tam] += 3;
    }
    tam++;
  }
  inverte(s, tam);
  for(int i = (int)(tam/2); i < tam; i++) {
    s[i] -= 1;
  }
}

void inverte(char *s, int tam) {
  for(int i = 0; i < (int)(tam/2); i++) {
    char temp = s[i];
    s[i] = s[(tam-i)-1];
    s[(tam-i)-1] = temp;
  }
}
