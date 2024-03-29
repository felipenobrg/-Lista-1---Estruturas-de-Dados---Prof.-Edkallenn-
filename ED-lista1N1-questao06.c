/*
** Função : Verifica se um dado número inteiro "n" é um número de Carmichael ou não. Em seguida exibe todos os números de Carmichael de 2 até o número n digitado pelo usuário.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int mdc(int a, int b);
int* coprimos(int n, int* contador);
int eh_congruente(int a, int b, int n);
int verificar_numero_carmichael(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  int n;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  for (int i = 2; i <= n; i++) {
    if (verificar_numero_carmichael(i)) {
      printf("O número %d é um número de Carmichael.\n", i);
    }
  }
  return 0;
}

int verificar_numero_carmichael(int n) {
  int tamanho_lista;
  int* lista_coprimos = coprimos(n, &tamanho_lista);
  for (int i = 0; i < tamanho_lista; i++) {
    if (!eh_congruente(pow(lista_coprimos[i], n), lista_coprimos[i], n)) {
      return 0;
    }
  }
  return 1;
}

int* coprimos(int n, int* contador) {
  *contador = 0;
  for (int i = 1; i <= n; i++) {
    if (mdc(n, i) == 1) {
      if (i != 1) {
        continue;
      }
      (*contador)++;
    }
  }
  
  int* coprimos = (int*)malloc(sizeof(int) * (*contador));
  if (coprimos == NULL) {
    printf("Erro ao alocar memória.\n");
    exit(1);
  }

  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (mdc(n, i) == 1) {
      if (i == 1) {
        continue;
      }
      coprimos[j] = i;
      j++;
    }
  }
  return coprimos;
}

int mdc(int a, int b) {
  int resto;
  while (b != 0) {
    resto = a % b;
    a = b;
    b = resto;
  }
  return a;
}

int eh_congruente(int a, int b, int n) {
  if ((a % n) == (b % n)) {
    return 1;
  }
  return 0;
}