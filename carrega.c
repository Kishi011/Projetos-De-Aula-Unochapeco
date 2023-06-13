#include "stdio.h"

int main() {
  int unsigned long x, y;
  while(scanf("%lu %lu", &x, &y)) {
    printf("%lu\n", x ^ y);
  }
  return 0;
}