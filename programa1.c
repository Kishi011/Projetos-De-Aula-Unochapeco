#include <stdio.h>
#include <stdbool.h>

float resultado(int op, float v1, float v2) {
    switch(op) {
        case 1: return v1 + v2;
                break;
        case 2: return v1 - v2;
                break;
        case 3: return v1 * v2;
                break;
        case 4: return v1 / v2;
                break;
        default: break;
    }
    return 0;
}

int main() {
    float v1, v2;
    int op;

    do {
        INICIO:
        printf("***************Escolha uma opcao***************\n");
        printf("1\t\t\tSOMA\n");
        printf("2\t\t\tSUBTRACAO\n");
        printf("3\t\t\tMULTIPLICACAO\n");
        printf("4\t\t\tDIVISAO\n");
        printf("5\t\t\tSAIR\n");
        scanf("%d", &op);
        if(op < 1 || op > 5) {
            printf("Selecione uma opcao valida!\n");
            goto INICIO;
        }
        if(op == 5) {
            break;
        }
        printf("Digite um numero: ");
        scanf("%f", &v1);
        printf("Digite outro numero: ");
        scanf("%f", &v2);
        printf("Resultado: %.2f\n", resultado(op, v1, v2));
    } while(true);

    return 0;
}