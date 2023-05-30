#include <stdio.h>

int find(int *v, int *num);

int main() {
    int casos = 1;
    int qtd_marbles = 0, qtd_consultas = 0;
    int tentativa = 0;
    do {
        scanf(" %d %d", &qtd_marbles, &qtd_consultas);
        if(!(qtd_marbles <= 0 && qtd_consultas <= 0)) {
            int marbles[qtd_marbles];
            int tam = sizeof(marbles) / sizeof(marbles[0]);
            for(int i = 0; i < tam; i++) {
                scanf("%d", marbles+i);
            }
            for(int i = 0; i < qtd_consultas; i++) {
                scanf("%d", &tentativa);
                int index = find(marbles, &tentativa);
                if(index != 0) {
                    printf("%d found at %d\n", tentativa, index);
                    break;
                }
            }
        } else {
            break;
        }
        casos++;
    } while(1);
    
    return 0;
}

int find(int *v, int *num) {
    int tam = sizeof(v)/sizeof(v[0]);
    for(int i = 0; i < tam; i++) {
        if(*num == v[i]) {
            return *num;
        }
    }
    printf("%d not found\n", *num);
    return 0;
}
