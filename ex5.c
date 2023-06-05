/**
 * a) A partir de um dia e um mês informado pelo usuário, calcule quantos dias se passaram desta data informada desde 1º de janeiro deste ano de 2023.
 * b) A saída deve ser assim: "Total de dias desde 01/01 até [dia]/[mês]: [xxx] dias"; onde [dia] e [mês] foram informados pelo usuário e [xxx] são os dias calculados.
 * */

#include <stdio.h>

typedef struct Data {
  int dia;
  int mes;
} Data;

Data defineData();
int calculaDias(Data d);

int main() {
  Data data = defineData();
  int dias = calculaDias(data);
  printf("Total de dias desde 01/01 ate %d/%d: %d", data.dia, data.mes, dias);
  return 0;
}

Data defineData() {
  Data d;
  DEFINE_DATA:
    printf("Informe um dia: ");
    scanf("%d", &d.dia);    
    printf("Informe um mes: ");
    scanf("%d", &d.mes);
    if(d.dia < 1 || d.dia > 31
    || d.mes < 0 || d.mes > 12) {
      printf("Informe uma data valida!\n");
      goto DEFINE_DATA;
    }
  return d;
}

int calculaDias(Data d) {
  int dias = 0;
  dias = d.dia + (d.mes * 30);
  return dias;
}
