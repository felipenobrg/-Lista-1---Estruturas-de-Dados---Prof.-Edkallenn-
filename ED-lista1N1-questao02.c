/*
** Função : Recebe parametro n e retorna o resultado do fatorial duplo
** Autor : Felipe Nóbrega de Almeida
** Data : 27/03/2024
** Observações:
*/

#include <stdio.h>
#include <locale.h>

long long fatorial_duplo(int n);
long long fatorial_simples(int n);

int main() {
  setlocale(LC_ALL, "Portugese");

  int n = 7;
  int tamanho = 18;
  int r_simples[tamanho];
  int r_duplo[tamanho];

  int j = 2;
  for (int i = 0; i < tamanho; i++) {
    r_simples[i] = fatorial_simples(j);
    r_duplo[i] = fatorial_duplo(j);
    j++;
  }

  printf("------------ Tabela de fatorial ------------\n");
  printf(" n | fatorial simples | fatorial duplo | diferença\n");
  for (int i = 0; i <= tamanho; i++) {
    printf(" %d | %lld | %lld | %lld\n", i + 2, r_simples[i], r_duplo[i], r_simples[i] - r_duplo[i]);
  }
  printf("------------------------------------------------------\n");

  return 0;
}

long long fatorial_duplo(int n) {
  long long fatorial = n;
  for (int i = 2; i < n; i+=2) {
    fatorial *= (n - i);
  }
  return fatorial;
}

long long fatorial_simples(int n) {
  long long fatorial = n;
  for (int i = 1; i < n; i++) {
    fatorial *= (n - i);
  }
  return fatorial;
}