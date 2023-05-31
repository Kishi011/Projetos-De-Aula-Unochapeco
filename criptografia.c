#include <stdio.h>

void encriptar(char*);
void inverte(char*, int);

int main() {
  int testes;
  scanf("%d ", &testes);
  char *texto;
  for(int i = 0; i < testes; i++) {
    scanf("%[^\n]%*c", texto);
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
  inverte(s, --i);
  int tam = i;
  while(tam >= i/2) {
    s[tam--] -= 1;
  }
}

void inverte(char *s, int tam) {
  int i = 0, j = tam;
  while(i < j) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++; j--;
  }
}
