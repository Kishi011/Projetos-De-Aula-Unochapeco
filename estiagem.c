#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Imovel {
  int moradores;
  int consumo;
  int mediaConsumo;
  int totalMoradores;
  int totalConsumo;
} Imovel;

double calculaMedia(int *m, int *c);

int main() {
  int imoveis = 0;
  int contCidades = 1;
  do {
    scanf("%d", &imoveis);
    if(imoveis != 0) {
      Imovel im;
      im.totalMoradores = 0, im.totalConsumo = 0;
      int maiorMedia = 0;
      int menorMedia = 0;
      int mediaMoradores = 0;
      for(int i = 0; i < imoveis; i++) {
        scanf("%d %d", &im.moradores, &im.consumo);
        im.mediaConsumo = floor(calculaMedia(&im.moradores, &im.consumo));
        if(i == 0) {
          menorMedia = im.mediaConsumo;
        }
        if(maiorMedia < im.mediaConsumo) {
          maiorMedia = im.mediaConsumo;
        }
        if(menorMedia > im.mediaConsumo) {
          menorMedia = im.mediaConsumo;
        }
        im.totalMoradores += im.moradores;
        im.totalConsumo += im.consumo;
      }
      printf("\nCidade# %d:\n", contCidades);
      printf("Consumo medio: %.2lf m3.\n", calculaMedia(&im.totalMoradores, &im.totalConsumo));
      contCidades++;
    } else {
      break;
    }
  } while(1);
  return 0;
}

double calculaMedia(int *m, int *c) {
  return *c / *m;
}
