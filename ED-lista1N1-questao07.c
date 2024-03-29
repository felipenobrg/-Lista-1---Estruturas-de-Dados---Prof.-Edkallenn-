/*
** Função : Recebe um número inteiro positivo n como entrada e retorna verdadeiro se n for um número feliz, e falso caso contrário.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <locale.h>

int eh_numero_feliz(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  int n;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);

  if (eh_numero_feliz(n)) {
    printf("O número %d é feliz.\n", n);
  } else {
    printf("O número %d não é feliz.\n", n);
  }

  return 0;
}

int eh_numero_feliz(int n) {
  int soma = 0;
  while (n != 1 && n != 4) {
    while (n != 0) {
      soma += (n % 10) * (n % 10);
      n /= 10;
    }
    n = soma;
    soma = 0;
  }
  return n == 1;
}