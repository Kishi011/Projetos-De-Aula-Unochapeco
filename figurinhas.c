#include "stdio.h"

int mdc(int f1, int f2);

int main() {
  int testes = 0;
  scanf("%d", &testes);
  int f1 = 0, f2 = 0;
  int i = 0;
  for(i = 0; i < testes; i++) {
    scanf("%d %d", &f1, &f2);
    printf("%d\n", mdc(f1, f2));
  }
  return 0;
}

int mdc(int f1, int f2) {
  if(f1 % f2 == 0)
    return f2;
  else
    return mdc(f2, f1 % f2);
}
