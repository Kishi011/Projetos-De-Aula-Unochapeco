#include "stdio.h"

int testes = -1;
int i = 0;

float media(int, int);

typedef struct {
  int moradores;
  int consumo;
  int consumoMedia;
} registro;


int main() {
  int contCidade = 1;
  int moradores = 0, consumo = 0;
  int totalMoradores = 0, totalConsumo = 0;
  do {
    scanf("%d", &testes);
    if(testes != 0) {
      for(i = 0; i < testes; i++) {
        scanf("%d %d", &moradores, &consumo);
        totalMoradores += moradores;
        totalConsumo += consumo;
      }
      printf("Cidade# %d:\n", contCidade);
      printf("Consumo medio: %.2f m3.\n", media(totalMoradores, totalConsumo));
      contCidade++;
    } else {
      break;
    }
  } while(1);
  return 0;
}

float media(int moradores, int consumo) {
  return consumo / moradores;
}