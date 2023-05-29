#include <stdio.h>

int fib(int n, int *num_calls);

int main() {
    int testes;
    scanf("%d", &testes);
    int n = 0;
    int num_calls;
    for(int i = 0; i < testes; i++) {
        num_calls = 0;
        scanf("%d", &n);
        printf("fib(%d) = %d calls = %d", n, fib(n, &num_calls), num_calls);
    }
    return 0;
}

int fib(int n, int *num_calls) {
    (*num_calls)++;
    if(n > 0) {
        n -= 1;
        return fib(n, num_calls);
    }
    return n;
}
