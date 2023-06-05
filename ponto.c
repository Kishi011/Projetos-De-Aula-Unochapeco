#include "stdio.h"

int main() {
  int testes = 0;
  scanf("%d", &testes);
  short x, y; short xtemp, ytemp;
  int qtdPontos = 0;
  int i = 0;
  do {
    scanf("%hu %hu", &x, &y);
    if(qtdPontos <= 0) {
      qtdPontos++;
      xtemp = x; ytemp = y;
    }
    if(x != xtemp && (ytemp+2 == y || ytemp-2 == y) && (y >= -1 && y <= 1)) {
      qtdPontos++;
      xtemp = x; ytemp = y;
    }
    i++;
  } while(i < testes);  
  printf("%d\n", qtdPontos);
  return 0;
}