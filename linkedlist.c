#include "stdio.h"
#include "stdlib.h"

typedef struct {
  void *prox;
  int valor;
} Lista;

Lista *head = NULL;

// adiciona na lista

Lista *adiciona(int valor) {
  Lista *novo = malloc(sizeof(Lista));

  if(head == NULL) {
    head = novo;
    novo->valor = valor;
    novo->prox = NULL;
  } else {
    novo->valor = valor;
    novo->prox = head;
    head = novo;
  }
  
  return novo;
}

// remove da lista

int removeValor(int valor) {
  Lista *atual = head;
  Lista *anterior;

  while(atual != NULL) {
    if(atual->valor == valor) {
      anterior->prox = atual->prox;
      free(atual);
      return 1;
    }
    
    anterior = atual;
    atual = atual->prox;
  }

  return 0;
}

// insere em uma posição na lista

Lista *insere(int valor, int pos) {
  Lista *novo = NULL;
  Lista *atual = head;
  int position = pos;

  while(position != 0) {
    atual = atual->prox;
    position--;
  }

  if(atual != NULL) {
    novo = malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = atual->prox;
    atual->prox = novo;
    return novo;
  }

  printf("Posicao fora do alcance da lista\n");
  return novo;
}

// mostra a lista

void mostraLista() {
  Lista *item = head;
  
  if(item == NULL) {
    printf("<lista vazia>");
  } else {
    while(item != NULL) {
      printf("%d->", item->valor);
      item = item->prox;
    }
    printf("NULL");
  }
  printf("\n");
  return;
}

// mostra o menu
void mostraMenu() {
  printf("\tEscolha qual acao deseja executar: \n");
  printf("\t1 - Adicionar valor na lista \n");
  printf("\t2 - Remover valor da lista \n");
  printf("\t3 - inserir valor na lista em uma posicao \n");
  printf("\t4 - Mostrar a lista \n");
  printf("\t5 - Sair \n");
  return;
}

int main() {
  int opcao = -1;
  int arg1; int arg2;
  while(opcao != 5) {
    mostraMenu();
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
      printf("Informe o valor que deseja adicionar: ");
      scanf("%d", &arg1);
      adiciona(arg1);
      break;
    
    case 2:
      printf("Informe o valor que deseja remover: ");
      scanf("%d", &arg1);
      int sucesso = removeValor(arg1);
      if(!sucesso) {
        printf("%d nao encontrado na lista\n", arg1);
      }
      break;

    case 3:
      printf("Informe o valor que deseja inserir: ");
      scanf("%d", &arg1);
      printf("Informe a posicao: ");
      scanf("%d", &arg2);
      Lista *l = insere(arg1, arg2);
      break;

    case 4:
      mostraLista();
      break;

    case 5:
      break;
    }

  }
  
  return 0;
}