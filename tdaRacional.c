#include <stdio.h>
#include <stdbool.h>

void calculaFracao(int n1, int d1, int n2, int d2, char operacao);
void simplifica(int n, int d);

int inverteValor(int n);

int main() {
    int testes;
    char operador[testes];
    scanf("%d", &testes);
    int n1[testes], n2[testes], d1[testes], d2[testes];
    char barra;
    for(int i = 0; i < testes; i++) {
        scanf("%d %c %d %c %d %c %d", &n1[i], &barra, &d1[i], &operador[i], &n2[i], &barra, &d2[i]);
    }
    for(int i = 0; i < testes; i++) {
        calculaFracao(n1[i], d1[i], n2[i], d2[i], operador[i]);
    }
    return 0;
}

void calculaFracao(int n1, int d1, int n2, int d2, char operacao) {
    switch(operacao) {
        case '+': simplifica(((n1*d2) + (n2*d1)), (d1*d2)); break;
        case '-': simplifica(((n1*d2) - (n2*d1)), (d1*d2)); break;
        case '*': simplifica((n1*n2), (d1*d2)); break;
        case '/': simplifica((n1*d2), (n2*d1)); break;
        default: break;
    }
}

void simplifica(int n, int d) {
    printf("%d/%d ", n, d);
    bool nEraNegativo = false;
    bool dEraNegativo = false;
    if(n < 0) {
        nEraNegativo = true;
        n *= -1;
    }
    if(d < 0) {
        dEraNegativo = true;
        d *= -1;
    }
    int menor = n < d ? n : d;
    for(int i = 1; i <= menor; i++) {
        if(n %i == 0 && d %i == 0) {
            n /= i;
            d /= i;
            i = 1;
        }
    }
    if(nEraNegativo) {
        n *= -1;
    }
    if(dEraNegativo) {
        d *= -1;
    }
    printf("= %d/%d\n", n, d);
}