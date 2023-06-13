#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 300

int arr[MAX];

int main(void)
{
    int i, j, N, c = 1;

    int X, Y, ta, tp, fp;

    double ip;

    int bo = 0;

    while (scanf("%d", &N) && N)
    {
        if (bo)
        {
            printf("\n");
        }
        bo = 1;

        ta = tp = 0;

        memset(arr, 0, sizeof(arr)); //é usado para preencher um bloco de memória com um valor específico. (todos os espaços vão ser 0)

        for (i = 0; i < N; ++i)
        {
            scanf("%d %d", &X, &Y);

            ta += Y;

            tp += X;

            arr[Y / X] += X; // armazena o valor de quantidade de pessoa no indice que representa o consumo ex indice 7 (consumo) valor 3 qtd pessoa
        }

        printf("Cidade# %d:\n", c);

        c++;

        for (i = 0, j = 0; i < MAX; i++)
        {
            if (arr[i] > 0)
            {
                if (j != 0)
                {
                    printf(" ");
                }
                printf("%d-%d", arr[i], i);

                j++;
            }
        }

        printf("\n");

        fp = (int)(modf((double)ta / tp, &ip) * 100); //retorna o componente de fração (parte após o decimal) e define inteiro como o componente de número inteiro.

        if (fp < 10)
        {
             printf("Consumo medio: %d.0%d m3.\n", (int)ip, (int)fp);
        }

        else
        {
             printf("Consumo medio: %d.%d m3.\n", (int)ip, (int)fp);
        }
    }

    return 0;
}