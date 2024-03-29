/*
** Função : Recebe um número inteiro positivo n como entrada e retorna verdadeiro se n for um número perfeito, e falso caso contrário.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <locale.h>

int eh_numero_perfeito(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  for (int i = 1; i <= 10000; i++) {
    if (eh_numero_perfeito(i)) {
      printf("%d ", i);
    }
  }

  return 0;
}

int eh_numero_perfeito(int n) {
  if (n < 1) {
    return 0;
  }

  int soma = 0;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      soma += i;
    }
  }
  return soma == n;
}