/*
** Função : Recebe um número inteiro positivo n como entrada e retorna a soma dos fatoriais inversos dos números de 1 a n.
** Autor : Felipe Nóbrega de Almeida
** Data : 29/03/2024
** Observações:
*/

#include <stdio.h>
#include <locale.h>

double fatorial(int n);
double soma_fatoriais_inversos(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  int n;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);
  printf("A soma dos fatoriais inversos de 1 a %d é %.6lf\n", n, soma_fatoriais_inversos(n));

  return 0;
}

double soma_fatoriais_inversos(int n) {
  double soma = 0;
  for (int i = 1; i <= n; i++) {
    soma += 1.0/fatorial(i);
  }
  return soma;
}

double fatorial(int n) {
  int fat = 1;
  for (int i = 1; i <= n; i++) {
    fat *= i;
  }
  return fat;
}