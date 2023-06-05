#include "stdio.h"

int main() {
  int unsigned long x, y;
  while(scanf("%lu", &x) != EOF) {
    scanf("%lu", &y);
    printf("%lu\n", x ^ y);
  }
  return 0;
}