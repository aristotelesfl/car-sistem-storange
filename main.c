#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char marca[15], cor[10], placa[8];
  int ano, ano_aquisicao;
  float preco;
} tCarro;

int menu() {
  int opcao;
  printf("--- MENU PRINCIPAL ---\n");
  printf("1 - Cadastrar carro\n2 - Localizar carro\n3 - Remover carro\n4 - Relatorios\n0 - Sair\n");
  setbuf(stdin, NULL);
  scanf("%d", &opcao);
  return opcao;
}

void cadastra_carro(tCarro vc[], int qtdCarros) {
  int i = qtdCarros - 1;
  int j;

  printf("-- Carro %d --\n", qtdCarros);
  printf("Marca: ");
  scanf("%s", vc[i].marca);

  printf("ano: ");
  scanf("%d", &vc[i].ano);

  printf("ano de aquisicao: ");
  scanf("%d", &vc[i].ano_aquisicao);

  
  printf("Cor: ");
  scanf("%s", vc[i].cor);

  printf("preco: ");
  scanf("%f", &vc[i].preco);

  printf("placa: ");
  scanf("%s", vc[i].placa);

  for (j = 0; j < i; j++) {
    while (strcmp(vc[i].placa, vc[j].placa) == 0) {
      printf("Negado! Placa ja cadastrada!\nDigite novamente\n");
      printf("placa: ");
      fflush(stdin);
      fgets(vc[i].placa, 9, stdin);
    }
  }
}

void localizar_carro(tCarro vc[], int j) {
  int i, e = 0;
  char placa[8];
  printf("Digite uma placa: ");
  fflush(stdin);
  scanf("%s", placa);
  for (i = 0; i < j; i++) {
    if (strcmp(vc[i].placa, placa) == 0) {
      printf("-- Carro %d --", i + 1);
      printf("\nMarca: %s", vc[i].marca);
      printf("\nAno: %d", vc[i].ano);
      printf("\nAno de aquisicao: %d", vc[i].ano_aquisicao);
      printf("\nCor: %s", vc[i].cor);
      printf("\nPreco: %.2f", vc[i].preco);
      printf("\nPlaca: %s", vc[i].placa);
      printf("\n");
      e = 1;
    }
  }
  if (e == 0) printf("Carro nao encontrado.\n");
}

int apaga_carro(tCarro vc[], int j) {
  int i, e = 0;
  char placa[8];
  printf("Digite a placa do carro a ser removido: ");
  scanf("%s", placa);
  for (i = 0; i <= j; i++) {
    if (strcmp(vc[i].placa, placa) == 0) {
      printf("Excluido com sucesso!\n");
      vc[i] = vc[i + 1];
      e = 1;
      j--;
    }
  }
  if (e == 0) printf("Carro nao encontrado.\n");
  return j;
}

void relatorios(tCarro vc[], int qtdCarros) {
  int opcao=1, i, ANO;
  float valor;
  char Marca[15];
  while (opcao != 0) {
    printf("--- MENU RELATORIOS ---\n");
    printf("1 - Listar carros\n"
	"2 - Listar carros por limite de preco\n"
	"3 - Listar carros por limite de ano\n"
	"4 - Listar carros de uma marca\n"
	"5 - Listar carros de marca e ano\n"
	"0 - Sair\n");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        for (i = 0; i < qtdCarros; i++) {
          printf("-- Carro %d --", i + 1);
          printf("\nMarca: %s", vc[i].marca);
          printf("\nAno: %d", vc[i].ano);
          printf("\nAno de aquisicao: %d", vc[i].ano_aquisicao);
          printf("\nCor: %s", vc[i].cor);
          printf("\nPreco: %.2f", vc[i].preco);
          printf("\nPlaca: %s", vc[i].placa);
          printf("\n");
        }
        break;
      case 2:
        printf("\nDigite um preco: R$");
        scanf("%f", &valor);
        for(i=0; i<qtdCarros; i++){
   	      if (vc[i].preco >= valor) {
          printf("-- Carro %d --", i + 1);
          printf("\nMarca: %s", vc[i].marca);
          printf("\nAno: %d", vc[i].ano);
          printf("\nAno de aquisicao: %d", vc[i].ano_aquisicao);
          printf("\nCor: %s", vc[i].cor);
          printf("\nPreco: %.2f", vc[i].preco);
          printf("\nPlaca: %s", vc[i].placa);
          printf("\n");
			}
		}
          break;
        case 3:
          printf("\nDigite um ano: ");
          scanf("%d", &ANO);
          for (i = 0; i < qtdCarros; i++) {
            if (vc[i].ano >= ANO) {
              printf("-- Carro %d --", i + 1);
              printf("\nMarca: %s", vc[i].marca);
              printf("\nAno: %d", vc[i].ano);
              printf("\nAno de aquisicao: %d", vc[i].ano_aquisicao);
              printf("\nCor: %s", vc[i].cor);
              printf("\nPreco: %.2f", vc[i].preco);
              printf("\nPlaca: %s", vc[i].placa);
              printf("\n");
            }
          }
          break;
        case 4:
          printf("\nDigite uma marca: ");
          scanf("%s", &Marca);
          for (i = 0; i < qtdCarros; i++) {
            if (strcmp(vc[i].marca, Marca)==0) {
              printf("-- Carro %d --", i + 1);
              printf("\nMarca: %s", vc[i].marca);
              printf("\nAno: %d", vc[i].ano);
              printf("\nAno de aquisicao: %d", vc[i].ano_aquisicao);
              printf("\nCor: %s", vc[i].cor);
              printf("\nPreco: %.2f", vc[i].preco);
              printf("\nPlaca: %s", vc[i].placa);
              printf("\n");
            }
          }
          break;
        case 5:
          printf("\nDigite uma Marca: ");
          scanf("%s", &Marca);
          printf("\nDigite um ano: ");
          scanf("%d", &ANO);
          for (i = 0; i < qtdCarros - 1; i++) {
            if (strcmp(vc[i].marca, Marca) == 0 && vc[i].ano >= ANO) {
              printf("-- Carro %d --", i + 1);
              printf("\nMarca: %s", vc[i].marca);
              printf("\nAno: %d", vc[i].ano);
              printf("\nAno de aquisicao: %d", vc[i].ano_aquisicao);
              printf("\nCor: %s", vc[i].cor);
              printf("\nPreco: %.2f", vc[i].preco);
              printf("\nPlaca: %s", vc[i].placa);
              printf("\n");
            }
          }
          break;
        case 0:
          break;
        default:
          printf("Entrada Invalida\n");
          break;
        }
    }
  }


int main() {
  int comando = 1;
  tCarro *vetCarro;
  int qtdCarros = 0;

  vetCarro = (tCarro*)(calloc(qtdCarros, sizeof(tCarro)));

  while (comando != 0) {
    comando = menu();

    switch (comando) {
      case 1:
        qtdCarros++;
        vetCarro = realloc(vetCarro, qtdCarros * sizeof(tCarro));
        cadastra_carro(vetCarro, qtdCarros);
        break;
      case 2:
        localizar_carro(vetCarro, qtdCarros);
        break;
      case 3:
        qtdCarros = apaga_carro(vetCarro, qtdCarros);
        break;
      case 4:
        relatorios(vetCarro, qtdCarros);
        break;
      case 0:
        break;
      default:
        printf("Entrada Invalida\n");
        break;
    }
  }

  free(vetCarro);
  return 0;
}
