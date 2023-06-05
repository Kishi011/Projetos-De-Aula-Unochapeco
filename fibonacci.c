#include "stdio.h"

int fib(int, int*);

int main() {
  int testes = 0;
  scanf("%d", &testes);
  int num_calls = -1;
  int *pnum_calls = &num_calls;
  int i = 0, n = 0, result = 0;
  for(i = 0; i < testes; i++) {
    *pnum_calls = -1;
    n = 0;
    scanf("%d", &n);
    result = fib(n, pnum_calls);
    printf("fib(%d) = %d calls = %d\n", n, *pnum_calls, result);
  }
  return 0;
}

int fib(int n, int *num_calls) {
  (*num_calls)++;
  if (n <= 1)
    return n;
  else
    return (fib(n-1, num_calls) + fib(n-2, num_calls));
}
