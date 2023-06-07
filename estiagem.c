#include "stdio.h"
#include "stdlib.h"

int testes = -1;
int i = 0;

float media(int, int);

typedef struct registro {
  int moradores;
  int consumo;
  int consumoMedia;
} registro;

int main() {
  int contCidade = 1;
  int totalMoradores = 0, totalConsumo = 0;
  while(1) {
    scanf("%d", &testes);
    registro *r[testes];
    if(testes != 0) {
      for(i = 0; i < testes; i++) {
        r[i] = malloc(sizeof(registro));
        scanf("%d %d", &r[i]->moradores, &r[i]->consumo);
        r[i]->consumoMedia = media(r[i]->moradores, r[i]->consumo);
        totalMoradores += r[i]->moradores;
        totalConsumo += r[i]->consumo;
      }
      printf("Cidade# %d:\n", contCidade);
      printf("Consumo medio: %.2f m3.\n", media(totalMoradores, totalConsumo));
      contCidade++;
    } else {
      break;
    }
  }
  return 0;
}

float media(int moradores, int consumo) {
  return consumo / moradores;
}