/*
** Função : Recebe um número inteiro max como entrada e retorna um array contendo todos os números da série de Fibonacci que sejam menores ou iguais a max.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* fibonacci_max(int max);

int main() {
  setlocale(LC_ALL, "Portugese");

  int max;
  printf("Digite um número inteiro: ");
  scanf("%d", &max);

  int* fib = fibonacci_max(max);

  printf("Série de Fibonacci de 0 até %d: ", max);
  for (int i = 0; fib[i] <= max; i++) {
    printf("%d ", fib[i]);
    if (fib[i] == -1) {
      break;
    }
  }

  return 0;
}

int* fibonacci_max(int max) {
  int contador = 0;
  int* fib = (int*) malloc(sizeof(int) * max);
  fib[0] = 0;
  fib[1] = 1;

  for (int i = 2; fib[i - 1] <= max; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    contador++;
  }
  
  contador++;
  fib[contador] = -1;
  fib = (int*) realloc(fib, sizeof(int) * (contador));

  return fib;
}