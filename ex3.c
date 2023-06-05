/**
 * Exiba o cardápio na tela para o usuário escolher e digitar o código do produto e a quantidade desse produto escolhido. 
 * Calcule o valor a ser pago por aquele(s) produto(s). Depois informe o dinheiro dado pelo cliente e verifique se é necessário dar troco. Se sim, informe o valor do troco na tela. 
 * */

#include <stdio.h>

void exibeMenu();

typedef struct Pedido {
  int codigo;
  int qtd;
} Pedido;

Pedido fazPedido();
double calculaValorPedido(Pedido p);
double efetuaPagamento(double valorPedido);

int main() {
  exibeMenu();
  Pedido pedido = fazPedido();
  efetuaPagamento(calculaValorPedido(pedido));  
  return 0;
}

void exibeMenu() {
  printf("%-20s %-20s %-20s\n", "Produto", "Codigo", "Valor");
  printf("%-20s %-20s %-20s\n", "-------", "------", "-----");
  printf("%-20s %-20s %-20s\n", "Pipoca", "100", "R$ 3.00");
  printf("%-20s %-20s %-20s\n", "Cachorro-quente", "101", "R$ 6.00");
  printf("%-20s %-20s %-20s\n", "Coxinha", "102", "R$ 7.00");
  printf("%-20s %-20s %-20s\n", "Pastel", "103", "R$ 6.00");
  printf("%-20s %-20s %-20s\n", "Cheeseburguer", "104", "R$ 16.00");
  printf("%-20s %-20s %-20s\n", "Refrigerante", "105", "R$ 5.00");
}

Pedido fazPedido() {
  Pedido p;
  CODIGO:
    printf("Digite o codigo do seu pedido: ");
    scanf("%d", &p.codigo);
    if(p.codigo < 100 || p.codigo > 105) {
      printf("Insira um codigo valido!\n");
      goto CODIGO;
    }
    printf("Informe a quantidade desejada: ");
    scanf("%d", &p.qtd);
  return p;
}

double calculaValorPedido(Pedido p) {
  double valor = 0;
  switch(p.codigo) {
    case 100: valor = 3.00 * p.qtd; break;
    case 101: valor = 6.00 * p.qtd; break;
    case 102: valor = 7.00 * p.qtd; break;
    case 103: valor = 6.00 * p.qtd; break;
    case 104: valor = 16.00 * p.qtd; break;
    case 105: valor = 5.00 * p.qtd; break;
    default: break;
  }
  printf("Valor do pedido: R$ %.2lf\n", valor);
  return valor;
}

double efetuaPagamento(double valorPedido) {
  printf("Informe o valor a ser pago: R$ ");
  double valor;
  scanf("%lf", &valor);
  if(valor < valorPedido) {
    printf("Valor insuficiente seu pobre! Vai ficar sem comer\n");
  } else if(valor > valorPedido) {
    double troco = valor - valorPedido;
    printf("O troco sera de: R$ %.2lf\n", troco);
  } else {
    printf("O valor pago foi igual ao valor do produto, sem troco.\n");
  }
}
