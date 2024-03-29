/*
** Função : Recebe um array de inteiros e seu tamanho como entrada, e verifica se ele é uma permutação circular de outro array de inteiros do mesmo Trabalho 1 - Entrada/Saída, Controle de Fluxo, Funções e Arrays 11 tamanho.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int permutacao_circular(int* arr1, int* arr2, int tam);
void constroi_array(int* arr, int tam);

int main() {
  setlocale(LC_ALL, "Portugese");

  int tam;
  printf("Digite o tamanho dos arrays: ");
  scanf("%d", &tam);

  int* arr1 = (int*) malloc(tam * sizeof(int));
  int* arr2 = (int*) malloc(tam * sizeof(int));

  printf("Digite os elementos do primeiro array: \n");
  constroi_array(arr1, tam);

  printf("\n");

  printf("Digite os elementos do segundo array: \n");
  constroi_array(arr2, tam);

  printf("\n");
  if (permutacao_circular(arr1, arr2, tam)) {
    printf("Os arrays são permutações circulares.\n");
  } else {
    printf("Os arrays não são permutações circulares.\n");
  }

  return 0;
}

void constroi_array(int* arr, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("Elemento %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
}

int permutacao_circular(int* arr1, int* arr2, int tam) {
  int i, j, k;
  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      if (arr1[i] == arr2[j]) {
        for (k = 0; k < tam; k++) {
          if (arr1[(i + k) % tam] != arr2[(j + k) % tam]) {
            break;
          }
        }
        if (k == tam) {
          return 1;
        }
      }
    }
  }
  return 0;
}