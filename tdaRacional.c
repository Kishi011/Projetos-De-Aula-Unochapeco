#include <stdio.h>

void calculaFracao(int n1, int d1, int n2, int d2, char operacao);
void simplifica(int n, int d);
int maximoDivisorComum(int m, int n);
void simplificaNovo(int n, int d);

int main() {
    int qtdCalculos;
    char  operacao;
    scanf("%d", &qtdCalculos);
    int n1, n2, d1, d2;

    while (qtdCalculos--) {
        scanf("%d %*c %d %c %d %*c %d", &n1, &d1, &operacao, &n2, &d2);
        calculaFracao(n1, d1, n2, d2, operacao);
    }
    return 0;
}

int maximoDivisorComum(int m, int n)
{
    m = m < 0 ? -m : m;
    n = n < 0 ? -n : n;

    if (m % n == 0)
        return n;
    else
        return maximoDivisorComum(n, m % n);
}

void simplificaNovo(int n, int d){
    printf("%d/%d ", n, d);
    int n2 = n/maximoDivisorComum(n, d);
    int d2 = d/maximoDivisorComum(n, d);
    printf("= %d/%d\n", n2, d2);
}

void calculaFracao(int n1, int d1, int n2, int d2, char operacao) {
    switch(operacao) {
        case '+': simplificaNovo(((n1*d2) + (n2*d1)), (d1*d2)); break;
        case '-': simplificaNovo(((n1*d2) - (n2*d1)), (d1*d2)); break;
        case '*': simplificaNovo((n1*n2), (d1*d2)); break;
        case '/': simplificaNovo((n1*d2), (n2*d1)); break;
        default: break;
    }
}