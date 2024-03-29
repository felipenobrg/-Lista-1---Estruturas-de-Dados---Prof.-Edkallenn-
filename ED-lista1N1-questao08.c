/*
** Função : Recebe um número inteiro positivo n como entrada e retorna verdadeiro se n for um número de Armstrong, e falso caso contrário.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int eh_numero_armstrong(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  for (int i = 1; i <= 1000; i++) {
    if (eh_numero_armstrong(i)) {
      printf("%d ", i);
    }
  }

  return 0;
}

int eh_numero_armstrong(int n) {
  if (n > 1 && n < 10) {
    return 0;
  }

  int soma = 0;
  int temp = n;
  int digitos = 0;
  while (temp != 0) {
    digitos++;
    temp /= 10;
  }
  temp = n;
  while (temp != 0) {
    soma += pow(temp % 10, digitos);
    temp /= 10;
  }
  return soma == n;
}